// Problem: C. Costly Roads
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico Repechaje
// URL: https://codeforces.com/gym/106710/problem/C
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

const int MAXN = 200067;
int subtree_size[MAXN], ans[MAXN], visited[MAXN], base = 0, cur = 0, n;
vector<vector<pair<int, int>>> AL;
map<pair<int, int>, int> counter;

int dfs_sts(int u) {
    visited[u] = true;
    
    int res = 1;
    for (auto& [v, w] : AL[u]) {
        if (visited[v]) continue;
        
        cur += w;
        base += cur;
        res += dfs_sts(v);
        cur -= w;
    }
    
    return subtree_size[u] = res;
}

void dfs_ans(int u, int res) {
    visited[u] = true;
    ans[u] = res;
    
    for (auto& [v, w] : AL[u]) {
        if (visited[v]) continue;
        
        int additive = counter[{u, v}] * (n - subtree_size[v]);
        int subtractive = w * (subtree_size[v]);
        
        dfs_ans(v, res + additive - subtractive);
    }
}

void solve() {
    cin >> n;
    fill_n(&subtree_size[0], MAXN, 0);
    fill_n(&ans[0], MAXN, 0);
    AL.assign(n + 1, vector<pair<int, int>>());
    int leaf = 0;
    vector<int> ct(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        u--, v--;
        ct[u]++; ct[v]++;
        AL[u].pb({v, a});
        AL[v].pb({u, b});
        
        counter[{u, v}] = b;
        counter[{v, u}] = a;
    }
    
    for (int i = 0; i < n; i++) {
        if (ct[i] == 1) leaf = i;
    }
    
    fill_n(&visited[0], MAXN, 0);
    dfs_sts(leaf);
    fill_n(&visited[0], MAXN, 0);
    dfs_ans(leaf, base);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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
