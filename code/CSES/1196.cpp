// Problem: Flight Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1196/
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
    // dist[x][v] = dist[x-1][u]
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> AL(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({v, w});
    }
    
    vector<priority_queue<int>> dist(n + 1);
    
    dist[0].push(0);
    
    pq.push({0, 0});
    while (!pq.empty()) {
    	pair<int, int> U = pq.top();
    	pq.pop();
    	
    	int d = U.first;
    	int u = U.second;
    	
    	if (dist[u].size() == k and dist[u].top() < d) continue;
    	
    	for (auto& [v, w] : AL[u]) {
			int nd = w + d;
			if (dist[v].size() == k and dist[v].top() <= nd) continue;
			
			dist[v].push(nd);
			while (dist[v].size() > k) dist[v].pop();
			
			pq.push({nd, v});
    	}
    }
    
    vector<int> ans;
    while (!dist[n-1].empty()) {
    	ans.pb(dist[n-1].top());
    	dist[n-1].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto& i : ans) {
    	cout << i << " ";
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
