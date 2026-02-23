// Problem: F. Failing Factory
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/F
// Memory Limit: 1024 MB
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

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& output) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited, output);
        }
    }
    output.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ld> probs(n);
    for (int i = 0; i < n; i++) {
        cin >> probs[i];
        probs[i] = 1.0 - probs[i];
    }
    
    vector<vector<int>> adj(n);
    vector<vector<int>> adj_rev(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    
    // Pass 1: Order by exit time
    vector<bool> visited(n, false);
    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adj, visited, order);
    }
    
    // Pass 2: Extract SCCs
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    
    vector<int> scc_root(n, 0);
    vector<vector<int>> components;
    
    for (int v : order) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj_rev, visited, component);
            components.push_back(component);
            
            int root = component.front();
            for (int u : component) {
                scc_root[u] = root;
            }
        }
    }
    
    vector<int> out_degree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (scc_root[u] != scc_root[v]) {
                out_degree[scc_root[u]]++;
            }
        }
    }
    
    ld ans = 0.0;
    for (const auto& comp : components) {
        int root = scc_root[comp.front()];
        
        if (out_degree[root] == 0) {
            ld current_prob = 1.0;
            for (int u : comp) {
                current_prob *= probs[u];
            }
            ans = max(ans, current_prob);
        }
    }
    
    cout << fixed << setprecision(200) << ans << ln;
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
