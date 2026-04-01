// Problem: Coding Company
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1665
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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    int dp[2][101][5001];
    fill_n(&dp[0][0][0], 2*101*5001, 0);
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	for (int j = 0; j <= n; j++) {
    		for (int k = 0; k <= x; k++) {
    			int nb;
    			if (i == 1) nb = k + j * a[i-1];
    			else nb = k + j * (a[i-1] - a[i-2]);
    			
    			if (nb > x) continue;
    			
    			// Add a new group with just itself, close it
    			dp[now][j][nb] += dp[last][j][k];
    			dp[now][j][nb] %= MOD;
    			
    			// Add it to any group, close it
    			if (j) {
    				dp[now][j-1][nb] += j * dp[last][j][k];
    				dp[now][j-1][nb] %= MOD;
    			}
    			
    			// Add it to any group, dont close
    			dp[now][j][nb] += j * dp[last][j][k];
    			dp[now][j][nb] %= MOD;
    			
    			// Add a new group with itself, dont close
    			if (j < n) {
    				dp[now][j+1][nb] += dp[last][j][k];
    				dp[now][j+1][nb] %= MOD;
    			}
    		}
    	}
    	
    	fill_n(&dp[last][0][0], 101*5001, 0);
    }
    
    int ans = 0;
    for (int i = 0; i <= x; i++) {
    	ans += dp[n%2][0][i];
    	ans %= MOD;
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
