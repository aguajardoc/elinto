// Problem: Mail Delivery
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1691
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

vector<int> path, visited, deg;
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
    int n, m; cin >> n >> m;
    visited.assign(m, 0);
    deg.assign(n, 0);
    AL.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        AL[u].pb({v, i});
        AL[v].pb({u, i});
        
        deg[u]++;
        deg[v]++;
    }
    
    for (auto& i : deg) {
        if (i % 2) {
            cout << "IMPOSSIBLE" << ln;
            return;
        }
    }
    
    dfs(0);
    
    if (path.size() == m + 1) {
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
