// Problem: Maximum Subarray Sum II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1644
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

void solve() {
    // -1 3 1 6 9
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n); for (auto& i : v) cin >> i;
    vector<int> k(n + 1, 0);
    int cur = 0, mx = -INF;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        mx = max(mx, cur);
        k[i+1] = cur;
    }
    
    multiset<int> ms;
    
    int ans = -INF;
    for (int i = n; i >= 1; i--) {
        if (i + b <= n) ms.erase(ms.find(k[i+b]));
        if (i + a - 1 <= n) ms.insert(k[i+a-1]);
        
        if (ms.empty()) continue;
    
        int mxe = *ms.rbegin();
        ans = max(ans, mxe - k[i-1]);
        
        // dbg(k[i-1], mxe, ms.size());
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
