// Problem: E. Carrying One Badge
// Contest: Codeforces - ICPC Masters Mexico 2026
// URL: https://codeforces.com/gym/106646/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct State {
    int x, y, holding, open;
    bool operator < (const auto& oth) const {
        return x < oth.x;
    }
};

int dist[51][51][11][257];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n);
    pair<int, int> S, T;
    int color_map[128];
    fill_n(&color_map[0], 128, -1);
    int colors = 0;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') S = {i, j};
            else if (grid[i][j] == 'T') T = {i, j};
            else if (grid[i][j] != '.' and grid[i][j] != '#' and color_map[tolower(grid[i][j])] == -1) {
                color_map[tolower(grid[i][j])] = colors++;
            }
        }
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    fill_n(&dist[0][0][0][0], 51*51*11*257, INF);

    dist[S.first][S.second][k][0] = 0;
    queue<State> q;
    q.push({S.first, S.second, k, 0});
    
    while (!q.empty()) {
        State u = q.front();
        // dbg(u.x, u.y, u.holding, u.open);
        q.pop();
        
        for (auto& [dx, dy] : dir) {
            int nx = u.x + dx;
            int ny = u.y + dy;
            int nh = u.holding;
            int no = u.open;
            if (nx >= n or ny >= m or nx < 0 or ny < 0) continue;
            if (grid[nx][ny] == '#') continue;
            int bit = color_map[tolower(grid[nx][ny])];
            
            // dbg(u.holding);
            // dbg(nx, ny, bit);
            
            if (bit != -1) {
                if (isupper(grid[nx][ny])) {
                    if (u.holding == bit and !(u.open & (1 << bit))) {
                        // Uses held badge on door
                        nh = k; // reset
                        no |= (1 << bit);
                        State nu = {nx, ny, nh, no};
                    
                        if (dist[nx][ny][nh][no] == INF) {
                            dist[nx][ny][nh][no] = dist[u.x][u.y][u.holding][u.open] + 1;
                            q.push(nu);
                        }
                    }
                    else if ((u.open & (1 << bit))) {
                        // Nothing happens, we can go on tho
                        State nu = {nx, ny, nh, no};
                    
                        if (dist[nx][ny][nh][no] == INF) {
                            dist[nx][ny][nh][no] = dist[u.x][u.y][u.holding][u.open] + 1;
                            q.push(nu);
                        }
                    }
                    else {
                        // no way to open it :(
                        continue;
                    }
                }
                else if (islower(grid[nx][ny])) {
                    // Can decide to take this badge or not
                    State nu = {nx, ny, nh, no};
                    // not
                    if (dist[nx][ny][nh][no] == INF) {
                        dist[nx][ny][nh][no] = dist[u.x][u.y][u.holding][u.open] + 1;
                        q.push(nu);
                    }
                    // do
                    nh = bit;
                    nu.holding = nh;
                    if (dist[nx][ny][nh][no] == INF) {
                        dist[nx][ny][nh][no] = dist[u.x][u.y][u.holding][u.open] + 1;
                        q.push(nu);
                    }
                }
                else continue;
            }
            else {
                // Empty cell
                State nu = {nx, ny, nh, no};
            
                if (dist[nx][ny][nh][no] == INF) {
                    dist[nx][ny][nh][no] = dist[u.x][u.y][u.holding][u.open] + 1;
                    q.push(nu);
                }
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j <= k; j++) {
            ans = min(ans, dist[T.first][T.second][j][i]);
        }
    }
    
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
