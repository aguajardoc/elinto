// Problem: Coin Collector
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1686
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

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *component.begin();
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

int dp[100001];

int dfs2(int u, vector<vector<int>>& ALc, vector<int>& coins, vector<int>& root_to_comp) {
    if (dp[u] != -1) return dp[u];
    int res = 0;
    for (auto& v : ALc[u]) {
        res = max(res, dfs2(v, ALc, coins, root_to_comp));
    }
    
    return dp[u] = res + coins[root_to_comp[u]];
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> AL(n), components, ALc;
    vector<int> coins(n);
    fill_n(&dp[0], 100001, -1);
    for (auto& i : coins) cin >> i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        AL[u].pb(v);
    }
    
    strongly_connected_components(AL, components, ALc);
    
    int k = components.size();
    vector<int> coins_comp(k, 0), root_to_comp(n, -1);
    for (int i = 0; i < k; i++) {
        for (auto& j : components[i]) {
            coins_comp[i] += coins[j];
            root_to_comp[j] = i;
        }
    }
    
    vector<int> sources;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto& j : ALc[i]) {
            indeg[j]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!indeg[i]) sources.pb(i);
    }
    
    int ans = 0;
    for (auto& u : sources) {
        ans = max(ans, dfs2(u, ALc, coins_comp, root_to_comp));
    }
    
    cout << ans << ln;
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
