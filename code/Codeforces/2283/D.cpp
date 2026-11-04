// Problem: D. Black, Gray and White
// Contest: Codeforces - Educational Codeforces Round 196 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2283/problem/D
// Memory Limit: 512 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = INT32_MAX;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Segtree {
	int ts = 1;
	vector<int> st;
	
	Segtree() {}
	
	Segtree(int n) {
		while (ts < n) ts <<= 1;
		st.assign(2 * ts, 0);
	}
	
	void update(int i, int x) {
		i += ts;
		st[i] = x;
		i >>= 1;
		
		while(i) {
			st[i] = st[2*i] + st[2*i + 1];
			i >>= 1;
		}
	}
	
	int query(int l, int r) {
		l += ts;
		r += ts;
		int res = 0;
		
		while (l <= r) {
			if (l&1) res += st[l++];
			if (!(r&1)) res += st[r--];
			
			l >>= 1;
			r >>= 1;
		}
		
		return res;
	}
	
	void update(int i, int j, int x) {
		update(i, x);
	}
};

// pair with segtree
// Example: path/subtree set, path/subtree max
struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, par, root, dist;
	Segtree st;
	
	HLD(vector<vector<int>>& _AL, int _r) {
		r = _r; AL = _AL; n = AL.size();
		
		pos.assign(n, 0);
		size.assign(n, 1);
		par.assign(n, -1);
		root.assign(n, r);
		dist.assign(n, 0);
		st = Segtree(n);
		
		dfs_sz(r); dfs_hld(r);
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
			if (size[v] > size[AL[u][0]]) swap(v, AL[u][0]);
		}
	}
	
	void dfs_hld(int u) {
		pos[u] = time++;
		for (auto& v : AL[u]) {
			root[v] = (v == AL[u][0] ? root[u]:v);
			dfs_hld(v);
		}
	}

    void update_node(int i, int v) {
		st.update(pos[i], pos[i], v);
	}
	
	int query_node(int i) {
		return st.query(pos[i], pos[i]);
	}

    int query_subtree(int i) {
		return st.query(pos[i], pos[i] + size[i] - 1);
	}

    int query_path(int u, int v) {
		int res = -INF;
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) swap(u, v);
			res = max(res, st.query(pos[root[u]], pos[u]));	
			u = par[root[u]];
		}
		if (dist[u] > dist[v]) swap(u, v);
		res = max(res, st.query(pos[u], pos[v]));
		return res;
	}
};

void solve() {
    int n; cin >> n;
    vector<vector<int>> AL(n + 1);
    for (int i = 0; i < n - 1; i++) {
    	int u, v; cin >> u >> v;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    if (n % 2 == 0) {
    	cout << n + 1 << ln;
    	return;
    }
    
    HLD h(AL, 1);
    int ans = n;
    for (int k = n; k <= n + 2; k++) {
    	int target;
    	if (k == n) target = n;
    	else if (k == n + 1) target = n / 2 + n % 2;
    	else target = 1;
    	
    	h.update_node(target, 1);
    	
    	for (int i = 1; i <= n; i++) {
    		int j = k - i;
    		
    		if (i == j or j < 1 or j > n) continue;
    		
    		if (h.query_path(i, j)) ans = k;
    	}
    	
    	
    	h.update_node(target, 0);
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
