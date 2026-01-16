// Problem: J. Bottles
// Contest: Codeforces - 2016-2017 ACM-ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/730/problem/J
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

int n, k;
vector<int> a, b;
int dp[2][10001][101];

int getMinBottles(vector<int> c, int sum) {
	sort(c.rbegin(), c.rend());
	int r = 0;
	int cur = 0;
	while (cur < sum) {
		cur += c[r++];
	}
	
	return r;
}

void solve() {
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
    // First, solve how many bottles are needed
    	// This is greedyable
    	// Catch: we don't know which bottles!
    int s = 0;
    for (auto& i : a) s += i;
    k = getMinBottles(b, s);
    // Check every way of using k bottles
    // 0/1 dp, holding capacity of chosen (excl. their water) and
    // amount in the rest and amount chosen
    // dp[idx][capacity][remainder][chosen]
    // idx = 100, cap = 100*100, remainder = 100 * 100, chosen = 100
    // remainder can be retrieved?
    	// not really
    // idx can be flattened?
    	// sure
    // dp[2][1e4][1e4][1e2] -> 1e10... ofc not
    
    // We care if capacity is higher than s... not much else
    // so ignore remainder
    // dp[2][1e4][1e2] -> 1e6
    
    fill_n(&dp[0][0][0], 2 * 10001*101, INF);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	for (int j = 0; j <= 10000; j++) {
    		for (int l = 0; l <= 100; l++) {
    			auto& x = dp[now][j][l];
    			if (j - b[i-1] >= 0 and l) 
    				x = min(x, dp[last][j - b[i - 1]][l - 1]);
    			x = min(x, dp[last][j][l] + a[i - 1]);
    		}
    	}
    	
    	fill_n(&dp[last][0][0], 10001*101, INF);
    }
    
    int ans = INF;
    
    for (int j = s; j <= 10000; j++) {
    	ans = min(ans, dp[n%2][j][k]);
    }
    
    cout << k << " " << ans << ln;
    
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
