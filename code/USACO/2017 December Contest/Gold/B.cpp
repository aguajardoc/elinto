// Problem: Problem 2. Barn Painting
// Contest: USACO - USACO 2017 December Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=766
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("barnpainting.in", "r", stdin); \
    freopen("barnpainting.out", "w", stdout)
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

vector<vector<int>> dp, AL;
vector<int> painted;

void dfs(int u, int p) {
	
	if (painted[u]) {
		dp[painted[u]][u] = 1;
	}
	else {
		dp[1][u] = 1;
		dp[2][u] = 1;
		dp[3][u] = 1;
	}
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u);
		
		dp[1][u] *= (dp[2][v] + dp[3][v]) % MOD;
		dp[2][u] *= (dp[1][v] + dp[3][v]) % MOD;
		dp[3][u] *= (dp[1][v] + dp[2][v]) % MOD;
		
		dp[1][u] %= MOD;
		dp[2][u] %= MOD;
		dp[3][u] %= MOD;
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    dp.assign(4, vector<int> (n, 0));
    AL.assign(n, vector<int> ());
    painted.assign(n, 0);
    
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    for (int i = 0; i< k; i++) {
    	int b, c;
    	cin >> b >> c;
    	b--;
    	painted[b] = c;
    }
    
    dfs(0, -1);
    
    int ans = 0;
    ans += dp[0][0];
    ans %= MOD;
    ans += dp[1][0];
    ans %= MOD;
    ans += dp[2][0];
    ans %= MOD;
    ans += dp[3][0];
    ans %= MOD;
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
