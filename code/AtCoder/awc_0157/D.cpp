// Problem: D - Network Construction
// Contest: AtCoder - AtCoder Weekday Contest 0157 Beta
// URL: https://atcoder.jp/contests/awc0157/tasks/awc0157_d
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
    int n, m; cin >> n >> m;
    vector<int> a(n), l(m); for (auto& i : a) cin >> i;
    for (auto& i : l) cin >> i;
    sort(a.begin(), a.end());
    sort(l.begin(), l.end());
    
    bool poss = true;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        while (idx < l.size() and a[0] + a[i] > l[idx]) idx++;
        if (idx == m) poss = false;
        else idx++;
    }
    
    cout << (poss ? "Yes":"No") << ln;
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
