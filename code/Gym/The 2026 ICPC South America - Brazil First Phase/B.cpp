// Problem: B. Sequences
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1500 ms
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

struct Range {
    int l, r;
};

int n, m;
vector<Range> blocks, intervals;
int dp[606][303], binom[606][303], inv[303];

int binexp(int a, int b) {
    ll res = 1;
    while(b) {
        if(b&1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    
    return res;
}

void precalc() {
    int cur = 1;
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= 300; i++) {
        cur *= i;
        cur %= MOD;
        inv[i] = binexp(cur, MOD - 2);
    }
    
    for (int i = 0; i < m; i++) {
        int MIC = blocks[i].r - blocks[i].l + 1;
        int num = 1;
        binom[i][0] = 1;
        
        for (int k = 1; k <= min(MIC, 300ll); k++) {
            num *= (MIC - k + 1);
            num %= MOD;
            
            int res = num * inv[k];
            res %= MOD;
            binom[i][k] = res;
        }
    }
}

int recurse(int b_idx, int i_idx) {
    if (i_idx == n) {
        return 1;
    }
    if (b_idx == m) {
        return 0;
    }
    
    if (dp[b_idx][i_idx] != -1) return dp[b_idx][i_idx];
    
    int res = recurse(b_idx+1, i_idx);
    int L = blocks[b_idx].l;
    int R = blocks[b_idx].r;
    int MIC = R - L + 1;
    
    for (int k = 1; k <= MIC and i_idx + k <= n; k++) {
        int iL = intervals[i_idx+k-1].l;
        int iR = intervals[i_idx+k-1].r;
        if (iL <= L and iR >= R) {
            res += (binom[b_idx][k] * recurse(b_idx+1, i_idx+k)) % MOD;
            res %= MOD;
        }
        else break;
    }
    
    return dp[b_idx][i_idx] = res;
}

void solve() {
    cin >> n;
    vector<int> ep;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.pb({l, r});
        ep.pb(l); ep.pb(r+1);
    }
    
    sort(ep.begin(), ep.end());
    ep.resize(unique(ep.begin(), ep.end()) - ep.begin());
    
    for (int i = 0; i < (int)ep.size() - 1; i++) {
        blocks.pb({ep[i], ep[i+1]-1});
    }
    
    fill_n(&dp[0][0], 606*303, -1);
    m = blocks.size();
    precalc();
    cout << recurse(0, 0) << ln;
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
