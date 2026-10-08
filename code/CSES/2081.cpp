// Problem: Fixed-Length Paths II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2081
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

struct Segtree {
    vector<int> bit;  // binary indexed tree
    int n;
    
    Segtree() {}

    Segtree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    Segtree(vector<int> const &a) : Segtree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n, k1, k2;
ll ans = 0;
const int N = 2e5 + 6;
int banned_centroids[N], subtree_size[N], ct[N];
vector<int> AL[N];
Segtree st;

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

void get_dists(int u, int p, int depth, int& md) {
    if (depth > k2) return;
    md = max(md, depth);
    ct[depth]++;
    
    for (auto& v : AL[u]) {
        if (v == p or banned_centroids[v]) continue;
        get_dists(v, u, depth + 1, md);
    }
}

void update_ans(int md) {
    for (int i = 0; i <= md; i++) {
        int L = k1 - i;
        int R = k2 - i;
        L = max(L, 0);
        R = min(R, n + 1);
        
        if (R < L) continue;
        
        // dbg(i);
        // dbg(L, R);
        // dbg(st.query(L, R));
        
        ans += (ll)ct[i] * st.query(L, R);
    }
    
    
    for (int i = 0; i <= md; i++) {
        st.update(i, ct[i]);
    }
}

void centroid_decomp(int u) {
    int centroid = get_centroid(u, get_subtree_size(u));
    banned_centroids[centroid] = true;
    
    // Compute distances
    st.update(0, 1);
    // dbg(centroid);
    int md = 0;
    int max_md = 0;
    for (auto& v : AL[centroid]) {
        if (banned_centroids[v]) continue;
        
        // dbg(v);
        get_dists(v, centroid, 1, md);
        update_ans(md);
        // cout << ln;
        
        max_md = max(max_md, md);
        
        for (int i = 0; i <= md; i++) {
            ct[i] = 0;
        }
        md = 0;
    }
    
    for (int i = 0; i <= max_md; i++) {
        st.update(i, -st.query(i, i));
    }
    
    
    for (auto& v : AL[centroid]) {
        if (banned_centroids[v]) continue;
        centroid_decomp(v);
    }
}

void solve() {
    cin >> n >> k1 >> k2;
    
    st = Segtree(n + 2);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        AL[u].pb(v);
        AL[v].pb(u);
    }
    
    centroid_decomp(0);
    
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
