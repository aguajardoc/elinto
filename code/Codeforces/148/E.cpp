// Problem: E. Porcelain
// Contest: Codeforces - Codeforces Round 105 (Div. 2)
// URL: https://codeforces.com/contest/148/problem/E
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
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> prefixes(n, vector<vector<int>> (2, vector<int> (100 + 1, 0)));
    vector<vector<int>> best(n, vector<int> (101, 0));
    vector<vector<int>> a(n);
    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	sizes[i] = x;
    	vector<int> b(x);
    	for (auto& j : b) cin >> j;
    	
    	for (int j = 1; j <= x; j++) {
    		prefixes[i][0][j] = prefixes[i][0][j-1] + b[j-1];
    		prefixes[i][1][x-j] = prefixes[i][1][x-j+1] + b[x-j];
    	}
    	
    	for (int j = 1; j <= x; j++) {
    		// Get best of taking j items
    		int res = 0;
    		for (int k = 0; k <= j; k++) {
    			// Get first k as left, rest from right
    			int local = prefixes[i][0][k] - prefixes[i][0][0];
    			local += prefixes[i][1][x + k - j] - prefixes[i][1][x];
    			res = max(local, res);
    		}
    		
    		best[i][j] = res;
    	}
    }
    
    // Dp time :)
    int dp[2][10001];
    fill_n(&dp[0][0], 2*10001, -1);
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	
    	for (int j = 0; j <= m; j++) {
    		for (int k = max(0ll, j - sizes[i-1]); k <= j; k++) {
    			int items = j - k;
    			dp[now][j] = max(dp[now][j], dp[last][k] + best[i - 1][items]);
    		}
    	}
    	
    	fill_n(&dp[last][0], 10001, -1);
    }
    
    int ans = 0;
    for (int i = 0; i <= m; i++) {
    	ans = max(ans, dp[n%2][i]);
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
