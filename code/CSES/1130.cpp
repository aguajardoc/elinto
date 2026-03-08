// Problem: Tree Matching
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1130
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

vector<int> visited;
vector<vector<int>> dp, AL;

void dfs(int u, int p) {
	visited[u] = 1;
	
	dp[0][u] = 0;
	dp[1][u] = 0;
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u);
		dp[0][u] += max(dp[0][v], dp[1][v]);
	}
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dp[1][u] = max(dp[1][u], dp[0][v] + 1 + dp[0][u] - max(dp[0][v], dp[1][v]));
	}
}

void solve() {
    int n;
    cin >> n;
    dp.assign(2, vector<int> (n, 0));
    visited.assign(n, 0);
    AL.assign(n, vector<int>());
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    dfs(0, -1);
    
    cout << max(dp[0][0], dp[1][0]) << ln;
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
