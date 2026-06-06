// Problem: C. Square Subsets
// Contest: Codeforces - Codeforces Round 448 (Div. 2)
// URL: https://codeforces.com/contest/895/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    while (b) {
        if (b&1) {
            res = (res * a) % MOD;
        }
        
        a = (a * a) % MOD;
        b >>= 1;
    }
    
    return res;
}

vector<int> p;
int dp[2][1 << 19];

void solve() {
    int n;
    cin >> n;
    vector<int> mask(71, 0), ct(71, 0);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x; ct[x]++;
    }
    
    for (int i = 1; i <= 70; i++) {
        int x = i;
        
        int M = 0;
        for (int j = 0; j < p.size() and p[j] * p[j] <= x; j++) {
            while (x % p[j] == 0) {
                M ^= (1ll << j);
                x /= p[j];
            }
        }
        
        if (x > 1) {
            M ^= (1ll << (lower_bound(p.begin(), p.end(), x) - p.begin()));
        }
        
        mask[i] = M;
    }
    
    
    fill_n(&dp[0][0], 2ll * (1ll << 19), 0);
    dp[0][0] = 1;
    
    for (int i = 1; i <= 70; i++) {
        int now = i % 2;
        int last = 1 - now;
        
        if (!ct[i]) {
            for (int j = 0; j < (1ll << 19); j++) {
                dp[now][j] = dp[last][j];
            }
            
            fill_n(&dp[last][0], (1ll << 19), 0);
            continue;
            
        }
        
        int ways = binexp(2, ct[i] - 1);
        int M = mask[i];
        
        for (int j = 0; j < (1ll << 19); j++) {
            dp[now][j] = (dp[last][j] * ways) % MOD + 
                        (dp[last][j^M] * ways) % MOD;
            dp[now][j] %= MOD;
        }
        
        fill_n(&dp[last][0], (1ll << 19), 0);
    }
    
    cout << (dp[0][0] - 1 + MOD) % MOD << ln;
}

signed main() {
    fast_cin();
    
    for (int i = 2; i <= 70; i++) {
        bool poss = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) poss = false;
        }
        
        if (poss) p.pb(i);
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
