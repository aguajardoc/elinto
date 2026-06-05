// Problem: F. Frangolino ali na mesa
// Contest: Codeforces - The 2025 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106073/problem/F
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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

ll binexp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b&1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(q), ans(100001, 0);
    for (auto& i : a) cin >> i;
    int inv2 = binexp(2, MOD - 2);
    if (q == 1) {
        ll ans = a[0] * inv2;
        ans %= MOD;
        
        cout << ans << ln;
        for (int i = 2; i <= n; i++) {
            cout << 0 << ln;
        }
        return;
    }
    
    int sum = 0;
    int pow = binexp(2, q - 2);
    for (int i = 1; i < q; i++) {
        sum += a[i] * pow;
        sum %= MOD;
        
        pow *= inv2;
        pow %= MOD;
    }
    
    int pf = binexp(2, q - 1);
    ans[1] += (sum) % MOD + (pf * a[0]) % MOD;
    ans[1] %= MOD;
    pow = binexp(2, q - 2);
    
    for (int i = 0; i < q - 1; i++) {
        // dbg(sum, pow);¨
        ans[a[i]] += sum;
        ans[a[i]] %= MOD;
        
        sum -= a[i+1] * pow;
        sum = ((sum % MOD) + MOD) % MOD;
        sum *= 2;
        sum %= MOD;
    }
    
    ll den = binexp(binexp(2, q), MOD - 2);
    
    for (int i = 1; i <= n; i++) {
        // dbg(ans[i]);
        ll res = ans[i] * den;
        res %= MOD;
        
        cout << res << ln;
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
