// Problem: B - Squares
// Contest: AtCoder - AtCoder Regular Contest 125
// URL: https://atcoder.jp/contests/arc125/tasks/arc125_b
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
const int MOD = 998244353;
const double eps = 1e-9;

void solve() {
    int n; cin >> n;
    
    int ans = 0;
    int x, y;
    for (x = 1; x * x <= n; x++) {
    	if (x * x <= n) y = x;
    	int ksq = x * x - n;
    	if (ksq <= 0) {
    		ans += x;
    		ans %= MOD;
    		continue;
    	}
    	
    	
    	int fk = floor(sqrt(ksq)) + ((floor(sqrt(ksq)) * floor(sqrt(ksq))) != ksq);
    	int r = x - fk;
    	// dbg(x, r);
    }
    
    x = y;
    
    // At most one million values of r
    // We can interate over every r and check when it's valid
    int cur = x;
    for (int r = x; r >= 0; r--) {
    	int L = r, R = n; 
    	int res = r;
    	while (L <= R) {
    		int m = (L + R) / 2;
    		int target = m - r;
    		
    		int fm = m * m - target*target;
    		// dbg(m, target);
    		// dbg(fm);
    		// cout << ln;
    		if (fm <= n) {
    			res = max(res, m);
    			L = m + 1;
    		}
    		else {
    			R = m - 1;
    		}
    	}
    	
    	// dbg(r, res);
    	int d = res - cur;
    	if (d <= 0) continue;
    	
    	ans += (r * d) % MOD;
    	ans %= MOD;
    	cur = res;
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
