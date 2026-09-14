// Problem: C. Madamant's Skating Dynasty
// Contest: Codeforces - Codeforces Round 1121 (Div. 2)
// URL: https://codeforces.com/contest/2264/problem/C
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
const int MOD = 998244353;
const double eps = 1e-9;

int fac[300001];

ll binexp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) {
            res = (res * a) % MOD;
        }
        a = (a*a) % MOD;
        b >>= 1;
    }
    
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i; sort(a.begin(), a.end());
    
    int ans = 0;
    int sbase = 0;
    for (int i = 1; i < n; i++) {
        sbase += a[i] - a[0];
        sbase %= MOD;
    }
    
    int k = fac[n-1];
    
    ans += (((k * binexp(n-1, MOD - 2)) % MOD) * (sbase)) % MOD;
    ans %= MOD;
    
    for (int i = 1; i < n; i++) {
        sbase -= (n - i) * (a[i] - a[i-1]);
        sbase = ((sbase % MOD) + MOD) % MOD;
        
        ans += (((k * binexp(n-i-1, MOD - 2)) % MOD) * (sbase)) % MOD;
        ans %= MOD;
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 300000; i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
