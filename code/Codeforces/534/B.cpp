// Problem: B. Covered Path
// Contest: Codeforces - Codeforces Round 298 (Div. 2)
// URL: https://codeforces.com/contest/534/problem/B
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
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    
    vector<int> lr(t), rl(t);
    for (int i = 0; i < t; i++) {
    	lr[i] = v1 + d * i;
    	rl[t-i-1] = v2 + d * i;
    }
    
    ll ans = 0;
    for (int i = 0; i < t; i++) {
    	ans += min(lr[i], rl[i]);
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
