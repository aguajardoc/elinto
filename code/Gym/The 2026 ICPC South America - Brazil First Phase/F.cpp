// Problem: F. Flower
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/F
// Memory Limit: 1024 MB
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

int findInLoop(int F0, int F1, int n) {
    if (F0 == n) return F1;
    
    int F2 = 3 * F0, F3 = 3 * F1;
    while (true) {
        F2 = 3 * F0;
        F3 = 3 * F1;
        
        if (F0 == n) return F1;
        if (F1 == n) return F2;
        if (F2 == n) return F3;
        
        F0 = F2;
        F1 = F3;
    }
    
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> pow3 = {1, 3};
    while (pow3.back() <= 3.67e7) {
        pow3.pb(pow3.back() * 3);
    }
    
    int fn = n;
    while (fn % 3 == 0) fn /= 3;
    
    int idx = upper_bound(pow3.begin(), pow3.end(), fn) - pow3.begin();
    
    int L = pow3[idx-1], R = pow3[idx];
    int half = (L + R) / 2;
    
    // cout << n << " ";
    if (fn == half) cout << findInLoop(1, 2, n) << ln;
    else if (fn < half) cout << findInLoop(fn, fn + L, n) << ln;
    else cout << findInLoop(fn - L, fn, n) << ln;
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
