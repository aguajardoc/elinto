// Problem: D. As Fast As Possible
// Contest: Codeforces - Codeforces Round 364 (Div. 2)
// URL: https://codeforces.com/contest/701/problem/D
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

void solve() {
    int nx, l, v1, v2, k;
    cin >> nx >> l >> v1 >> v2 >> k;
    
    int n = nx / k + min(1ll, nx % k);
    
    ld d = (1.0 * l / v1 + 1.0 * l / v2) / (1.0 * (n - 1.0) / v2 + 1.0 / v1 + 1.0 * n / v2);
    ld t = 1.0 * (l - d) / v1 + 1.0 * d / v2;
    
    cout << fixed << setprecision(10) << t << ln;
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
