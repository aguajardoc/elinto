// Problem: C. Gerald's Hexagon
// Contest: Codeforces - Codeforces Round 313 (Div. 2)
// URL: https://codeforces.com/contest/560/problem/C
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
    ll a[6];
    for (int i = 0; i < 6; i++) cin >> a[i];
    set<int> distinct;
    for (auto& i : a) distinct.insert(i);
    ll start = 1 + 2 * a[0];
    ll ans = 0;
    for (int i = 1; i <= min(a[1], a[5]); i++) {
    	ans += start;
    	start += 2;
    }
    start--;
    for (int i = min(a[1], a[5]) + 1; i <= max(a[1], a[5]); i++) {
    	ans += start;
    }
    start--;
    
    for (int i = 1; i <= min(a[2], a[4]); i++) {
    	ans += start;
    	start -= 2;
    }
    
    cout << ans << ln;
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
