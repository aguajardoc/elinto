// Problem: D - Importance of Relay Cities
// Contest: AtCoder - AtCoder Weekday Contest 0154 Beta
// URL: https://atcoder.jp/contests/awc0154/tasks/awc0154_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AM(n, vector<int> (n, INF));
    for (int i = 0; i < n; i++) AM[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        AM[u][v] = min(AM[u][v], w);
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AM[i][j] = min(AM[i][j], 
                    AM[i][k] + AM[k][j]
                );
            }
        }
    }
    
    vector<int> ans(n, 0);
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i == k) continue;
            for (int j = 0; j < n; j++) {
                if (j == k or j == i) continue;
                if (AM[i][j] == AM[i][k] + AM[k][j]) {
                    ans[k]++;
                }
            }
        }
    }
    
    for (auto& i : ans) {
        cout << i << ln;
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
