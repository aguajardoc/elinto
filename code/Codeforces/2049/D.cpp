// Problem: D. Shift + Esc
// Contest: Codeforces - Codeforces Round 994 (Div. 2)
// URL: https://codeforces.com/contest/2049/problem/D
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n+1, vector<int> (m+1, INF)), a = dp;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    dp[0][0] = 0;
    
    vector<int> cur(m + 1, INF);
    
    for (int i = 1; i <= n; i++) {
    	for (int s = 0; s < m; s++) {
    		cur.assign(m + 1, INF);
    		for (int j = 0; j < m; j++) cur[j] = dp[i-1][j] + a[i][(j+s)%m] + k*s;
    		for (int j = 0; j < m; j++) cur[j] = min(cur[j], cur[(j+m-1)%m] + a[i][(j+s)%m]);
    		for (int j = 0; j < m; j++) dp[i][j] = min(dp[i][j], cur[j]);
    	}
    }
    
    cout << dp[n][m-1] << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
