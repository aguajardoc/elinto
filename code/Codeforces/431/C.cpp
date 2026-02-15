// Problem: C. k-Tree
// Contest: Codeforces - Codeforces Round 247 (Div. 2)
// URL: https://codeforces.com/contest/431/problem/C
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

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    
    int dp[2][101];
    fill_n(&dp[0][0], 2*101, 0);
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= k; j++) {
    		if (i - j < 0) break;
    		
    		if (j < d) {
	    		dp[0][i] += dp[0][i - j];
	    		dp[0][i] %= MOD;
    		}
    		else {
    			dp[1][i] += dp[0][i - j];
    			dp[1][i] %= MOD;
    		}
    		
    		dp[1][i] += dp[1][i - j];
	    	dp[1][i] %= MOD;
    	}
    }
    
    cout << dp[1][n] << ln;
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
