// Problem: N - Slimes
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_n
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

int dp[401][401];
vector<int> a, pref;

int recurse(int l, int r) {
	if (l >= r) {
		return 0;
	}
	
	if (dp[l][r] != -1) return dp[l][r];
	
	int res = INF;
	
	for (int k = l; k < r; k++) {
		res = min(res, 
			recurse(l, k) + recurse(k + 1, r) + pref[r + 1] - pref[l]
		);
	}
	
	return dp[l][r] = res;
}

void solve() {
    int n;
    cin >> n;
    a.assign(n,0);
    pref.assign(n + 1, 0);
    fill_n(&dp[0][0], 401*401, -1);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    cout << recurse(0, n - 1) << ln;
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
