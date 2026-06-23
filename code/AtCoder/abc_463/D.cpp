// Problem: D - Maximize the Gap
// Contest: AtCoder - AtCoder Beginner Contest 463
// URL: https://atcoder.jp/contests/abc463/tasks/abc463_d
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

bool f(vector<pair<int, int>>& valid, int x, int k) {
    int cur = 0;
    vector<pair<int, int>> newv;
    for (int i = 0; i < valid.size(); i++) {
        if (newv.empty() or newv.back().second + x - 1 < valid[i].first) {
            newv.pb(valid[i]);
        }
    }
    
    return (newv.size() >= k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    
    for (int i= 0; i < n; i++) {
        int l,r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    #define l first
    #define r second
    sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
        if (a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });
    
    int l = 1, r = INF;
    
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        
        int fm = f(a, m, k);
        
        if (fm) {
            ans = max(ans, m);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    
    cout << ans << ln;
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
