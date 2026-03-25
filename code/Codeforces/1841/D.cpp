// Problem: D. Pairs of Segments
// Contest: Codeforces - Educational Codeforces Round 150 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1841/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

vector<vector<vector<int>>> dp;
vector<pair<int, int>> a;
int n;

int recurse(int idx, int mx, int parity) {
	if (idx == n) {
		return 0;
	}
	
	if (dp[parity][mx][idx] != -1) return dp[parity][mx][idx];
	
	int res = 0;
	
	if (parity == 0) {
		if (a[idx].first > mx) {
			res = max(res, recurse(idx + 1, max(mx, a[idx].second), 1));
		}
	}
	else {
		if (a[idx].first <= mx) {
			res = max(res, recurse(idx + 1, max(mx, a[idx].second), 0) + 1);
		}		
	}
	res = max(res, recurse(idx + 1, mx, parity));
	
	return dp[parity][mx][idx] = res;
}


void solve() {
    cin >> n;
    a.assign(n, {0, 0});
    vector<int> vals = {0};
    dp.assign(2, vector<vector<int>> (2 * n + 2, vector<int> (n+1, -1)));
    
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    	a[i].first++;
    	a[i].second++;
    	
    	vals.pb(a[i].first);
    	vals.pb(a[i].second);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (auto& [x, y] : a) {
    	x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    	y = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
    }
    
    sort(a.begin(), a.end());
    
    // for (auto& [x, y] : a) {
    	// cout << x << " " << y << ln;
    // }
    
    cout << n - 2*recurse(0, 0, 0) << ln;
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
 