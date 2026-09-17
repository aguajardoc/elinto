// Problem: Longest Flight Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1680
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

const int N = 100001;
int dp[N], nxt[N], n, m;
vector<vector<int>> AL;

int recurse(int u) {
    if (u == n) return 1;
    
    if (dp[u] != -1) return dp[u];
    
    int res = -INF;
    int p = -1;
    for (auto& v : AL[u]) {
        int local = recurse(v) + 1;
        if (local > res) {
            p = v;
        }
        res = max(res, local);
    }
    
    if (p != -1) nxt[u] = p;
    return dp[u] = res;
}

void init(int n) {
    AL.assign(n + 1, vector<int>());
    fill_n(&dp[0], N, -1);
    fill_n(&nxt[0], N, -1);
}

void solve() {
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        AL[u].pb(v);
    }
    
    int ans = recurse(1);
    if (ans < 0) {
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    
    cout << ans << ln;
    int cur = 1;
    while (cur != -1) {
        cout << cur << " ";
        cur = nxt[cur];
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
