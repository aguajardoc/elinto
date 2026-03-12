// Problem: B. Diverging Directions
// Contest: Codeforces - IndiaHacks 2nd Elimination 2017 (unofficial, unrated mirror, ICPC rules)
// URL: https://codeforces.com/contest/838/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	vector<int> st, lazy, marked;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, INF);
		lazy.assign(4*n, 0);
		marked.assign(4*n, 0);
	}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a);
		build(2*p+1, m + 1, r, a);
		
		st[p] = min(st[2*p], st[2*p+1]);
	}
	
	void push(int p, int l, int r) {
		if (!marked[p]) return;
		
		int m = (l + r) / 2;
		
		st[2*p] += lazy[p];
		st[2*p+1] += lazy[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
		
		marked[2*p] = true;
		marked[2*p+1] = true;
		marked[p] = false;
	}
	
	void update(int p, int l,int r, int i, int j, int v) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			st[p] += v;
			lazy[p] += v;
			marked[p] = true;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p+1,m+1,r,i,j,v);
		
		st[p] = min(st[2*p], st[2*p+1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return INF;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		return min(query(2*p, l, m, i, j), query(2*p+1, m + 1, r, i , j));
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i, j ,v);
	}
	
	int query(int i ,int j) {
		return query(1, 0, n - 1, i , j);
	}
};

struct Edge {
	int u, v, w;
};

vector<int> tin, tout, dist;
vector<vector<pair<int, int>>> AL;
int timer = 0;
vector<Edge> edge_list;

void dfs(int u, int p, int depth) {
	tin[u] = timer++;
	dist[tin[u]] = depth;
	
	for (auto& [v, w] : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u, depth + w);
	}
	
	tout[u] = timer - 1;
} 

void solve() {
	int n, q;
	cin >> n >> q;
	AL.assign(2 * n, vector<pair<int, int>> ());
	tin.assign(2*n, 0);
	tout.assign(2*n, 0);
	dist.assign(2*n, 0);
	
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		
		AL[u].pb({v, w});
		edge_list.pb({u, v, w});
	}
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		v = n + i;
		u--, v--;
		
		AL[u].pb({v, w});
		edge_list.pb({u, v, w});
	}
	
	dfs(0, -1, 0);
	
	// for (int i = 0; i < 2 * n - 2; i++) {
		// edge_list[i].u = tin[edge_list[i].u];
		// edge_list[i].v = tin[edge_list[i].v];
	// }
	
	Segtree st(2*n), st2(2*n);
	
	st.build(1, 0, 2 * n - 1, dist);
	for (int i = 0; i < 2 * n-1; i++) {
		// if leaf, push to st2
		if (tin[i] == tout[i]) {
			st2.update(tin[i], tin[i], -INF);
			st2.update(tin[i], tin[i], dist[tin[i]]);
		}
	}
	
	while (q--) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int i, w;
			cin >> i >> w;
			i--;
			
			int diff = w - edge_list[i].w;
			edge_list[i].w = w;
			
			int v = edge_list[i].v;
			int L = tin[v];
			int R = tout[v];
			
			// dbg(w, diff);
			// dbg(v);
			
			st.update(L, R, diff);
			st2.update(L, R, diff);
			
			// dbg(L, R);
			// dbg(st2.query(L, R));
		}
		else {
			int u, v;
			cin >> u >> v;
			u--, v--;
			
			bool isChild = (tin[v] >= tin[u] and tin[v] <= tout[u]);
			int ans = 0;
			
			
			// dbg(st.query(tin[v], tin[v]));
			// dbg(isChild);
			// dbg(tin[u]);
			// dbg(tin[v]);
			// dbg(st2.query(tin[u], tout[u]));
			// dbg(st.query(tin[u], tin[u]));
			// dbg(st.query(tin[v], tin[v]));
			
			
			if (isChild) {
				ans = st.query(tin[v], tin[v]) - st.query(tin[u], tin[u]);	
			}
			else {
				ans = st2.query(tin[u], tout[u]) - st.query(tin[u], tin[u]) + st.query(tin[v], tin[v]);	
			}
			
			cout << ans << ln;
			// cout << ln;
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
