// Problem: D. Quantity of Strings
// Contest: Codeforces - Codeforces Round 107 (Div. 2)
// URL: https://codeforces.com/contest/151/problem/D
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

// Usage: a^b % m
long long binexp(long long a, long long b, long long m = 1000000007) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    if (k == 1 or n < k) {
    	cout << binexp(m, n) << ln;
    }
    else if (n == k) {
    	cout << binexp(m, n/2 + n % 2) << ln;
    }
    else if (k % 2 == 0) {
    	cout << m << ln;
    }
    else {
    	cout << m * m << ln;
    }
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
