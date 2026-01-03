// Problem: K. King's Colors
// Contest: Codeforces - 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// URL: https://codeforces.com/gym/101933/problem/K
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

int dp[2501][2501];

void solve() {
    for (auto& i : dp) for (auto& j : i) j = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i ++) {
    	int x;
    	cin >> x;
    }
    
    dp[1][1] = k;
    
    for (int i = 2; i <= n; i++) {
    	for (int j = 1; j <= min(i, k); j++) {
    		dp[i][j] = (k - j + 1) * dp[i - 1][j - 1] + (j - 1) * dp[i - 1][j];
    		dp[i][j] %= MOD;
    	}
    }
    
    cout << dp[n][k] << ln;
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
