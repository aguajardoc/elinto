// Problem: G. GCD on a grid
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/G
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

int a[101][101], dp[101][101];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    
    vector<int> facs;
    int og = a[0][0];
    for (int i = 1; i * i <= og; i++) {
    	if (og % i == 0) {
    		facs.pb(i);
    		facs.pb(og/i);
    	}
    }
    
    int ans = 1;
	for (auto& ele : facs) {
		int item = ele;
    
    	dp[0][1] = 0;
    	a[0][0] = item;
    	
    	for (int x = 1; x <= n; x++) {
    		for (int y = 1; y <= m; y++) {
    			dp[x][y] = max(gcd(dp[x-1][y], a[x-1][y-1]), gcd(dp[x][y-1], a[x-1][y-1]));
    		}
    	}
    	
    	ans = max(ans, dp[n][m]);	
	}
	
    cout << ans << ln;
}

signed main() {
    fast_cin();
    fill_n(&dp[0][0], 101*101, 1);
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
