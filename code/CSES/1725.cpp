// Problem: Dice Probability
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1725
// Memory Limit: 512 MB
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

ld dp[601][101], sixtothen;
int n,a,b;

ld recurse(int s, int idx) {
    if (idx == n) {
        if (s >= a and s <= b) return (ld)1/sixtothen;
        return 0;
    }
    
    if (dp[s][idx] > -eps) return dp[s][idx];
    ld res = 0;
    for (int i = 1; i <= 6; i++) {
        res += recurse(s+i, idx+1);
    }
    
    return dp[s][idx] = res;
}

void solve() {
    cin >> n >> a >> b;
    fill_n(&dp[0][0], 601*101, -1);
    sixtothen = pow(6, n);
    cout << fixed << setprecision(6) << recurse(0, 0) << ln;
    // ways / 6^n
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
