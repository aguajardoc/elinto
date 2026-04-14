// Problem: Query on a tree again!
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/QTREE3/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("input.in", "r", stdin); \
    freopen("output.out", "w", stdout)
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << ": " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

#define ll long long
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

// segtree: point xor updates, range sum queries

struct Segtree {
	vector<int> st;
	int TREE_SIZE = 1;
	
	Segtree() {}
	
	Segtree(int n) {
		while (TREE_SIZE < n) TREE_SIZE <<= 1;
		st.assign(2*TREE_SIZE, 0);
	}
	
	void update(int i) {
		i += TREE_SIZE;
		st[i] ^= 1;
		i >>= 1;
		while(i) {
			st[i] = st[2*i] + st[2*i+1];
			i >>= 1;
		}
	}
	
	int query(int l, int r) {
		l += TREE_SIZE;
		r += TREE_SIZE;
		int res = 0;
		
		while(l <= r) {
			if(l&1) res += st[l++];
			if(!(r&1)) res += st[r--];
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, dist, root, par, antipos;
	Segtree st;
	
	HLD(vector<vector<int>> _AL, int _r) {
		r = _r;
		n = _AL.size();
		AL = _AL;
		
		pos.assign(n, 0);
		size.assign(n, 1);
		dist.assign(n, 0);
		root.assign(n, 0);
		par.assign(n, -1);
		antipos.assign(n, 0);
		st = Segtree(n);
		
		dfs_sz(r);
		dfs_hld(r);
	}
	
	void dfs_sz(int u) {
		if (par[u] != -1) {
			AL[u].erase(find(AL[u].begin(), AL[u].end(), par[u]));
		}
		
		for (auto& v : AL[u]) {
			dist[v] = dist[u] + 1;
			par[v] = u;
			dfs_sz(v);
			size[u] += size[v];
			
			if (size[v] > size[AL[u][0]]) {
				swap(v, AL[u][0]);
			}
		}
	}
	
	void dfs_hld(int u) {
		pos[u] = time;
		antipos[time] = u;
		time++;
		for (auto& v : AL[u]) {
			root[v] = (v == AL[u][0] ? root[u]:v);
			dfs_hld(v);
		}
	}
	
	int min_in_segment(int L, int R) {
		int found = INF;
		int init = L;
		while (L <= R) {
			int m = (L + R) / 2;
			
			int fm = st.query(init, m);
			
			if (fm) {
				found = min(found, m);
				R = m - 1;
			}
			else {
				L = m + 1;
			}
		}
		
		return found;
	}
	
	int query(int u, int v) {
		int res = -2;
		
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) {
				swap(u, v);
			}
			
			// BS
			int L = pos[root[u]];
			int R = pos[u];
			int f = min_in_segment(L, R);
			if (f != INF) res = antipos[f];
			
			u = par[root[u]];
		}
		
		if (dist[u] > dist[v]) swap(u, v);
		
		// BS
		int L = pos[u];
		int R = pos[v];
		int f = min_in_segment(L, R);
		if (f != INF) res = antipos[f];
		
		return res;
	}
	
	void update_node(int i) {
		st.update(pos[i]);
	}
};

void solve() {
    // When doing a query from 1 to v,
    // the path really ends up going from v to 1
    // so the answer is the last node we find in 
    // any segment of queries
    // for each segment, binary search and query from
    // pos[root[u]] to x, (x in range pos[root[u]], pos[u])
    // if a black node is found, set res as the path's lowest
    // if not, do nothing
    // repeat for all segments in path from v to 1
    
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> AL(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    HLD h(AL, 0);
    
    while(q--) {
    	int type, x;
    	cin >> type >> x;
    	x--;
    	if (!type) {
    		h.update_node(x);
    	}
    	else {
    		cout << h.query(0, x) + 1 << ln;
    	}
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
