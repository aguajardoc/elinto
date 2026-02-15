// Problem: Longest path in a tree
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PT07Z/
// Memory Limit: 1536 MB
// Time Limit: 500 ms
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

pair<int, int> bfs(int start, vector<vector<int>>& AL, int n) {
	queue<int> q;
	q.push(start);
	vector<int> dist(n, INF);
	dist[start] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (auto& v : AL[u]) {
			if (dist[v] != INF) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	
	pair<int, int> res = {-1, -1};
	
	for (int i = 0; i < n; i++) {
		if (dist[i] > res.second) {
			res = {i, dist[i]};
		}
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> AL(n);
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    if (n <= 1) {
    	cout << 0 << ln;
    	return;
    }
    
    pair<int, int> r = bfs(0, AL, n);
    pair<int, int> r2 = bfs(r.first, AL, n);
    
    cout << r2.second << ln;
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
