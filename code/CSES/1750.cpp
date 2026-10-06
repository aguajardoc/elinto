// Problem: Planets Queries I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1750
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
    int n, q; cin >> n >> q;
    vector<vector<int>> up(32, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
    }
    
    for (int i = 1; i <= 31; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
    
    while (q--) {
        int u, k; cin >> u >> k;
        int it = 0;
        while(k) {
            if (k&1) {
                u = up[it][u];
            }
            
            it++;
            k >>= 1;
        }
        
        cout << u << ln;
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
