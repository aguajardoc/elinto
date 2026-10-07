// Problem: Tree Distances I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1132
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

// Usage: preprocess(0) after adj init
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, dist;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p){
            dist[u] = dist[v] + 1;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs2(v, u);
    }
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
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int get_max() {
    int mx = 0;
    int node = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx) {
            mx = dist[i];
            node = i;
        }
    }
    
    return node;
}

int get_dist(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

void solve() {
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dist.assign(n, 0);
    preprocess(0);
    int L1 = get_max();
    dist.assign(n, 0);
    dfs2(L1, -1);
    int L2 = get_max();
    dist.assign(n, 0);
    dfs2(0, -1);
    
    for (int i = 0; i < n; i++) {
        cout << max(get_dist(i, L1), get_dist(i, L2)) << " ";
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
