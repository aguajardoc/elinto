// Problem: D. Kefa and Dishes
// Contest: Codeforces - Codeforces Round 321 (Div. 2)
// URL: https://codeforces.com/contest/580/problem/D
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int MAXN = 1 << 19;
const int MAXM = 19;
int dp[MAXN][MAXM];
int rules[MAXM][MAXM];
int sat[MAXM];

int n, m, k;

int recurse(int tasted, int prev) {
	if (__builtin_popcountll(tasted) == m) {
		return 0;
	}
	if (dp[tasted][prev] != -1) return dp[tasted][prev];
	
	int res = 0;
	
	for (int j = 0; j < n; j++) {
		if (tasted & (1ll << j)) continue;
		res = max(res,
		                          recurse(tasted | (1ll << j), j)
		                          + sat[j] + rules[prev][j]);
	}
	
	return dp[tasted][prev] = res;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
    	cin >> sat[i];
    }
    for (int i = 0; i < k; i++) {
    	int x, y, c;
    	cin >> x >> y >> c;
    	x--, y--;
    	rules[x][y] = c;
    }
    
    cout << recurse(0, n) << ln;
}

signed main() {
    fast_cin();
    fill_n(&dp[0][0], MAXN*MAXM, -1);
    fill_n(&rules[0][0], MAXM*MAXM, 0);
    fill_n(&sat[0], MAXM, 0);
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
