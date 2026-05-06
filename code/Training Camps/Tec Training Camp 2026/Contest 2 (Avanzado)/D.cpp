// Problem: D. Loppinha, the boy who likes sopinha
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/D
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
// #define int ll
#define ld long double
#define pb push_back

const int INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int dp[2][451][451];

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    fill_n(&dp[0][0][0], 2 * 451 * 451, INF);
    dp[0][0][0] = 0;
    
    for (int idx = 1; idx <= n; idx++) {
    	int now = idx % 2;
    	int last = 1 - now;
    	for (int cons = 0; cons <= n; cons++) {
    		for (int rem = 0; rem <= n; rem++) {
    			if (s[idx-1] == '0') {
    				// dont do anything
    				dp[now][0][rem] = min(
    					dp[now][0][rem],
    					dp[last][cons][rem]
    				);
    			}
    			else {
    				// Leave it or kill it
    				if (cons > 0 and dp[last][cons-1][rem] != INF) {
	    				dp[now][cons][rem] = min(
	    					dp[now][cons][rem],
	    					dp[last][cons-1][rem] + cons
	    				);
    				}
    				
    				if (rem > 0 and dp[last][cons][rem-1] != INF) {
    					dp[now][0][rem] = min(
    						dp[now][0][rem],
	    					dp[last][cons][rem-1]
	    				);
	    			}
	    		}
    		}
    	}
    	
    	fill_n(&dp[last][0][0], 451 * 451, INF);
    }
    
    int ans = INF;
    for (int cons = 0; cons <= n; cons++) {
    	for (int rem = 0; rem <= n; rem++) {
    		// dbg(dp[n%2][cons][rem]);
    		// dbg(rem);
    		int x = dp[n%2][cons][rem];
    		// dbg(x, rem);
    		if (x <= k) {
    			// dbg(x, rem);
    			ans = min(ans, rem);
    		}
    	}
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
