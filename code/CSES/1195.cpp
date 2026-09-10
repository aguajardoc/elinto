// Problem: Flight Discount
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1195
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

struct State {
    int d, used, u;
    
    bool operator>(const auto& oth) const {
        return d > oth.d;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> AL(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
        AL[u].pb({v, w});
    }
    
    priority_queue<
        State, 
        vector<State>, 
        greater<State>
    > pq;
    
    pq.push({0, 0, 0});
    vector<vector<int>> cost(2, vector<int> (n, INF));
    cost[0][0] = 0;
    
    while (!pq.empty()) {
        State S = pq.top();
        pq.pop();
        
        if (S.d > cost[S.used][S.u]) continue;
        
        for (auto& [v, w] : AL[S.u]) {
            // Do not half
            if (S.d + w < cost[S.used][v]) {
                cost[S.used][v] = S.d + w;
                pq.push({cost[S.used][v], S.used, v});
            }
            
            // Half if possible
            if (!S.used and S.d + w/2 < cost[1][v]) {
                cost[1][v] = S.d + w/2;
                pq.push({cost[1][v], 1, v});
            }
        }
    }
    
    cout << min(cost[0][n-1], cost[1][n-1]) << ln;
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
