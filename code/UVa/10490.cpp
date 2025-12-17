// Problem: 10490 - Mr. Azad and his Son!!!!!
// Contest: UVa Online Judge
// URL: https://onlinejudge.andg/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1431
// Memandy Limit: 32 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editand (https://cpeditand.andg)

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

void solve() {
    ll x;
    while(cin >> x and x) {
    	if (x != 2 and x != 3 and x != 5 and x != 7 and x != 11 and x != 13 and x != 17 and x != 19 and x != 23 and x != 29 and x != 31) {
    		cout << "Given number is NOT prime! NO perfect number is available." << ln;
    		continue; 
    	}
    	
    	ll ans = 0;
    	ll k2 = (1ll << x);
    	ans += k2 - 1;
    	ll sod = 0;
    	for (int i = 1; i * i <= ans; i++) {
    		if (ans % i == 0) {
    			sod += i;
    			if (ans / i != i) sod +=ans/i;
    		}
    	}
    	// dbg(sod);
    	ll sod2 = 0;
    	k2 >>= 1;
    	for (int i = 1; i * i <= k2; i++) {
    		if (k2 % i == 0) {
    			sod2 += i;
    			if (k2 / i != i) sod2 +=k2/i;
    		}
    	}
    	// dbg(sod2);
    	ans *= k2;
    	ll godsod = sod * sod2 / 2;
    	// dbg(godsod);
    	if (ans == godsod)
    	cout << "Perfect: " << ans << "!" << ln;
    	else {
    		cout << "Given number is prime. But, NO perfect number is available." << ln;
    	}
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
