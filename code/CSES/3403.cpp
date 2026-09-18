// Problem: Longest Common Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3403
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

const int N = 1067;
unordered_map<int, vector<int>> next_x;
int dp[N][N], n, m, a[N], b[N];
pair<int, int> next_p[N][N];

int recurse(int idx_a, int idx_b) {
    if (idx_a == n) return 0;
    
    if (dp[idx_a][idx_b] != -1) return dp[idx_a][idx_b];
    
    int res = 0;
    int A = recurse(idx_a + 1, idx_b);
    int B = -INF;
    auto it = lower_bound(next_x[a[idx_a]].begin(), next_x[a[idx_a]].end(), idx_b);
    if (it != next_x[a[idx_a]].end()) {
        B = recurse(idx_a + 1, *it + 1) + 1;
    }
    
    if (A > B) {
        next_p[idx_a][idx_b] = {idx_a+1, idx_b};
        res = A;
    }
    else {
        next_p[idx_a][idx_b] = {idx_a+1, *it + 1};
        res = B;
    }
    
    return dp[idx_a][idx_b] = res;
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        next_x[b[i]].pb(i);
    }
    
    fill_n(&dp[0][0], N*N, -1);
    fill_n(&next_p[0][0], N*N, make_pair(-1, -1));
    
    int ans = recurse(0, 0);
    cout << ans << ln;
    int x = 0, y = 0;
    while (x != n) {
        auto [nx, ny] = next_p[x][y];
        
        if (y != ny) {
            cout << b[ny-1] << " ";
        }
        
        x = nx;
        y = ny;
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
