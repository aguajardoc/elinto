// Problem: Vertex Set Path Composite
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/vertex_set_path_composite
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
const int MOD = 998244353;
const double eps = 1e-9;

struct Node {
	int a, b;
	Node() {
		a = 1;
		b = 0;
	}
	
	Node(int _a, int _b) {
		a = _a;
		b = _b;
	}
	
	Node operator+(Node& oth) {
		Node res;
		res.a = (a * oth.a);
		res.a %= MOD;
		
		res.b = (oth.b + oth.a * b);
		res.b %= MOD;
		
		return res;
	}
};

struct Segtree {
	vector<Node> fwd, bwd;
	int n;
	
	Segtree() {}
	
	Segtree(int _n) {
		n = _n;
		fwd.assign(4*n, Node());
		bwd.assign(4*n, Node());
	}
	
	void update(int p, int l, int r, int i, int j, int a, int b) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			fwd[p] = Node(a, b);
			bwd[p] = Node(a, b);
			return;
		}
		
		int m = (l + r) / 2;
		update(2*p, l, m, i,j, a, b);
		update(2*p+1, m + 1, r, i, j, a, b);
		
		fwd[p] = fwd[2*p] + fwd[2*p+1];
		bwd[p] = bwd[2*p+1] + bwd[2*p];
	}
	
	Node query(int p, int l, int r, int i, int j, int type) {
		if (l > j or r < i) return Node();
		if (l >= i and r <= j) {
			if (!type) return fwd[p];
			return bwd[p];
		}
		
		int m = (l + r) / 2;
		Node res;
		Node L = query(2*p, l, m, i,j, type);
		Node R = query(2*p + 1, m + 1, r, i, j, type);
		
		if (!type) {
			res = L + R;
		}
		else res = R + L;
		
		return res;
	}
	
	void update(int i, int a, int b) {
		update(1, 0, n - 1, i, i, a, b);
	}
	
	Node query(int l, int r, int type) {
		return query(1, 0, n - 1, l, r, type);
	}
};

struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, dist, par, root;
	Segtree st;
	
	HLD (vector<vector<int>> _AL, int _r) {
		AL = _AL;
		r = _r;
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
			root[v] = (v == AL[u][0] ? root[u] : v);
			dfs_hld(v);
		}
	}
	
	int query_path(int u, int v, int x) {
		Node au, av;
		
		while (root[u] != root[v]) {
			if (dist[root[u]] > dist[root[v]]) {
				Node r2 = st.query(pos[root[u]], pos[u], 1);
				au = au + r2;
				u = par[root[u]];
			}
			else {
				Node r2 = st.query(pos[root[v]], pos[v], 0);
				av = r2 + av;
				v = par[root[v]];
			}
		}
		
		if (dist[u] > dist[v]) {
			Node r2 = st.query(pos[v], pos[u], 1);	
			au = au + r2;
		}
		else {
			Node r2 = st.query(pos[u], pos[v], 0);	
			av = r2 + av;
		}
		
		Node res = au + av;
		
		return (res.a * x + res.b) % MOD;
	}
	
	void update_node(int i, int a, int b) {
		st.update(pos[i], a, b);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> AL(n);
    vector<pair<int, int>> func;
    for (int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	func.pb({a, b});
    }
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    HLD h(AL, 0);
    
    for (int i = 0; i < n; i++) {
    	h.update_node(i, func[i].first, func[i].second);
    }
    
    while (q--) {
    	int type;
    	cin >> type;
    	
    	if (!type) {
    		int p, c, d;
    		cin >> p >> c >> d;
    		h.update_node(p, c, d);
    	}
    	else {
    		int u, v, x;
    		cin >> u >> v >> x;
    		cout << h.query_path(u, v, x) << ln;
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
