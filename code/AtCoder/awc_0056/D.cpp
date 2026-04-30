// Problem: D - Dividing the Flower Bed into Sections
// Contest: AtCoder - AtCoder Weekday Contest 0056 Beta
// URL: https://atcoder.jp/contests/awc0056/tasks/awc0056_d
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
vector<vector<pair<int, int>>> AL;
vector<vector<int>> dp;

int n, k;

int recurse(int idx, int rem) {
	if (rem == 0) {
		if (idx == n) return 0;
		return INF;
	}
	if (idx == n) {
		if (rem == 0) return 0;
		return INF;
	}
	
	if (dp[idx][rem] != -1) return dp[idx][rem];
	
	int res = INF;
	for (auto& [v, w] : AL[idx]) {
		res = min(res, recurse(v, rem - 1) + w);
	}
	
	return dp[idx][rem] = res;
}

void solve() {
    cin >> n >> k;
    AL.resize(n + 1);
    dp.assign(n + 1, vector<int> (k + 1, -1));
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
	for (int j = 0; j < n; j++) {
		int mn = a[j], mx = a[j];
	
		for (int k = j; k < n; k++) {
			mx = max(mx, a[k]);
			mn = min(mn, a[k]);
			
			AL[j].pb({k + 1, mx - mn});
		}
    }
    
    cout << recurse(0, k) << ln;
    
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
