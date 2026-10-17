// Problem: F. Escaping the Sun
// Contest: Codeforces - I Maratona Nordestina de Programação — 1st Northeastern Brazil Programming Contest
// URL: https://codeforces.com/gym/106667/problem/F
// Memory Limit: 1024 MB
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

vector<vector<pair<int, ld>>> AL;

struct Umbrella {
    int x, y, r;
};

void solve() {
    int n, H;
    cin >> n >> H;
    
    AL.resize(n + 2);
    
    int sea = 0, shore = n + 1;
    AL[sea].pb({shore, H});
    AL[shore].pb({sea, H});
    vector<Umbrella> a(n + 2);
    for (int i = 1; i <= n; i++) {
        int x, y, r; cin >> x >> y >> r;
        a[i] = {x, y, r};
        
        // Sea to umbrella
        AL[sea].pb({i, max(0ll, (y - r))});
        AL[i].pb({sea, max(0ll, (y - r))});
        
        // Umbrella to shore
        AL[i].pb({shore, max(0ll, (H - (y + r)))});
        AL[shore].pb({i, max(0ll, (H - (y + r)))});
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ld d = hypotl((a[i].x-a[j].x), (a[i].y-a[j].y));
            // dbg(i, j, d);
            ld w = max((ld)0, d - a[i].r - a[j].r);
            AL[i].pb({j, w});
            AL[j].pb({i, w});
        }
    }
    
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;
    pq.push({0, sea});
    vector<ld> dist(shore + 1, INF);
    dist[sea] = 0;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, w] : AL[u]) {
            if (d + w + eps >= dist[v]) continue;
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
    
    cout << fixed << setprecision(10) << dist[shore] << ln;
    
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