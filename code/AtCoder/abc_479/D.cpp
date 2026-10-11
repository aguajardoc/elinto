// Problem: D - Back and Forth Distance
// Contest: AtCoder - AtCoder Beginner Contest 479
// URL: https://atcoder.jp/contests/abc479/tasks/abc479_d
// Memory Limit: 1024 MB
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
    int n, q; cin >> n >> q;
    vector<int> l(n+1), r(n+1), pl(n+2, INF), pr(n+1, INF);
    for (int i = 2; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = n; i >= 0; i--) {
        pl[i] = min(pl[i+1], l[i]);
    }
    for (int i = 1; i <= n-1; i++) {
        cin >> r[i];
        pr[i] = min(pr[i-1], r[i]);
    }
    
    while (q--) {
        int s, t; cin >> s >> t;
        
        int ans = INF;
        
        if (s < t) {
            // Go right
            ans = min(ans, r[s]);
            // Go left then right
            if (s > 1)
            ans = min(ans, l[s] + pr[s-1]);
        }
        else {
            ans = min(ans, l[s]);
            if (s < n)
            ans = min(ans, r[s] + pl[s+1]);
        }
        
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
