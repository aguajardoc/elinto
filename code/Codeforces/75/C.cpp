// Problem: C. Modified GCD
// Contest: Codeforces - Codeforces Beta Round 67 (Div. 2)
// URL: https://codeforces.com/contest/75/problem/C
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
    ll a, b;
    cin >> a>> b;
    int q;
    cin >> q;
    vector<int> divs;
    ll x = gcd(a, b);
    
    for (int i = 1; i * i<= x; i++) {
    	if (x % i == 0) {
    		divs.push_back(i);
    		if (x / i != i) divs.push_back(x / i);
    	}
    }
    
	sort(divs.begin(), divs.end());
    while(q--) {
    	int l, r;
    	cin >> l >>  r;
    	auto it = lower_bound(divs.begin(), divs.end(), r);
    	if (it == divs.end()) it--;
    	while (it != divs.begin() and *it > r) it--;
    	
    	if (*it < l) cout << -1 << ln;
    	else cout << *it << ln;
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
