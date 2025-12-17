// Problem: C. Tennis Championship
// Contest: Codeforces - Codeforces Round 382 (Div. 2)
// URL: https://codeforces.com/contest/735/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

ll f(ll x) {
	ll res = (x * (x + 1)) / 2;
	res += 2;
	return res;
}

void solve() {
    ll x;
    cin >> x;
    
    ll f0 = 2, f1 = 3;
    if (x == 2)  {
    	cout << 1 << ln;
    	return;
    }
    if (x < 5) {
    	cout << 2 << ln;
    	return;
    }
    for (ll i = 3; i <= 100; i++) {
    	ll fi = f0 + f1;
    	f0 = f1;
    	f1 = fi;
    	
    	if (fi > x) {
    		cout << i - 1 << ln;
    		return;
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
