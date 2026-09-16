// Problem: B. Bridges of Koninsberg ii
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico Repechaje
// URL: https://codeforces.com/gym/106710/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

const int MAXN = 755;
int AM[MAXN][MAXN], d[MAXN][MAXN];

void solve() {
    int n; cin >> n;
    fill_n(&AM[0][0], MAXN*MAXN, -1);
    fill_n(&d[0][0], MAXN*MAXN, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> AM[i][j];
            if (AM[i][j] < 0) AM[i][j] = -INF;
        }
    }
    
    int m; cin >> m;
    for (int a = 0; a < m; a++) {
        int i, j, x, y, k; cin >> i >> j >> x >> y >> k;
        
        for (int b = min(i, x); b <= max(i, x); b++) {
            d[b][min(j, y)] += k;
            d[b][max(j, y) + 1] -= k;
        }
    }
    
    int cur = 0;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            cur += d[i][j];
            AM[i][j] += cur;
            
            if (AM[i][j] < 0) AM[i][j] = INF;
            if (i == j) AM[i][i] = 0;
        }
    }
    
    for (int k = 1; k < MAXN; k++) {
        for (int i = 1; i < MAXN; i++) {
            for (int j = 1; j < MAXN; j++) {
                AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
            }
        }
    }
    
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        int res = AM[a][b];
        if (res >= 1e17) res = -1;
        
        cout << res << ln;
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
