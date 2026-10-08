// Problem: Fixed-Length Paths I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2080
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
// #define int ll
#define ld long double
#define pb push_back
 
const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;
 
const int N = 2e5 + 6;
 
int dist[N], last[N], subtree_size[N], banned_centroids[N];
vector<int> AL[N];
ll ans, n, k;
 
int get_subtree_size(int u, int p=-1) {
    subtree_size[u] = 1;
    
    for (auto& v : AL[u]) {
        if (v == p or banned_centroids[v]) continue;
        subtree_size[u] += get_subtree_size(v, u);
    }
    
    return subtree_size[u];
}
 
int get_centroid(int u, int n, int p=-1) {
    for (auto& v : AL[u]) {
        if (v == p or banned_centroids[v]) continue;
        if (subtree_size[v] * 2 > n) return get_centroid(v, n, u);
    }
    
    return u;
}
 
void compute_dists(int u, int p, int depth, int timer) {
    if (depth > k) return;
    if (last[depth] != timer) {
        dist[depth] = 1;
        last[depth] = timer;
    }
    else dist[depth]++;
    
    for (auto& v : AL[u]) {
        if (v == p or banned_centroids[v]) continue;
        compute_dists(v, u, depth + 1, timer);
    }
}
 
void update_ans(int u, int p, int depth, int timer) {
    if (k - depth < 0) return;
    if (last[k-depth] == timer) ans += dist[k - depth];
    
    for (auto& v : AL[u]) {
        if (v == p or banned_centroids[v]) continue;
        update_ans(v, u, depth + 1, timer);
    }
}
 
void centroid_decomp(int u, int& timer) {
    int centroid = get_centroid(u, get_subtree_size(u));
    banned_centroids[centroid] = true;
    
    // For each component, add to ans
    dist[0] = 1;
    last[0] = timer;
    for (auto& v : AL[centroid]) {
        if (banned_centroids[v]) continue;
        update_ans(v, centroid, 1, timer);
        compute_dists(v, centroid, 1, timer);
    }
    
    for (auto& v : AL[centroid]) {
        if (banned_centroids[v]) continue;
        
        centroid_decomp(v, ++timer);
    }
}
 
void solve() {
    cin >> n >> k;
    ans = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        AL[u].pb(v);
        AL[v].pb(u);
    }
    
    int timer = 0;
    centroid_decomp(0, timer);
    
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