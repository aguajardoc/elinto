// Problem: Graph Paths II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1724
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

const int N = 100;
using Matrix = array<array<int, N>, N>;

Matrix mult(Matrix a, Matrix b) {
    Matrix res; for (auto& i : res) for (auto& j : i) j = INF;
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (a[i][k] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (b[k][j] == INF) continue;
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    
    return res;
}

Matrix binexp(Matrix a, int b) {
    Matrix res; 
    for (auto& i : res) for (auto& j : i) j = INF;
    for (int i = 0; i < N; i++) res[i][i] = 0;
    
    while(b) {
        if(b&1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        
        b >>= 1;
    }
    
    return res;
}

void print(Matrix& a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << ln;
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    Matrix AM; for (auto& i : AM) for (auto& j : i) j = INF;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        AM[u][v] = AM[u][v] == INF ? w:min(AM[u][v], w);
    }
    
    Matrix res = binexp(AM, k);
    
    // print(res, n);
    
    int ans = res[0][n-1];
    if (ans == INF) ans = -1;
    
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
