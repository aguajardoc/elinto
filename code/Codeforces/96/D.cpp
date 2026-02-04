// Problem: D. Volleyball
// Contest: Codeforces - Codeforces Beta Round 77 (Div. 2 Only)
// URL: https://codeforces.com/contest/96/problem/D
// Memory Limit: 256 MB
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

struct Edge {
	int v, w;
};

struct Vertex {
	int t, c;
};

void solve() {
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	x--, y--;
	
	vector<Vertex> taxis(n);
	vector<vector<Edge>> AL(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		AL[u].pb({v, w});
		AL[v].pb({u, w});
	}
	for (int i = 0; i < n; i++) {
		int t, c;
		cin >> t >> c;
		taxis[i] = {t, c};
	}
	
	vector<vector<int>> dist(n + 1, vector<int> (n + 1, INF));
	
	// Distance dijkstra for new AL
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		// Dijkstra
		
		pq.push({0, i});
		dist[i][i] = 0;
		
		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();
			

			if (d > dist[i][u]) continue;
			
			for (auto& [v, w] : AL[u]) {
				if (d + w >= dist[i][v]) continue;
				
				dist[i][v] = d + w;
				pq.push({dist[i][v], v});
			}
		}
	}
	
	// taxi based AL
	vector<vector<Edge>> TAL(n);
	for (int i = 0; i < n; i++) {
		// Current junction can only reach those with d < t
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			
			if (dist[i][j] <= taxis[i].t) {
				TAL[i].pb({j, taxis[i].c});
			}
		}
	}
	
	// New dijkstra
	vector<int> fd(n + 1, INF);
	fd[x] = 0;
	// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, x});
	
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		
		if (d > fd[u]) continue;
		
		for (auto& [v, w] : TAL[u]) {
			if (d + w >= fd[v]) continue;
			
			fd[v] = d + w;
			pq.push({fd[v], v});
		}
	}
	
	cout << (fd[y] == INF ? -1:fd[y]) << ln;
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
