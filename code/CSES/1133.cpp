// Problem: Tree Distances II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1133
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

vector<int> dist, sts, ans;
int n;
vector<vector<int>> AL;

void dfs1(int u, int p) {
    sts[u]++;
    for (auto& v : AL[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs1(v, u);
        sts[u] += sts[v];
    }
}

void dfs2(int u, int p) {
    for (auto& v : AL[u]) {
        if (v == p) continue;
        ans[v] = ans[u] - sts[v] + (n - sts[v]);
        dfs2(v, u);
    }
}
void solve() {
    cin >> n;
    AL.resize(n);
    dist.assign(n, 0);
    sts.assign(n, 0);
    ans.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        AL[u].pb(v);
        AL[v].pb(u);
    }
    
    dfs1(0, -1);
    int res = 0; for (auto& i : dist) res += i;
    ans[0] = res;
    dfs2(0, -1);
    
    for (auto& i : ans) {
        cout << i << " ";
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
