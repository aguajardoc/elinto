// Problem: E - Roads and Gates
// Contest: AtCoder - AtCoder Beginner Contest 463
// URL: https://atcoder.jp/contests/abc463/tasks/abc463_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

void solve() {
    // add an extra node, then dupe everything
    int n, m,y;
    cin >> n >> m >> y;
    y *= 2;
    vector<vector<pair<int, int>>> AL(n + 2);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--, w *= 2;
        AL[u].pb({v, w});
        AL[v].pb({u, w});
    }
    vector<int> X(n);
    for (auto& i : X) cin >> i;
    for (auto& i : X) i <<= 1;
    
    
    for (int i = 0; i < n; i++) {
        AL[i].pb({n, y / 2 + X[i]});
        AL[n].pb({i, y / 2 + X[i]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 2, INF);
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, w] : AL[u]) {
            if (d + w >= dist[v]) continue;
            
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
    
    for (int i = 1; i < n; i++) {
        cout << dist[i] / 2 << " ";
    }
    cout << ln;
    
    
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
