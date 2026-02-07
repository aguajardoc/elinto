// Problem: 10003 - Cutting Sticks
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

int dp[55][55];
vector<int> a;
int n;
int l;

int recurse(int l, int r) {
	if (l > r) return 0;
	
	if (dp[l][r] != -1) return dp[l][r];
	
	int res = INF;
	
	for (int k = l+1; k < r; k++) {
		res = min(res, a[r] - a[l] + recurse(l, k) + recurse(k, r));
	}
	if (res == INF) res = 0;
	
	return dp[l][r] = res;
}

void solve() {
    while (cin >> l and l) {
    	cin >> n;
    	n += 2;
    	a.assign(n, 0);
    	a[0] = 0;
    	for (int i = 1; i < n - 1; i++) {
    		cin >> a[i];
    	}
    	a[n-1] = l;
    	
    	fill_n(&dp[0][0], 55*55, -1);
    	
    	int ans = recurse(0, n - 1);
    	cout << "The minimum cutting is " << ans << ".\n";
    }
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
