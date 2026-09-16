// Problem: Planets and Kingdoms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1683
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int N = 1e5 + 1;

// adj_t is the transpose of adj
std::vector<int> adj[N], adj_t[N];
std::vector<int> order;
std::vector<int> vis(N), id(N);

// calculates the order in which nodes are processed
void dfs1(int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) { dfs1(u); }
	}
	order.push_back(v);
}

/*
 * traverse one SCC at a time and
 * assign component ID to all nodes in one SCC
 */
void dfs2(int x, int comp) {
	vis[x] = true;

	for (int u : adj_t[x]) {
		if (!vis[u]) { dfs2(u, comp); }
	}
	id[x] = comp;
}

void solve() {
    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj_t[v].pb(u);
    }
    
    vis.assign(N, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }
    vis.assign(N, 0);
    
    int comps = 0;
    reverse(order.begin(), order.end());
    for (auto& v : order) {
        if (!vis[v]) dfs2(v, ++comps);
    }
    
    cout << comps << ln;
    for (int i = 1; i <= n; i++) {
        cout << id[i] << " ";
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
