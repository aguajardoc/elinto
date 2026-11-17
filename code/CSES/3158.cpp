// Problem: Bus Companies
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3158
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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> AL(n + m + 1);
    vector<int> c(m); for (auto& i : c) cin >> i;
    
    for (int i = 0; i < m; i++) {
    	int k; cin >> k;
    	for (int j = 0; j < k; j++) {
    		int u; cin >> u; u--;
    		AL[u].pb({n + i, c[i]});
    		AL[n+i].pb({u, 0});
    	}
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> dist(n + m, INF); dist[0] = 0;
    
    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	
    	if (dist[u] < d) continue;
    	
    	for (auto& [v, w] : AL[u]) {
    		if (d + w >= dist[v]) continue;
    		
			dist[v] = d + w;
			pq.push({dist[v], v});
    		
    	}
    }
    
    for (int i = 0; i < n; i++) {
    	cout << dist[i] << " ";
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
