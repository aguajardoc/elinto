// Problem: C. Win or Freeze
// Contest: Codeforces - Codeforces Round 107 (Div. 2)
// URL: https://codeforces.com/contest/151/problem/C
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

void solve() {
    ll x;
    cin >> x;
    
    ll th = 1;
    ll powers = 0;
    for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			powers++;
			if (powers <= 2) {
				th *= i;
			}
			x /= i;
		}
    }
    
    if (x > 1) {
    	powers++;
    	if (powers <= 2) {
    		th *= x;
    	}
    }
    
    if (powers < 2) {
    	cout << 1 << ln << 0 << ln;
    }
    else if (powers == 2) {
    	cout << 2 << ln;
    }
    else {
    	cout << 1 << ln << th << ln;
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
