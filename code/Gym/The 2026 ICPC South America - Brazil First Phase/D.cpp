// Problem: D. Dragons in Harmony
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/D
// Memory Limit: 1024 MB
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

vector<string> rotate(int times, vector<string> grid) {
    if (times == 0) {
        return grid;
    }
    
    int n = grid.size(), m = grid[0].size();
    vector<string> grid2(m, string(n, '-')); 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid2[m - j - 1][i] = grid[i][j];
        }
    }
    
    return rotate(times - 1, grid2);
}

vector<string> flip(vector<string> grid) {
    vector<string> grid2 = grid; int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid2[i][j] = grid[n - i - 1][j];
        }
    }
    
    return grid2;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto& i : grid) cin >> i;
    
    int ans = 0;
    if (n == m and rotate(1, grid) == grid) ans++;
    if (rotate(2, grid) == grid) ans++;
    if (n == m and rotate(3, grid) == grid) ans++;
    if (rotate(4, grid) == grid) ans++;
    if (n == m and flip(rotate(1, grid)) == grid) ans++;
    if (flip(rotate(2, grid)) == grid) ans++;
    if (n == m and flip(rotate(3, grid)) == grid) ans++;
    if (flip(rotate(4, grid)) == grid) ans++;
    
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
