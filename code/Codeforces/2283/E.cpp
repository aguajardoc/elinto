// Problem: E. Partition of a Binary String
// Contest: Codeforces - Educational Codeforces Round 196 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2283/problem/E
// Memory Limit: 512 MB
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
const int MOD = 998244353;
const double eps = 1e-9;

vector<int> bell(5067, 0);

// Usage: run binomialInit(), then binomial
vector<vector<int>> dp(6000 + 1, vector<int>(6000 + 1, 0));
vector<int> part23(5555, 0);
vector<int> fact(6000, 1);

vector<int> dp2(5500, 0);

void binomialInit() {
    // base cases described above
	for (int i = 0; i <= 6000; i++) {
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
		if (i <= 6000) { dp[i][i] = 1; }
	}
}

/** @return nCk mod p using dynamic programming */
int binomial(int n, int k, int p) {
	// dp[i][j] stores iCj

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
			}
		}
	}

	return dp[n][k];  // returns nCk modulo p
}



void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> consec(n, 1);
    consec[0] = 1;
    for (int i = 1; i < n; i++) {
    	if (s[i] != s[i-1]) {
    		consec[i] = 0;
    		consec[i-1] = 0;
    	}
    }
    
    int c0 = 0, c1 = 0;
    vector<int> alts;
    
    int cura = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
    	if (consec[i]) {
    		if (cura) {
    			alts.pb(cura);
    			cura = 0;
    		}
    		c0 += (s[i] == '0');
    		c1 += (s[i] == '1');
    	}
    	else {
    		if (i and s[i] == s[i-1] and cura) {
    			alts.pb(cura);
    			cura = 0;
    		}
    		cura++;
    		// dbg(i, cura);
    	}
    }
    if (cura) alts.pb(cura);
    
    int ans = 1;
    
    ans *= bell[c0];
    ans %= MOD;
    ans *= bell[c1];
    ans %= MOD;
    for (auto& i : alts) {
    	ans *= dp2[i];
    	ans %= MOD;
    	
    	mx += i * 2;
    	mx %= MOD;
    }
    mx += c0 + c1;
    mx %= MOD;
    
    cout << mx << " " << ans << ln;
}

signed main() {
    fast_cin();
    binomialInit();
    bell[0] = 1;
    binomial(6000, 6000, MOD);
    for (int i = 1; i <= 5066; i++) {
    	int cur = 0;
    	for (int j = 0; j < i; j++) {
    		int ncr = dp[i-1][j] % MOD;
    		cur += (ncr * bell[j]) % MOD;
    		cur %= MOD;
    	}
    	bell[i] = cur;
    }
    
    dp2[0] = 1;
    
    for (int i = 1; i <= 5200; i++) {
    	for (int j = 2; j <= min(3ll, i); j++) {
    		dp2[i] += dp2[i-j];
    		dp2[i] %= MOD;
	    }
    }
    
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
