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

struct Rule {
    int i, j, u, v;
};

vector<vector<int>> dp;
vector<Rule> a;

void solve() {
    int n;
    cin >> n;
    dp.assign(n + 10, vector<int> (n + 10, -1));
    a.clear();
    for (int i = 0; i < n; i++) {
        int I, J, U, V;
        cin >> I >> J >> U >> V;
        a.pb({I, J, U, V});
    }

    for (int i = 0; i <= n; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int m = 1; m <= n; m++) {
            // do nothing
            if (dp[i-1][m] != -1) {
                dp[i][m] = dp[i-1][m];

            // take
                int idx = dp[i-1][m] + 1;
                // if (m ==3) {
                //     dbg(i, idx);
                //     dbg(a[i-1].i);
                //     dbg(a[i-1].j);
                //     dbg(a[i-1].u);
                //     dbg(a[i-1].v);
                //     cout << ln;
                // }
                if ((idx < a[i-1].i or idx > a[i-1].j) and
                    (   m < a[i-1].u + idx - 1 or 
                        m > a[i-1].v + idx - 1
                    ) and
                    dp[i][m] < m
                ){
                    // if (m == 3) {
                    //     dbg(i, idx);
                    // }
                    dp[i][m] = max(dp[i][m], dp[i-1][m] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[n][i] == i) ans = i;
    }

    cout << ans << ln;

}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ C.cpp && ./a.out <input.in>output.out