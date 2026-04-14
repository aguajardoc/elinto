// Problem: F. Friends Reunion at the Park
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/F
// Memory Limit: 256 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int n, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout, dist;
vector<vector<int>> up;

void dfs(int v, int p, int depth) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; i++) {
		up[v][i] = up[up[v][i-1]][i-1];
	}
	dist[v] = depth;
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v, depth + 1);
		}
	}
	tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { return tin[u] <= tin[v] and tout[u] >= tout[v]; }

int lca(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (int i = l; i >= 0; i--) {
		if (!is_ancestor(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dist.assign(n, 0);
	dfs(root, root, 0);
}

int getDist(int a, int b) {
	return dist[a] + dist[b] - 2*dist[lca(a, b)];
}

void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    preprocess(0);
    
    int q;
    cin >> q;
    while(q--) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	a--, b--, c--;
    	
    	int d = max({
    		getDist(a, b),
    		getDist(a, c),
    		getDist(b, c)
    	});
    	
    	int res = d/2 + d%2;
    	cout << res << ln;
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
