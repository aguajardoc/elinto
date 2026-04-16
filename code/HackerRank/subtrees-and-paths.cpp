// Problem: Subtrees And Paths
// Contest: HackerRank - Data Structures - Advanced
// URL: https://www.hackerrank.com/challenges/subtrees-and-paths/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree() {}
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy.assign(4*n, 0);
	}
	
	void push(int p, int l, int r) {
		if (!lazy[p]) return;
		
		st[2*p] += lazy[p];
		st[2*p+1] += lazy[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p] += v;
			lazy[p] += v;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		update(2*p, l, m, i, j, v);
		update(2*p+1, m + 1, r, i, j ,v);
		
		st[p] = max(st[2*p], st[2*p+1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return -INF;
		if (l >= i and r <= j) {
			return st[p];
		}
		push(p, l, r);
		int m = (l + r) / 2;
		
		int res = max(query(2*p, l, m, i, j), query(2*p+1, m+1,r, i, j));
		
		return res;
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
	
	int query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, par, root, dist;
	Segtree st;
	
	HLD(vector<vector<int>> _AL, int _r) {
		r = _r;
		AL = _AL;
		n = AL.size();
		
		pos.assign(n, 0);
		size.assign(n, 1);
		par.assign(n, -1);
		dist.assign(n, 0);
		root.assign(n, 0);
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
		pos[u] = time++;
		for (auto& v : AL[u]) {
			root[v] = (v == AL[u][0] ? root[u] : v);
			dfs_hld(v);
		}
	}
	
	int query_path(int u, int v) {
		int res = -INF;
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) {
				swap(u, v);
			}
			
			res = max(res, st.query(pos[root[u]], pos[u]));
			
			u = par[root[u]];
		}
		
		if (dist[u] > dist[v]) {
			swap(u, v);
		}
		
		res = max(res, st.query(pos[u], pos[v]));
		return res;
	}
	
	void update_subtree(int u, int val) {
		st.update(pos[u], pos[u] + size[u] - 1, val);
	}
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> AL(n);
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    HLD h(AL, 0);
    
    int q;
    cin >> q;
    while(q--) {
    	string t;
    	cin >> t;
    	if (t=="add") {
    		int u, v;
    		cin >> u >> v;
    		u--;
    		h.update_subtree(u, v);
    	}
    	else {
    		int u, v;
    		cin >> u >> v;
    		u--, v--;
    		cout << h.query_path(u, v) << ln;
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
