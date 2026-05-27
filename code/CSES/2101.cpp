// Problem: New Roads Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2101/
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
#define int ll
#define ld long double
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int inf = 1e9;
typedef vector<int> vi;

vector<vector<int>> AL[200010];

struct Segtree {
	vector<int> st;
	int TREE_SIZE = 1;
	
	Segtree() {
		
	}
	
	Segtree(int _n) {
		while (TREE_SIZE <= _n) TREE_SIZE <<= 1;
		st.assign(2 * TREE_SIZE, 0);
	}
	
	void update(int i, int x) {
		i += TREE_SIZE;
		st[i] = x;
		i >>= 1;
		
		while(i) {
			st[i] = max(st[2*i], st[2*i+1]);
			i>>= 1;
		}
	}
	
	int query(int l, int r) {
		l += TREE_SIZE;
		r += TREE_SIZE;
		int res = 0;
		
		while(l <= r) {
			if (l&1) res = max(res, st[l++]);
			if (!(r&1)) res = max(res, st[r--]);
			
			l >>= 1;
			r >>= 1;
		}
		
		return res;
	}
	
	void update(int i, int j, int v) {
		update(i, v);
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
		return st.update(pos[i], pos[i], v);
	}
	
	void update_edge(int u, int v, int w) {
		if (dist[u] < dist[v]) swap(u, v);
		return st.update(pos[u], pos[u], w);
	}

    void update_subtree(int i, int v) {
		return st.update(pos[i], pos[i] + size[i] - 1, v);
	}
	
	void update_path(int u, int v, int w) {
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) swap(u, v);
			st.update(pos[root[u]], pos[u], w);	
			u = par[root[u]];
		}
		if (dist[u] > dist[v]) swap(u, v);
		st.update(pos[u], pos[v], w);
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
		if (pos[u] + 1 <= pos[v])
			res = max(res, st.query(pos[u] + 1, pos[v]));
		return res;
	}
};
// Usage: UnionFind(n). unionSet() merges sets
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	UnionFind dsu(n), dsuF(n), dsuS(n);
	vector<pair<int, int>> joins;
	
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		dsu.unionSet(u, v);
		
		joins.pb({u, v});
	}
	
	vector<int> node_map(n, -1);
	vector<int> map_per(n, 0);
	
	for (int i = 0; i < n; i++) {
		if (dsu.findSet(i) != i) continue;
		AL[i].resize(dsu.sizeOfSet(i));
	}
	
	for (int i = 0; i < m; i++) {
		int u = joins[i].first;
		int v = joins[i].second;
		
		if (dsuF.isSameSet(u, v)) continue;
		
		int s = dsu.findSet(u);
		dsuF.unionSet(u, v);
		
		if (node_map[u] == -1) {
			node_map[u] = map_per[s]++;
		}
		if (node_map[v] == -1) {
			node_map[v] = map_per[s]++;
		}
		
		AL[s][node_map[u]].pb(node_map[v]);
		AL[s][node_map[v]].pb(node_map[u]);
	}
	
	vector<HLD> hlds;
	
	for (int i = 0; i < n; i++) {
		if (AL[i].empty()) {
			AL[i] = {{}};
		}
		hlds.pb(HLD(AL[i], 0));
	}
	
	for (int i = 0; i < m; i++) {
		int u = joins[i].first;
		int v = joins[i].second;
		
		if (dsuS.isSameSet(u, v)) continue;
		
		int s = dsu.findSet(u);
		dsuS.unionSet(u, v);
		
		hlds[s].update_edge(node_map[u], node_map[v], i+1);
	}
	
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		if (u == v) {
			cout << 0 << ln;
			continue;
		}
		if (!dsu.isSameSet(u, v)) {
			cout << -1 << ln;
			continue;
		}
		int s = dsu.findSet(u);
		
		cout << hlds[s].query_path(node_map[u], node_map[v]) << ln;
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
