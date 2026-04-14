// Problem: L. Los Ratones III
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 3ra Fecha
// URL: https://codeforces.com/gym/106063/problem/L
// Memory Limit: 256 MB
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

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree() {}
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy.assign(4*n, 1);
	}
	
	void push(int p, int l, int r) {
		if (lazy[p] == 1) return;
		
		st[2*p] *= lazy[p];
		st[2*p] %= MOD;
		st[2*p+1] *= lazy[p];
		st[2*p+1] %= MOD;
		
		lazy[2*p] *= lazy[p];
		lazy[2*p] %= MOD;
		lazy[2*p+1] *= lazy[p];
		lazy[2*p+1] %= MOD;
		lazy[p] = 1;
	}
	
	void update(int p, int l, int r, int i, int j, int v, int type) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			if (!type) {
				st[p] += v;
				st[p] %= MOD;
				return;
			}
			
			st[p] *= v;
			st[p] %= MOD;
			lazy[p] *= v;
			lazy[p] %= MOD;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v, type);
		update(2*p+1, m+1, r, i, j, v, type);
		
		st[p] = st[2*p] + st[2*p+1];
		st[p] %= MOD;
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		int res = query(2*p, l, m, i, j) + query(2*p + 1, m + 1, r, i, j);
		res %= MOD;
		return res;
	}
	
	void update(int i, int j, int v, int type) {
		update(1, 0, n - 1, i, j, v, type);
	}
	
	int query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, dist, par, root;
	Segtree st;
	
	HLD(vector<vector<int>> _AL, int _r) {
		r = _r;
		AL = _AL;
		n = AL.size();
		
		pos.assign(n, 0);
		size.assign(n, 1);
		dist.assign(n, 0);
		par.assign(n, -1);
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
			root[v] = (v == AL[u][0] ? root[u]:v);
			dfs_hld(v);
		}
	}
	
	int query(int u, int v, int x) {
		int res = 0;
		
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) {
				swap(u, v);
			}
			
			st.update(pos[root[u]], pos[u], x, 1);
			res += st.query(pos[root[u]], pos[u]);
			res %= MOD;
			
			u = par[root[u]];
		}
		
		if (dist[u] > dist[v]) {
			swap(u, v);
		}
		
		st.update(pos[u], pos[v], x, 1);
		res += st.query(pos[u], pos[v]);
		res %= MOD;
		
		return res;
	}
	
	void update_node(int i, int v, int type) {
		st.update(pos[i], pos[i], v, type);
	}
	
};

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>>AL(2*n);
	vector<int> a(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		u *= 2;
		v *= 2;
		AL[u].pb(2*i+1);
		AL[2*i+1].pb(u);
		AL[2*i+1].pb(v);
		AL[v].pb(2*i+1);
		a[i] = c;
	}
	
	HLD h(AL, 0);
	
	for (int i = 0; i < n-1; i++) {
		h.update_node(2*i+1, a[i], 0);
	}
	
	while(q--) {
		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
		u *= 2;
		v *= 2;
		
		cout << h.query(u, v, x) << ln;
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
