// Problem: E. Xenia and Tree
// Contest: Codeforces - Codeforces Round 199 (Div. 2)
// URL: https://codeforces.com/contest/342/problem/E
// Memory Limit: 256 MB
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
const int MOD = 1000000007;
const double eps = 1e-9;

int n, m;
vector<vector<int>> AL;
vector<int> subtree_size, killed_centroids, parent_cd, dist_to_red, dist_root;

int l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

int get_subtree_size(int u, int p=-1) {
    subtree_size[u] = 1;
    
    for (auto& v : AL[u]) {
        if (v == p or killed_centroids[v]) continue;
        
        subtree_size[u] += get_subtree_size(v, u);
    }
    
    return subtree_size[u];
}

int get_centroid(int u, int n, int p=-1) {
    for (auto& v : AL[u]) {
        if (v == p or killed_centroids[v]) continue;
        
        if (subtree_size[v] * 2 > n) {
            return get_centroid(v, n, u);
        }
    }
    
    return u;
}

int centroid_decomp(int u) {
    int centroid = get_centroid(u, get_subtree_size(u));
    
    killed_centroids[centroid] = 1;
    
    for (auto& v : AL[centroid]) {
        if (killed_centroids[v]) continue;
        parent_cd[centroid_decomp(v)] = centroid;
    }
    
    return centroid;
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            dist_root[u] = dist_root[v] + 1;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
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
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}

int dist(int a, int b) {
    return dist_root[a] + dist_root[b] - 2 * dist_root[lca(a, b)];
}

void make_red(int u) {
    for (int c = u; c != -1; c = parent_cd[c]) {
        dist_to_red[c] = min(dist_to_red[c], dist(u, c));
    }
}

int query(int u) {
    int res = INF;
    for (int c = u; c != -1; c = parent_cd[c]) {
        res = min(res, dist_to_red[c] + dist(u, c));
    }
    
    return res;
}

void solve() {
    cin >> n >> m;
    AL.resize(n+1);
    subtree_size.assign(n + 1, 0);
    dist_to_red.assign(n + 1, INF);
    dist_root.assign(n + 1, 0);
    parent_cd.assign(n + 1, -1);
    killed_centroids.assign(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        AL[u].pb(v);
        AL[v].pb(u);
    }
    
    adj = AL;
    centroid_decomp(1);
    preprocess(1);
    make_red(1);
    
    while(m--) {
        int type, u; cin >> type >> u;
        if (type == 1) make_red(u);
        else cout << query(u) << ln;
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
