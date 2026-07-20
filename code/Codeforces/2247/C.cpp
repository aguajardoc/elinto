// Problem: Inversion of a Subsequence
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/2247/problem/C
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
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    int b1s = 0;
    int g0 = 0, g1 = 0;
    int good = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i])g1++;
            else g0++;
            continue;
        }
        if (a[i]) b1s++;
        good = false;
    }
    
    if (good) {
        cout << 0 << ln;
    }
    else {
        if (b1s == 0) {
            if (g0 and g1) {
                cout << 2 << ln;
            }
            else cout << -1 << ln;
        }
        else if (b1s % 2) cout << 1 << ln;
        else cout << 2 << ln;
    }
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
