// Problem: J. Jumping Reaction
// Contest: Codeforces - 2023 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/696886/problem/J
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> rolling_sum(n, 0), sof(n+1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        sum %= MOD;
        sof[i+1] = sum;
        sof[i+1] %= MOD;
        
        rolling_sum[i] = a[i] * sum;
        rolling_sum[i] %= MOD;
    }

    
    vector<int> RP(n + 1, 0), allall(n + 1, 0);
    for (int i = 0; i < n; i++) {       
        allall[i+1] = allall[i] + sum * a[i];
        allall[i+1] %= MOD;
        
        RP[i+1] = RP[i] + rolling_sum[i];
        RP[i+1] %= MOD;
    }
    
    int base = (sum * sum) % MOD;
    
    for (int i = 0; i < q; i++) {
        int L, R; cin >> L >> R;
        if (L == R) {
            cout << a[L-1] << ln;
            continue;
        }
        
        int LHS = sof[n] - sof[R];
        LHS %= MOD;
        
        int RHS = sof[R-1] - sof[L-1];
        RHS %= MOD;
        
        int res = LHS * RHS;
        res %= MOD;
        
        int ans = base;
        ans += RP[L-1];
        ans += allall[R-1];
        ans -= RP[R-1];
        ans -= allall[n];
        ans -= allall[L-1];
        ans -= res;
        ans = ((ans % MOD) + MOD) % MOD;
        
        cout << ans << ln;
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
