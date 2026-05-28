// Problem: D. Wishing Cards
// Contest: Codeforces - Codeforces Round 1069 (Div. 2)
// URL: https://codeforces.com/contest/2175/problem/D
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
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> dp(2, vector<vector<int>> (k + 1, vector<int> (k + 1, -INF)));
    dp[0][0][0] = 0;
    
    vector<int> cap, dist;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (cap.empty() or x > cap.back()) {
    		cap.pb(x);
    		dist.pb(1);
    	}
    	else dist.back()++;
    }
    
    vector<vector<int>> best(k + 1, vector<int> (k + 1, 0));
    n = cap.size();
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	int C = cap[i-1];
    	int D = dist[i-1];
    	for (int S = 0; S <= k; S++) {
    		for (int M = 0; M <= S; M++) {
    			int& cur = dp[now][S][M];
    			
    			// do nothing
    			if (dp[last][S][M] != -INF) {
    				cur = max(cur,
    					dp[last][S][M] + D * M
    				);
    			}
    			
    			// Take, only if we can
    			if (best[S-M][M] != -INF and M <= C) {
    				cur = max(cur,
    					best[S-M][M] + D * M
    				);
    			}
    		}
    	}
    	
    	// upd best
    	for (int S = 0; S <= k; S++) {
    		int cur = 0;
    		for (int M = 0; M <= k; M++) {
    			cur = max(cur, dp[now][S][M]);
    			
    			best[S][M] = cur;
    		}
    	}
    	
    	dp[last].assign(k+1, vector<int> (k+1, -INF));
    }
    
    int ans = 0;
    for (int S = 0; S <= k; S++) {
    	for (int M = 0; M <= k; M++) {
    		ans = max(ans, dp[n%2][S][M]);
    	}
    }
    
    cout << ans << ln;
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
