// Problem: Cycle Finding
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1197
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

struct Edge {
    int u,v,w;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> EL(m);
    for (auto& i : EL) {
        cin >> i.u >> i.v >> i.w;
    }
    
    vector<int> dist(n + 1, INF), par(n + 1, -1); int x;
    dist[0] = 0;
    for (int i = 0; i < n; i ++) {
        x = -1;
        for (auto& e : EL) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                x = e.v;
                par[e.v] = e.u;
            }
        }
    }
    
    if (x == -1) cout << "NO" << ln;
    else {
        int y = x;
        for (int i = 0; i < n; i++) y = par[y];
        
        vector<int> path = {y};
        int cur = y;
        while (path.size() < 2 or cur != y) {
            cur = par[cur];
            path.pb(cur);
        }
        reverse(path.begin(), path.end());
        
        cout << "YES" << ln;
        for (auto& i : path) {
            cout << i << " ";
        }
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
