// Problem: E. Lizard
// Contest: Codeforces - CODEFEM - Mexican Womens Competitive Programming League
// URL: https://codeforces.com/gym/106718/problem/E
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

struct Cat {
    int x, y, f;    
};

struct Hole {
    int x, y;
};

void print(vector<string>& grid, int n, int m) {
    for (auto& i : grid) {
        cout << i << ln;
    }
    cout << ln;
}

void solve() {
    int n, m, k, h, sx, sy;
    cin >> n >> m >> k >> h >> sx >> sy;
    vector<string> grid(n, string(m, '.')); 
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    sx--, sy--;
    vector<Cat> cats(k);
    
    // Store all holes and cats separately
    for (int i = 0; i < k; i++) {
        int x, y, f; cin >> x >> y >> f; x--, y--;
        cats[i] = {x, y, f};
        
        for (int xi = x - f, yi = y, cur = 1; xi <= x; xi++, yi--, cur += 2) {
            if (xi < 0) continue;
            pref[xi][max(0ll, yi)]++;
            pref[xi][min(m, yi+cur)]--;
        }
        
        for (int xi = x, yi = y - f, cur = 2*f + 1; xi <= x + f; xi++, yi++, cur -= 2) {
            if (xi >= n) continue;
            pref[xi][max(0ll, yi)]++;
            pref[xi][min(m, yi+cur)]--;
        }
    }
    
    for (int i = 0; i < h; i++) {
        int x, y; cin >> x >> y; x--, y--;
        grid[x][y] = 'X';
    }
    
    // Rewrite affected cells
    int aff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            aff += pref[i][j];
            if (aff) grid[i][j] = '#';
        }
    }
    
    // print(grid, n, m);
    
    // Traverse new grid accordingly
    queue<pair<int, int>> q;
    if (grid[sx][sy] != '#') {
        q.push({sx, sy});
        dist[sx][sy] = 0;
    }
    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        
        for (auto& [dx, dy] : dir) {
            int nx = u.first + dx;
            int ny = u.second + dy;
            
            if (nx >= n or ny >= m or nx < 0 or ny < 0) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] != INF) continue;
            
            dist[nx][ny] = dist[u.first][u.second] + 1;
            q.push({nx, ny});
        }
    }
    
    int ans = INF;
    pair<int, int> goat = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X' and dist[i][j] < ans) {
                ans = dist[i][j];
                goat = {i+1, j+1};
            }
        }
    }
    
    cout << goat.first << " " << goat.second << ln;
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
