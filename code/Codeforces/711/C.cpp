// Problem: C. Coloring Trees
// Contest: Codeforces - Codeforces Round 369 (Div. 2)
// URL: https://codeforces.com/contest/711/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
vector<vector<vector<int>>> dp(101, vector<vector<int>> (102, vector<int> (101, 1e16)));
vector<int> color;
vector<vector<int>> p;
int n, m, k;

int recurse(int idx, int prev, int beauty) {
	if (idx == n) {
		if (beauty == k) return 0;
		return 1e12;
	}
	
	if (dp[idx][prev][beauty] != 1e16) return dp[idx][prev][beauty];
	
	int cost = 1e12;
	// dont paint
	if (color[idx] != 0) {
		cost = recurse(idx + 1, color[idx], beauty + (prev != color[idx]));
	}
	// paint it in any color
	else {
		for (int i = 1; i <= m; i++) {
			cost = min(cost, recurse(idx + 1, i, beauty + (prev != i)) + p[idx][i]);
		}
	}
	
	return dp[idx][prev][beauty] = cost;
}

void solve() {
    cin >> n >> m >> k;
    color.assign(n, 0);
    p.assign(n, vector<int> (m + 1, 0));
    for (auto& i : color) cin >> i;
    for (int i = 0; i < n ; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> p[i][j];
    	}
    }
    
    recurse(0, 101, 0);
    
    int ans = dp[0][101][0];
    if (ans >= 1e12) ans = -1;
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
