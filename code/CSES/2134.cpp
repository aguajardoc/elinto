// Problem: Path Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2134
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Segtree {
	vector<int> st;
	int TREE_SIZE;
	int n;
	
	Segtree() {}
	
	Segtree (int _n) {
		n = _n;
		TREE_SIZE = 1;
		while (TREE_SIZE < n) TREE_SIZE <<= 1;
		
		st.assign(2*TREE_SIZE, 0);
	}
	
	void update(int i, int v) {
		i += TREE_SIZE;
		st[i] = v;
		i >>= 1;
		while (i) {
			st[i] = max(st[2*i], st[2*i+1]);
			i >>= 1;
		}
	}
	
	int query(int i, int j) {
		i += TREE_SIZE;
		j += TREE_SIZE;
		int res = 0;
		
		while(i <= j) {
			if (i&1) res = max(res, st[i++]);
			if (!(j&1)) res = max(res, st[j--]);
			
			i >>= 1;
			j >>= 1;
		}
		return res;
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> par, size, dist, root, pos;
	Segtree st;
	
	HLD (vector<vector<int>> _AL, int _R) {
		n = _AL.size();
		r = _R;
		AL = _AL;
		par.assign(n, -1);
		size.assign(n, 1);
		dist.assign(n, 0);
		root.assign(n, 0);
		pos.assign(n, 0);
		st = Segtree(n);
		
		root[r] = r;
		dfs_sz(r);
		dfs_hld(r);
	}
	
	void dfs_sz(int u) {
		if (par[u] != -1) {
			AL[u].erase(find(AL[u].begin(), AL[u].end(), par[u]));
		}
		
		for (auto& v : AL[u]) {
			par[v] = u;
			dist[v] = dist[u] + 1;
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
	
	int query(int u, int v) {
		int res = 0;
		
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) {
				swap(u, v);
			}
			
			res = max(res, st.query(pos[root[u]], pos[u]));
			
			u = par[root[u]];
		}
		
		if (dist[u] > dist[v]) swap(u, v);
		
		res = max(res, st.query(pos[u], pos[v]));
		return res;
	}
	
	
	void update_node(int u, int val) {
		st.update(pos[u], val);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> AL(n);
    vector<int> vals(n);
    
    for (auto& i : vals) cin >> i;
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    HLD h(AL, 0);
    
    for (int i = 0; i < n; i++) {
    	h.update_node(i, vals[i]);
    }
    
    while (q--) {
    	int type;
    	cin >> type;
    	
    	if (type == 1) {
    		int s, x;
    		cin >> s >> x;
    		s--;
    		h.update_node(s, x);
    	}
    	else {
    		int a, b;
    		cin >> a >> b;
    		a--, b--;
    		cout << h.query(a, b) << " ";
    	}
    }
    cout << ln;
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
