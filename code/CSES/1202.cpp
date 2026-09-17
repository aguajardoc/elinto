// Problem: Investigation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1202
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

const int N = 100001;
int n, m, dp_min[N], dp_max[N], dist[N], ways[N];
vector<vector<pair<int, int>>> AL;

void solve() {
    cin >> n >> m;
    AL.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].pb({v, w});
    }
    
    fill_n(&ways[0], N, 0); ways[1] = 1;
    fill_n(&dist[0], N, INF); dist[1] = 0;
    fill_n(&dp_min[0], N, INF); dp_min[1] = 0;
    fill_n(&dp_max[0], N, -INF); dp_max[1] = 0;
    
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, w] : AL[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                ways[v] = ways[u];
                dp_min[v] = dp_min[u] + 1;
                dp_max[v] = dp_max[u] + 1;
                
                pq.push({dist[v], v});
            }
            else if (d + w == dist[v]) {
                ways[v] += ways[u];
                ways[v] %= MOD;
                dp_min[v] = min(dp_min[v], dp_min[u] + 1);
                dp_max[v] = max(dp_max[v], dp_max[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << ways[n] << " ";
    cout << dp_min[n] << " " << dp_max[n] << ln;
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
