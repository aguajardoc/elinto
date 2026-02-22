// Problem: I. Interrail Pass
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/I
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

int dp[10001];
int n, k;
vector<int> t, f, p, d, c;

int T(int curtime, int period) {
	// Get last before time
	int first = curtime - period;
	int idx = distance(t.begin(), upper_bound(t.begin(), t.end(), first));
	
	return idx;
}

void solve() {
    cin >> n >> k;
    t.assign(n, 0);
    f.assign(n, 0);
    
    p.assign(k, 0);
    d.assign(k, 0);
    c.assign(k, 0);
    
    for (int i = 0; i < n; i++) {
    	cin >> t[i] >> f[i];
    }
    for (int i = 0; i < k; i++) {
    	cin >> p[i] >> d[i] >> c[i];
    }
    
    fill_n(&dp[0], 10001, 0);
    
    for (int i = 1; i <= n; i++) {
    	dp[i] = dp[i-1] + f[i-1];
    	
    	for (int j = 0; j < k; j++) {
    		int ni = max({0ll, i - d[j], T(t[i-1], p[j])});
    		// dbg(i, j, ni);
    		dp[i] = min(dp[i], c[j] + dp[ni]);
    	}
    }
    
    cout << dp[n] << ln;
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
