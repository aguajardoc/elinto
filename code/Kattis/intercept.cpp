// Problem: Intercept
// Contest: Kattis
// URL: https://open.kattis.com/problems/intercept
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

int n, m, s, t;
vector<vector<pair<int,int>>> DAL, TAL;
vector<vector<int>>  AAL;
vector<int> dist, arti_point, visited, dfs_num, dfs_low, dfs_par;
int timer = 0;

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	
    	if (dist[u] < d) continue;
    	
    	for (auto& [v, w] : DAL[u]) {
    		if (d + w >= dist[v]) continue;
    		
    		dist[v] = d + w;
    		pq.push({dist[v], v});
    	}
    }
}

void create_graph(int u) {
	visited[u] = true;
	for (auto& [v, w] : TAL[u]) {
		// dbg(u, v, w);
		// dbg(dist[u], dist[v]);
		if (dist[v] + w == dist[u]) {
			AAL[v].pb(u);
			AAL[u].pb(v);
			if (visited[v]) continue;
			create_graph(v);
		}
	}
}

void find_art_points(int u) {
	dfs_num[u] = dfs_low[u] = timer++;
	visited[u] = 1;
	
	for (auto& v : AAL[u]) {
		if (visited[v] == 0) {
			dfs_par[v] = u;
			find_art_points(v);
			
			if (dfs_low[v] >= dfs_num[u]) {
				arti_point[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_par[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
	
	visited[u] = 2;
}

void solve() {
    cin >> n >> m;
    DAL.resize(n);
    TAL.resize(n);
    AAL.resize(n);
    dist.assign(n, INF);
    visited.assign(n, 0);
    arti_point.assign(n, 0);
    dfs_num.assign(n, 0);
    dfs_low.assign(n, 0);
    dfs_par.assign(n, 0);
    
    for (int i = 0; i < m; i++) {
    	int u, v, w; cin >> u >> v >> w;
    	DAL[u].pb({v, w});
    	TAL[v].pb({u, w});
    }
    
    cin >> s >> t;
    
    dijkstra(s);
    create_graph(t);
    
    visited.assign(n, 0);
    arti_point[s] = arti_point[t] = 1;
    find_art_points(s);
    
    for (int u = 0; u < n; u++) {
    	if (arti_point[u]) cout << u << " ";
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
