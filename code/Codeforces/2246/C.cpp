// Problem: C. 0mar and Alternating Sums
// Contest: Codeforces - Codeforces Round 1108 (Div. 2)
// URL: https://codeforces.com/contest/2246/problem/C
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

vector<int> fac = {1, 1};

int binexp(int a, int b) {
    int res = 1;
    while(b) {
        if (b& 1) {
            res = (a* res) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int ncr(int n, int r) {
    int num = fac[n];
    int den = fac[n - r] * fac[r];
    den %=  MOD;
    
    int res = num * binexp(den, MOD - 2);
    res %= MOD;
    
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> ct;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (nums.empty() or x != nums.back()) {
            nums.pb(x);
            ct.pb(1);
        }
        else ct.back()++;
    }
    
    int m = nums.size();
    vector<int> even(m), odd(m);
    
    for (int i = 0; i < m; i++) {
        // dbg(nums[i]);
        for (int j = 0; j <= ct[i]; j++) {
            int res = ncr(ct[i], j);
            
            // dbg(j, res);
            if(j % 2) {
                odd[i] += res;
                odd[i] %= MOD;
            }
            else {
                even[i] += res;
                even[i] %= MOD;
            }
        }
    }
    
    // for (int i = 0; i < m; i++) {
        // cout << odd[i] << " " << even[i] << ln;
    // }
    
    int ans = 1;
    
    // pct
    for (int i = 0; i < m; i++) {
        ans *= even[i];
        ans %= MOD;
    }
    
    // nct
    if (nums[0] == -1) {
        // need prefix ugh
        int tot = 1;
        vector<int> evenSuff(m);
        for (int i = m-1; i >= 0; i--) {
            tot *= even[i];
            tot %= MOD;
            
            evenSuff[i] = tot;
        }
        
        int nct = odd[0];
        tot *= binexp(even[0], MOD - 2);
        tot %= MOD;
        
        int secondary = 0;
        int running = 1;
        for (int i = 1; i < m - 1; i++) {
            
            int local = 1;
            // add running
            local *= running;
            local %= MOD;
            
            // upd running
            running *= even[i];
            running %= MOD;
            
            // odd this and next
            local *= odd[i];
            local %= MOD;
            local *= odd[i+1];
            local %= MOD;
            
            // even of all next
            if (i + 2 < m)local *= evenSuff[i + 2];
            local %= MOD;
            
            if (nums[i] != nums[i+1] - 1) continue;
            secondary += local;
            secondary %= MOD;
            
            // dbg(i, local);
            // dbg(nums[i], nums[i+1]);
            // dbg(odd[i], odd[i+1]);
        }
        
        nct *= secondary;
        nct %= MOD;
        
        // dbg(ans, nct);
        
        ans += nct;
        ans %= MOD;
    }
    
    cout << ans << ln;
    // cout << ln;
}

signed main() {
    fast_cin();
    
    for (int i = 2; i <= 300000; i++) {
        fac.pb(fac.back() * i);
        fac.back() %= MOD;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
