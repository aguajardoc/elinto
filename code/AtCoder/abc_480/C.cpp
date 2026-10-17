// Problem: C - Self-Stopping Shower
// Contest: AtCoder - AtCoder Beginner Contest 480
// URL: https://atcoder.jp/contests/abc480/tasks/abc480_c
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
    int n, k, t; cin >> n >> k >> t;
    vector<int> a(n); for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    while (!a.empty() and a.back() > t) a.pop_back();
    a.pb(t);
    n = a.size();
    int ans = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time >= a[i]) {
            time = max(time, a[i] + k);
            // dbg(i, time);
            continue;
        }
        int diff = a[i] - time;
        int extra = diff / k + min(1ll, diff % k);
        ans += extra;
        time = a[i] + k;
        
        // dbg(i, extra, time);
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
