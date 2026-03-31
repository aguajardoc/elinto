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
    cin >> n;
    vector<vector<int>> transactions;
    for (int i = 0; i < n; i++) {
    	int c, f, v;
    	cin >> c >> f >> v;
    	transactions.pb({f, c, -v});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
    	int c, f, v;
    	cin >> c >> f >> v;
    	transactions.pb({f, -c, v});
    }
    sort(transactions.rbegin(), transactions.rend());
    
    int dp[2][100001];
    fill_n(&dp[0][0], 2*100001, -INF);
    dp[0][0] = 0;
    
    for (int i = 1; i <= n+m; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	int cores = transactions[i-1][1];
    	int value = transactions[i-1][2];
    	
    	for (int j = 0; j <= 100000; j++) {
    		dp[now][j] = max(dp[now][j], dp[last][j]);
    		if (j - cores >= 0 and j - cores <= 100000 and dp[last][j-cores] != -INF) {
    			dp[now][j] = max(dp[now][j], dp[last][j-cores] + value);
    		}
    	}
    	
    	fill_n(&dp[last][0], 100001, -INF);
    }
    
	int ans = 0;
	for (int i = 0; i <= 100000; i++) {
		ans = max(ans, dp[(n+m)%2][i]);
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
