// Problem: M. A and B and Lecture Rooms
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/M
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

// Usage: pass in a vector of parents to initialize
// Everything is 0-indexed
class Tree {
  // From USACO Guide
  private:
	const int log2dist;
	vector<int> par;
	vector<vector<int>> pow2ends;
  
  public:
	Tree(const vector<int> &parents)
	    : log2dist(std::ceil(std::log2(parents.size() + 1))), par(parents),
	      pow2ends(parents.size(), vector<int>(log2dist + 1)) {
		
		// pow2ends[n][k] contains the 2^kth parent of node n
		// if there is no 2^kth parent, the value is -1
		for (int n = 0; n < par.size(); n++) { pow2ends[n][0] = par[n]; }
		for (int p = 1; p <= log2dist; p++) {
			for (int n = 0; n < par.size(); n++) {
				int halfway = pow2ends[n][p - 1];
				if (halfway == -1) {
					pow2ends[n][p] = -1;
				} else {
					pow2ends[n][p] = pow2ends[halfway][p - 1];
				}
			}
		}
	}

	/** @return the kth parent of node n */
	int kth_parent(int n, int k) {
		int at = n;
		// break down k into powers of 2 by looping through its bits
		for (int pow = 0; pow <= log2dist; pow++) {
			if ((k & (1 << pow)) != 0) {
				at = pow2ends[at][pow];
				if (at == -1) {
					break;  // stop when we're past the root
				}
			}
		}
		return at;
	}
};

// Usage: preprocess(0) after adj init
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, dist, sz, par;
vector<vector<int>> up;

int dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
        	dist[u] = dist[v] + 1;
            sz[v] += dfs(u, v);
            par[u] = v;
        }
    }

    tout[v] = ++timer;
    sz[v]++;
    return sz[v];
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    dist.resize(n);
    par.assign(n, -1);
    sz.assign(n, 0);
    dist[root] = 0;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int get_dist(int u, int v) {
	return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

void solve() {
	cin >> n;
	vector<vector<int>> AL(n);
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		AL[u].pb(v);
		AL[v].pb(u);
	}
	
	// LCA
	swap(AL, adj);
	preprocess(0);
	
	// transform to parents vector
	Tree BJ(par);
	
	// process queries
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		if (dist[a] < dist[b]) swap(a, b);
		
		if (a == b) {
			cout << n << ln;
			continue;
		}
		
		int k = get_dist(a, b);
		if (k % 2) {
			cout << 0 << ln;
			continue;
		}
		
		if (get_dist(a, lca(a, b)) == get_dist(b, lca(a, b)) and get_dist(a, lca(a, b)) == k/2) {
			cout << n - sz[BJ.kth_parent(a, k/2 - 1)] - sz[BJ.kth_parent(b, k/2 - 1)] << ln;
			continue;
		}

		cout << sz[BJ.kth_parent(a, k/2)] - sz[BJ.kth_parent(a, k/2 - 1)] << ln;
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
