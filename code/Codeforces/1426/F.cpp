// Problem: F. Number of Subsequences
// Contest: Codeforces - Codeforces Round 674 (Div. 3)
// URL: https://codeforces.com/contest/1426/problem/F
// Memory Limit: 256 MB
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<int> factorial;

ll binexp(ll a, ll b) {
	if (b < 0) return 0;
	ll res = 1;
	while(b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

int ncr(int n, int r) {
	int num = factorial[n];
	int den = factorial[r] * factorial[n - r];
	den %= MOD;
	
	int val = num * binexp(den, MOD - 2);
	val %= MOD;
	return val;
}

int f(int a, int c, int ub, int ua) {
	int ans = 1;
	int L1 = a * binexp(3, ub);
	int L2 = ub * binexp(3, ub - 1);
	int R1 = c * binexp(3, ua);
	int R2 = ua * binexp(3, ua - 1);
	
	int L = (L1 + L2) % MOD;
	int R = (R1 + R2) % MOD;
	ans = L * R;
	ans %= MOD;
	
	return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // for (int i = 0; i < 10; i++) {
    	// for (int j = 0; j < 10; j++) {
    		// dbg(i, j);
    		// cout << f(0, 1, i, j) << ln;
    	// }
    	// cout << ln;
    // }
    
    int a = 0, c = 0, ua = 0, ub = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '?') ua++;
    	if (s[i] == 'c') c++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
    	if (s[i] == '?') ua--;
    	if (s[i] == 'c') c--;
    	
    	if (s[i] == 'b' or s[i] == '?') {
    		// dbg(a, c, ub, ua);
    		int r = f(a, c, ub, ua);
    		// dbg
    		ans += r;
    		ans %= MOD;
    		
    		// dbg(i, r);
    		// cout << ln;
    	}
    	
    	if (s[i] == 'a') a++;
    	if (s[i] == '?') ub++;
    }
    
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    factorial = {1, 1};
    for (int i = 2; i <= 3e5; i++) {
    	factorial.pb(factorial.back() * i);
    	factorial.back() %= MOD;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
