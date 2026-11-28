// Problem: 12783 - Weak Links
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4648
// Memory Limit: 32 MB
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

vector<vector<int>> AL;
int n;
vector<int> visited, dfs_par, dfs_num, dfs_low;
int timer = 0;
vector<pair<int, int>> bridges;

void dfs(int u) {
	dfs_num[u] = dfs_low[u] = timer++;
	visited[u] = 1;
	
	for (auto& v : AL[u]) {
		if (visited[v] == 0) {
			dfs_par[v] = u;
			dfs(v);
			
			if (dfs_low[v] > dfs_num[u]) {
				bridges.pb({min(u,v), max(u,v)});
				// dbg(u, v);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (dfs_par[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
		
	}
	
	visited[u] = 2;
}

void solve() {
    int m;
    
    while (cin >> n >> m and !(n == 0 and m == 0)) {
	    AL.assign(n, vector<int>());
	    dfs_num.assign(n, 0);
	    dfs_low.assign(n, 0);
	    dfs_par.assign(n, -1);
	    visited.assign(n, 0);
	    timer = 0;
	    bridges.clear();
	    for (int i = 0; i < m; i++) {
	    	int u, v; cin >> u >> v;
	    	AL[u].pb(v);
	    	AL[v].pb(u);
	    }
	    
	    for (int i = 0; i < n; i++) {
	    	if (!visited[i]) dfs(i);
	    }
	    
	    sort(bridges.begin(), bridges.end());
	    cout << bridges.size();
	    for (auto& [x, y] : bridges) {
	    	cout << " " << x << " " << y;
	    }
	    cout << ln;
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
