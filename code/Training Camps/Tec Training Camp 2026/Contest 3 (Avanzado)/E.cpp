// Problem: E. Moving Both Hands
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/E
// Memory Limit: 256 MB
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> AL(n), RAL(n);
    
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({ v, w });
    	RAL[v].pb({ u, w });
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
	vector<vector<int>> dist(2, vector<int> (n, INF));
	dist[0][0] = 0;
	
	while (!pq.empty()) {
		vector<int> state = pq.top();
		int d = state[0];
		int u = state[1];
		int rev = state[2];
		pq.pop();
		
		if (d > dist[rev][u]) continue;
		
		if (!rev) {
			for (auto& [v, w] : AL[u]) {
				if (d + w >= dist[rev][v]) continue;
				
				dist[rev][v] = d + w;
				pq.push({dist[rev][v], v, 0});
			}
		}
		
		for (auto& [v, w] : RAL[u]) {
			if (d + w >= dist[1][v]) continue;
			
			dist[1][v] = d + w;
			pq.push({dist[1][v], v, 1});
		}
	}
	
	for (int i = 1; i < n; i++) {
		int u = dist[0][i];
		int v = dist[1][i];
		
		u = min(u, v);
		if (u == INF) u = -1;
		cout << u << " ";
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
