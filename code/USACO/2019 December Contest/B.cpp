// Problem: Problem 2. Milk Visits
// Contest: USACO - USACO 2019 December Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=970
// Memory Limit: 256 MB
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
    freopen("milkvisits.in", "r", stdin); \
    freopen("milkvisits.out", "w", stdout)
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
	int TREE_SIZE = 1;
	
	Segtree() {}
	
	Segtree(int n) {
		while (TREE_SIZE < n) TREE_SIZE <<= 1;
		st.assign(2*TREE_SIZE, 0);
	}
	
	void update(int i, int v) {
		i += TREE_SIZE;
		st[i] = v;
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
			if (l&1) res += st[l++];
			if (!(r&1)) res += st[r--];
			
			l >>= 1;
			r >>= 1;
		}
		
		return res;
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> size, pos, root, dist, par;
	Segtree st;
	
	HLD(vector<vector<int>> _AL, int _r) {
		AL = _AL;
		r = _r;
		n = _AL.size();
		
		size.assign(n, 1);
		par.assign(n, -1);
		root.assign(n, 0);
		dist.assign(n, 0);
		pos.assign(n, 0);
		st = Segtree(n);
		
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
			root[v] = (v == AL[u][0] ? root[u]:v);
			dfs_hld(v);
		}
	}
	
	int query(int u, int v) {
		int res = 0;
		
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) {
				swap(u, v);
			}
			
			res += st.query(pos[root[u]], pos[u]);
			
			u = par[root[u]];
		}
		
		if (dist[u] > dist[v]) swap(u, v);
		
		res += st.query(pos[u], pos[v]);
		return res;
	}
	
	void update(int i, int v) {
		st.update(pos[i], v);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> buckets(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	x--;
    	buckets[x].pb(i);
    }
    
    vector<vector<int>> AL(n);
    
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    vector<vector<vector<int>>> queries(n);
    
    for (int i = 0; i < q; i++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	a--, b--, c--;
    	queries[c].pb({a, b, i});
    }
    
    HLD h(AL, 0);
    
    // For each bucket
    vector<int> ans(q, 0);
    for (int i = 0; i < n; i++) {
    	// Set all in bucket
    	for (auto& j : buckets[i]) {
    		h.update(j, 1);
    	}
    	
    	// Process all queries in bucket
    	for (auto& query : queries[i]) {
    		ans[query[2]] = min(1, h.query(query[0], query[1]));
    	}
    	
    	// Reset all in bucket
    	for (auto& j : buckets[i]) {
    		h.update(j, 0);
    	}
    }
    
    for (auto& i : ans) {
    	cout << i;
    }
    cout << ln;
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
