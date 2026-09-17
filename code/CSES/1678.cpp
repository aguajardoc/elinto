// Problem: Round Trip II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1678
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

const int N = 1e5 + 1;

vector<vector<int>> AL;
vector<int> visited, par;
int start = -1, last = -1;

void dfs(int u) {
    visited[u] = 1;
    
    for (auto& v : AL[u]) {
        if (visited[v] == 2) continue;
        else if (visited[v] == 0) {
            par[v] = u;
            dfs(v);
        }
        else {
            start = v;
            last = u;
            continue;
        }
    }
    
    visited[u] = 2;
}

void solve() {
    int n, m; cin >> n >> m;
    AL.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);
    par.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u,v; cin >>u >> v;
        AL[u].pb(v);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    
    if (start == -1) {
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    
    vector<int> path;
    int cur = last;
    while (cur != start) {
        path.pb(cur);
        cur = par[cur];
    }
    path.pb(start);
    path.pb(last);
    reverse(path.begin(), path.end());
    
    cout << path.size() << ln;
    for (auto& i : path) {
        cout << i << " ";
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
