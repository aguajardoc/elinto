// Problem: D. Falling Anvils
// Contest: Codeforces - Codeforces Beta Round 69 (Div. 2 Only)
// URL: https://codeforces.com/contest/80/problem/D
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int a, b;
    cin >> a >> b;
    ld A = a;
    ld B = b;
    if (a == 0 and b == 0) {
    	cout << "1.0000000000" << ln;
    	return;
    }
    if (a == 0) {
    	cout << "0.5000000000" << ln;
    	return;
    }
    if (b == 0) {
    	cout << "1.0000000000" << ln;
    	return;
    }
    
    ld ans;
    if (a <= 4 * b) {
    	ans = (A*A/8 + A*B) / (2*A*B);
    }
    else {
    	ans = (2*B*B + B * (A - 4*B) + A*B) / (2*A*B);
    }
    
    cout << fixed << setprecision(10) << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
