// Problem: A. Writing Code
// Contest: Codeforces - Codeforces Round 302 (Div. 1)
// URL: https://codeforces.com/contest/543/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    int dp[2][501][501];
    fill_n(&dp[0][0][0], 2*501*501, 0);
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	
    	for (int j = 0; j <= m; j++) {
    		for (int k = 0; k <= b; k++) {
    			// for (int l = 0; l <= 500; l++){
    				// if (j - l < 0) break;
    				// if (k - l * a[i - 1] < 0) break;
    				// dp[now][j][k] += dp[last][j - l][k - l * a[i - 1]];
    				// dp[now][j][k] %= mod;
    			// }
    			
    			dp[now][j][k] += dp[last][j][k];
    			dp[now][j][k] %= mod;
    			if (j and k - a[i-1] >= 0) dp[now][j][k] += dp[now][j - 1][k - a[i-1]];
    			dp[now][j][k] %= mod;
    		}
    	}
    	
    	fill_n(&dp[last][0][0], 501*501, 0);
    }
    
    int ans = 0;
    for (int i = 0;i <= b; i++) {
    	ans += dp[n%2][m][i];
    	ans %= mod;
    }
    
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