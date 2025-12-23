// Problem: 10986 - Sending email
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve(int caseN) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    vector<vector<pair<int, int>>> AL(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	AL[u].push_back({v, w});
    	AL[v].push_back({u, w});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    vector<int> dist(n, 1e12);
    dist[s] = 0;
    
    while (!pq.empty()) {
    	pair<int, int> node = pq.top();
    	pq.pop();
    	int d = node.first;
    	int u = node.second;
    	
    	if (d > dist[u]) continue;
    	
    	for (pair<int, int>& v : AL[u]) {
    		if (d + v.second >= dist[v.first]) continue;
    		
    		dist[v.first] = d + v.second;
    		pq.push({dist[v.first], v.first});
    	}
    }
    
    cout << "Case #" << caseN << ": ";
    
    if (dist[t] == 1e12) {
    	cout << "unreachable" << ln;
    }
    else cout << dist[t] << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve( i );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
