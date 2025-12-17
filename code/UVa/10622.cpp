// Problem: 10622 - Perfect P-th Powers
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1563
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

ll exponent(ll b, ll p) {
	ll res = 1;
	while(p) {
		if (p & 1) {
			res = (res * b);
		}
		b = (b * b);
		p >>= 1;
	}
	return res;
}

void solve() {
    ll x;
    while(cin >> x and x) {
    	ll ans = 1;

		bool flag = false;
    	if (x < 0) {
    		flag = true;
    		x = abs(x);
    	}
    	if (x == 1) {
    		cout << 1 << ln;
    		continue;
    	}
    	for (ll p = 1; p <= 32; p++) {
    		ld b = exp((ld)log(x) / (ld)p) + eps;
    		ll calc = exponent((ll)b, p);
    		
    		// dbg(b, p, calc, x);
    		if (x == calc) {
    			if (!flag or (flag and p % 2)) ans = p;
    		}
    	}
    	
    	cout << ans << ln;
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
