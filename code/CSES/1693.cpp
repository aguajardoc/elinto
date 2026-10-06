// Problem: Teleporters Path
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1693
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

vector<int> indeg, outdeg, visited, path;
vector<vector<pair<int, int>>> AL;

void dfs(int u) {
    while (!AL[u].empty()) {
        auto [v, i] = AL[u].back();
        AL[u].pop_back();
        if (visited[i]) continue;
        visited[i] = true;
        dfs(v);
    }
    
    path.pb(u);
}

void solve() {
    // works if indegree == outdegree for all
    // or one node has one larger indegree, other has outdegree lower
    int n, m; cin >> n >> m;
    
    AL.resize(n);
    visited.assign(m, 0);
    outdeg.assign(n, 0);
    indeg.assign(n, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        AL[u].pb({v, i});
        
        outdeg[u]++;
        indeg[v]++;
    }
    
    int onel = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == outdeg[i]) continue;
        if (indeg[i] == outdeg[i] + 1) onel++;
        else if (indeg[i] == outdeg[i] - 1) ones++;
        else onel = 1e9;
    }
    
    if (!((onel == 0 and ones == 0) or (onel == 1 and ones == 1))) {
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    
    dfs(0);
    reverse(path.begin(), path.end());
    if (path.size() == m + 1 and path.front() == 0 and path.back() == n - 1) {
        for (auto& i : path) {
            cout << i + 1 << " ";
        }
    }
    else cout << "IMPOSSIBLE" << ln;
    
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
