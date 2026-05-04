// Problem: D - Shortest Evacuation Route
// Contest: AtCoder - AtCoder Weekday Contest 0051 Beta
// URL: https://atcoder.jp/contests/awc0051/tasks/awc0051_d
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
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    
    vector<vector<pair<int, int>>> AL(n + 1);
    vector<int> affected(n + 1, 0);
    vector<vector<int>> EL(m);
    
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	EL[i] = {u, v, w};
    }
    
    for (int i = 0; i < k; i++) {
    	int x;
    	cin >> x;
    	affected[x] = 1;
    }
    
    
    AL[0].pb({1, affected[1] * t});
    
    for (int i = 0; i < m; i++) {
    	int u = EL[i][0];
    	int v = EL[i][1];
    	int w = EL[i][2];
    	
    	AL[u].pb({v, w + affected[v] * t});
    	AL[v].pb({u, w + affected[u] * t});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
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
    
    cout << dist[n] << ln;
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
