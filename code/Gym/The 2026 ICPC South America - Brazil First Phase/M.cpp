// Problem: M. Microwave
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/M
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct State {
    ll d;
    int mlinks, u;
    bool operator>(const auto& oth) const {
        return d > oth.d;
    }
};

struct Link {
    int v, w, type;  
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<Link>> AL(n);
    priority_queue<
        State,
        vector<State>,
        greater<State>
    > pq;
    
    for (int i = 0; i < m; i++) {
        int u, v, w, m;
        cin >> u >> v >> w >> m; u--, v--;
        AL[u].pb({v, w, 0});
        AL[v].pb({u, w, 0});
        
        if (m != -1) {
            AL[u].pb({v, m, 1});
            AL[v].pb({u, m, 1});
        }
    }
    
    pq.push({0, 0, 0});
    vector<vector<ll>> dist(k + 1, vector<ll> (n, INF));
    dist[0][0] = 0;
    
    while (!pq.empty()) {
        State S = pq.top();
        pq.pop();
        
        if (S.d > dist[S.mlinks][S.u]) continue;
        
        for (auto& v : AL[S.u]) {
            if (S.mlinks + v.type > k) continue;
            if (S.d + (ll)v.w < dist[S.mlinks+v.type][v.v]) {
                dist[S.mlinks+v.type][v.v] = S.d + (ll)v.w;
                pq.push({dist[S.mlinks+v.type][v.v], S.mlinks + v.type, v.v});
            }
        }
    }
    
    ll ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[i][n-1]);
    }
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
