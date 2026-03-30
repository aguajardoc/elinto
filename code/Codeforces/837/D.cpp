// Problem: D. Round Subset
// Contest: Codeforces - Educational Codeforces Round 26
// URL: https://codeforces.com/contest/837/problem/D
// Memory Limit: 256 MB
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

int dp[2][201][5001];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), twos(n, 0), fives(n, 0);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	int c = a[i];
    	while (c % 2 == 0) {
    		c/=2;
    		twos[i]++;
    	}
    	c = a[i];
    	while (c % 5 == 0) {
    		c/= 5;
    		fives[i]++;
    	}
    }
    
    fill_n(&dp[0][0][0], 2*201*5001, -1);
    dp[0][0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	
    	for (int j = 0; j <= k; j++) {
    		for (int f = 5000; f >= 0; f--) {
    			if(j and f-fives[i-1] >= 0 and dp[last][j-1][f-fives[i-1]] != -1)
    			dp[now][j][f] = 
    			max(
    				dp[now][j][f],
    				dp[last][j-1][f-fives[i-1]] + twos[i-1]
    			);
    			
    			if(dp[last][j][f] != -1)
    			dp[now][j][f] = 
    			max(
    				dp[now][j][f],
    				dp[last][j][f]
    			);
    		}
    	} 
    	
    	fill_n(&dp[last][0][0], 201 * 5001, -1);
    	dp[last][0][0] = 0; 
    }
    
    int ans = 0;
    for (int i = 0; i <= 5000; i++) {
    	ans = max(ans, min(i, dp[n%2][k][i]));
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
