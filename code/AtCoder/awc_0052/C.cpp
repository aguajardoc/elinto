// Problem: C - Shopping Challenge
// Contest: AtCoder - AtCoder Weekday Contest 0052 Beta
// URL: https://atcoder.jp/contests/awc0052/tasks/awc0052_c
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

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n), c(n);
	for (int  i = 0; i < n; i++) {
		cin >> v[i] >> c[i];
	}
	
    int dp[2][10010];
	fill_n(&dp[0][0], 2 * 10010, -INF);
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		int now = i % 2;
		int last = 1 - now;
		
		for (int j = 10000; j >= 0; j--) {
			if (dp[last][j] != -INF) {
				dp[now][j] = max(
					dp[now][j],
					dp[last][j]
				);
			}
			
			if (j - c[i-1] >= 0 and dp[last][j-c[i-1]] != -INF) {
				dp[now][j] = max(
					dp[now][j],
					dp[last][j-c[i-1]] + v[i-1]
				);
			}
		}
		
		fill_n(&dp[last][0], 10010, -INF);
	}
	
	int val = dp[n%2][s];
	
	if (val < 0) val = -1;
	
	cout << val << ln;
	
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
