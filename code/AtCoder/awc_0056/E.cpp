// Problem: E - Delivery Driver's Route
// Contest: AtCoder - AtCoder Weekday Contest 0056 Beta
// URL: https://atcoder.jp/contests/awc0056/tasks/awc0056_e
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
vector<vector<pair<int, int>>> AL;

vector<int> dijkstra(int source) {
	int n = AL.size();
	vector<int> dist(n, INF);
	dist[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, source});
	
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
	
	return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    AL.resize(n);
    
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({v, w});
    	AL[v].pb({u, w});
    }
    
    int s, k;
    cin >> s >> k;
    s--;
    vector<int> d(k);
    for (auto& i : d) {
    	cin >> i;
    	i--;
    }
    
    vector<vector<int>> dist(k + 1);
    for (int i = 0; i < k; i++) {
    	dist[i] = dijkstra(d[i]);
    }
    dist.back() = dijkstra(s);
    
    d.pb(s);
    
    int nk = k + 1;
    
    vector<vector<int>> dp(1 << nk, vector<int> (nk, INF));
    dp[1ll << k][k] = 0;
    
    for (int i = 0; i < (1 << nk); i++) {
    	for (int u = 0; u < nk; u++) {
    		if (!(i & (1ll << u)) or dp[i][u] == INF) continue;
    		
    		for (int v = 0; v < nk; v++) {
    			if ((i & (1ll << v))) continue;
    			
    			int nx = i | (1ll << v);
    			
    			dp[nx][v] = min(
    				dp[nx][v],
    				dp[i][u] + dist[u][d[v]]
    			);
    		}
    	}
    }
    
    int ans = INF;
    
    for (int u = 0; u < k; u++) {
    	ans = min(
    		ans,
    		dp[(1ll << nk) - 1][u] + dist[u][s]
    	);
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
