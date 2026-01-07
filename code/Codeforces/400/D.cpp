// Problem: D. Dima and Bacteria
// Contest: Codeforces - Codeforces Round 234 (Div. 2)
// URL: https://codeforces.com/contest/400/problem/D
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
int n, m, k;
vector<int> types, pft;
vector<vector<pair<int, int>>> AL;
vector<vector<int>> AM;
vector<set<int>> DSU;
vector<int> visited;

int getType(int b) {
	auto it = lower_bound(pft.begin(), pft.end(), b);
	return (distance(pft.begin(), it));
}

void dfs(int u, int idx) {
	DSU[idx].insert(u);
	visited[u] = true;
	
	
	for (auto& [v, w] : AL[u]) {
		// only check for 0-weight conns
		if (w) continue;
		// only include those in same component
		if (visited[v]) continue;
		
		dfs(v, idx);
	}
}

void dfsC(int u) {
	visited[u] = true;
	
	for (auto& [v, w] : AL[u]) {
		// If same component, don't add to AM
		// Min conn is best conn
		int tu = getType(u);
		int tv = getType(v);
		if (tu != tv) {
			AM[tu][tv] = min(AM[tu][tv], w);
			AM[tv][tu] = min(AM[tv][tu], w);
		}
		if (visited[v]) continue;
		
		dfsC(v);
	}
}

int getComponent(int x) {
	for (int j = 0; j < DSU.size(); j++) {
		if (DSU[j].count(x)) return j;
	}
	
	return -1;
}

void solve() {
	cin >> n >> m >> k;    
	types.assign(k, 0);
	for (auto& i : types) cin >> i;
	pft = {0};
	for (int i = 0; i < (int)types.size(); i++) {
		pft.pb(pft[i] + types[i]);
	}
	
	AL.assign(n + 1, vector<pair<int, int>>());
	
	for (int i = 0; i < m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		AL[u].pb({v, w});
		AL[v].pb({u, w});
	}
	
	// DFS to check for correctness
	bool correct = true;
	visited.assign(n + 1, 0);
	for (int i = 1; i <= k; i++) {
		DSU.pb(set<int>());
		dfs(pft[i], i - 1);
	}
	
	for (int i = 2; i <= n; i++) {
		
		if (getType(i - 1) == getType(i)) {
			if (getComponent(i - 1) != getComponent(i)) correct = false;
		}
	}
	
	if (!correct) {
		cout << "No" << ln;
		return;
	}
	else cout << "Yes" << ln;
	
	// Get connections between components
	visited.assign(n + 1, 0);
	AM.assign(k + 1, vector<int> (k + 1, 1e10));
	for (int i = 0; i <= k; i++) {
		AM[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		dfsC(i);
	}
	
	// FW on AM for ans
	for (int kk = 1; kk <= k; kk++) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k; j++) {
				AM[i][j] = min(AM[i][j], AM[i][kk] + AM[kk][j]);
			}
		}
	}
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			cout << (AM[i][j] == 1e10 ? -1:AM[i][j]) << " ";
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
