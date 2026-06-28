// Problem: Another Puzzle from Papyrus
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/2238/problem/A
// Memory Limit: 256 MB
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
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    // no sort
    int possNS = true, tNS = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) possNS = false;
        tNS += (a[i] - b[i]);
    }
    
    int possS = true, tS = c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) possS = false;
        tS += a[i] - b[i];
    }
    
    int ans = INF;
    if (possNS) {
        ans = min(ans, tNS);
    }
    if (possS) {
        ans = min(ans, tS);
    }
    
    if (ans == INF) ans = -1;
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
