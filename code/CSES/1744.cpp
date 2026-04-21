// Problem: Rectangle Cutting
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1744
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
// #define int ll
#define ld long double
#define pb push_back

const int INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int dp[501][501];

int recurse(int l, int w) {
	if (l == w) {
		return 0;
	}
	if (l <= 0 or w <= 0) {
		return INF;
	}
	
	if (dp[l][w] != -1) return dp[l][w];
	int res = INF;
	
	
	// if (l < w) {
		// res = recurse(l, w - l) + 1;
	// }
	// else res = recurse(l - w, w) + 1;
	
	for (int i = 1; i <= l/2; i++) {
		res = min(res, 
			recurse(l-i, w) + 
			recurse(i, w) +
			1
		);
	}
	for (int i = 1; i <= w/2; i++) {
		res = min(res, 
			recurse(l, w-i) + 
			recurse(l, i) +
			1
		);
	}
	
	// cout << l << " " << w << " " << res << ln;
	
	return dp[l][w] = res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    fill_n(&dp[0][0], 501*501, -1);
    cout << recurse(a, b) << ln;
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
