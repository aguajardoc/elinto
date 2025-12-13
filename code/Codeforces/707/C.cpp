// Problem: C. Pythagorean Triples
// Contest: Codeforces - Codeforces Round 368 (Div. 2)
// URL: https://codeforces.com/contest/707/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    ll n;
    cin >> n;
    if (n <= 2) cout << -1 << ln;
    else if (n % 2) {
    	ll a = n * n - 1;
    	a /= 2;
    	ll c = n * n + 1;
    	c /= 2;
    	cout << a << " " << c << ln;
    }
    else {
    	ll a = n * n;
    	a /= 4;
    	a--;
    	ll c = n * n;
    	c /= 4;
    	c++;
    	cout << a << " " << c << ln;
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
