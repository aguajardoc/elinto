// Problem: L. Last Orders
// Contest: Codeforces - 2025 United Kingdom and Ireland Programming Contest (UKIEPC 2025)
// URL: https://codeforces.com/gym/106157/problem/L
// Memory Limit: 1024 MB
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
int MA[301][301];

void solve() {
    int r;
    cin >> r;
    vector<int> pints(r);
    for (auto& i : pints) cin >> i;

    int k;
    cin >> k;
    vector<int> closing(k);
    for (auto& i : closing) cin >> i;

    int m;
    cin >> m;
    fill_n(&MA[0][0], 301*301, INF);
    
    for (int i = 0 ; i < k; i++) {
        MA[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        MA[u][v] = min(MA[u][v], w);
        MA[v][u] = min(MA[v][u], w);
    }


    for (int K = 0; K < k; K++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                MA[i][j] = min(MA[i][j], MA[i][K] + MA[K][j]);
            }
        }
    }
    
    int dp[301][101];
    fill_n(&dp[0][0], 301*101, INF);
    dp[0][0] = 0;
    
    for (int p = 0; p < r; p++) {
    	for (int u = 0; u < k; u++) {
    		if (dp[u][p] == INF) continue;
    		
    		for (int v = 0; v < k; v++) {
    			if (u == v and p != 0) continue;
    			int time = dp[u][p] + MA[u][v] + pints[p];
    			
    			if (time <= closing[v]) {
    				dp[v][p+1] = min(dp[v][p+1], time);
    			}
    		}
    	}
    }
    
    int ans = 0;
    for (int p = 0; p <= r; p++) {
    	for (int u = 0; u < k; u++) {
    		if (dp[u][p] != INF) {
    			ans = max(ans, p);
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
