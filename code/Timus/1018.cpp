// Problem: 1018. Binary Apple Tree
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1018
// Memory Limit: 64 MB
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

vector<vector<pair<int, int>>> AL;
int dp[105][105];

void recurse(int u, int p) {
	for (auto& [v, w] : AL[u]) {
		if (v == p) continue;
		recurse(v, u);
		
		for (int i = 100; i >= 1; i--) {
			for (int j = 0; j < i; j++) {
				dp[u][i] = max(
					dp[u][i],
					dp[u][i-j-1] + dp[v][j] + w
				);
			}
		}
	}
}

void solve() {
    fill_n(&dp[0][0], 105*105, 0);
    int n, q;
    cin >> n >> q;
    AL.assign(n, vector<pair<int, int>> ());
    
    for (int i = 0; i < n - 1; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({v, w});
    	AL[v].pb({u, w});
    }
    
    recurse(0, -1);
    
    cout << dp[0][q] << ln;
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
