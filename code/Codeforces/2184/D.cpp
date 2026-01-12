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

// From USACO Guide: https://usaco.guide/gold/combo?lang=cpp
/** @return nCk using dynamic programming */
vector<vector<int>> dp(40, vector<int>(40 + 1, 0));
int binomial(int n, int k, int p=INF) {
	// dp[i][j] stores iCj

	// base cases described above
	

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
	}

	return dp[n][k];  // returns nCk
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    
    int mask = 1;
    int res = 1;
    int after = 0;
    while (mask < n) {
    	for (int i = 0; i <= after; i++) {
    		if (i + res > k) break;
    		ans += binomial(after, i);	
    	}
    	
    	mask<<=1;
    	res++;
    	after++;
    }
    
    if (res <= k) ans++;
    
    cout << n - ans << ln;
}

signed main() {
    fast_cin();
    for (int i = 0; i <= 35; i++) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		dp[i][i] = 1;
	}
	binomial(34, 34);
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
