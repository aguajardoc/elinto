// Problem: Knight's Tour
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1689
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
const int N = 8;

int visited[N][N], ans[N][N];
pair<int, int> par[N][N];
vector<pair<int, int>> dir = {
    {-2, -1}, {-2, 1},
    {2, -1}, {2, 1},
    {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}
};

void build_ans(int x, int y) {
    int ct = 64;
    while (x != -1 and y != -1) {
        ans[x][y] = ct--;
        tie(x, y) = par[x][y];
    }
}

bool valid(int x, int y) {
    return (x < N and x >= 0 and y < N and y >= 0);
}

int get_degree(int x, int y) {
    int d = 0;
    for (auto& [dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        
        if (valid(nx, ny) and !visited[nx][ny]) d++;
    }
    
    return d;
}


bool recurse(int x, int y, int& ct) {
    if (ct == 64) {
        build_ans(x, y);
        return true;
    }
    
    bool res = false;
    vector<pair<int, pair<int, int>>> candidates;
    for (auto& [dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        
        if (valid(nx, ny) and !visited[nx][ny]) {
            candidates.push_back({get_degree(nx, ny), {nx, ny}});
        }
    }
    
    sort(candidates.begin(), candidates.end());
    for (auto& [d, node] : candidates) {
        ct++;
        visited[node.first][node.second] = 1;
        par[node.first][node.second] = {x, y};
        res |= recurse(node.first, node.second, ct);
        if (res) return true;
        
        ct--;
        visited[node.first][node.second] = 0;
        par[node.first][node.second] = {-1, -1};
    }
    
    return res;
}

void init() {
    fill_n(&visited[0][0], N * N, 0);
    fill_n(&ans[0][0], N * N, 0);
    fill_n(&par[0][0], N * N, make_pair(-1, -1));
}


void solve() {
    init();
    int x, y, ct = 1;
    cin >> x >> y;
    x--, y--;
    visited[y][x] = 1;
    recurse(y, x, ct);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << ln;
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
