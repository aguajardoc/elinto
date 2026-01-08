// Problem: C. Restore Graph
// Contest: Codeforces - Codeforces Round 237 (Div. 2)
// URL: https://codeforces.com/contest/404/problem/C
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

bool connected = true;

vector<int> visited;

void dfs(int u, vector<vector<int>>& AL) {
	visited[u] = true;
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		dfs(v, AL);
	}
}


void solve() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> ct;
    
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	ct[x].pb(i + 1);
    }
    
    if (ct[0].empty() or ct[0].size() != 1) {
    	cout << -1 << ln;
    	return;
    }
    
    vector<vector<int>> AL(n + 1);
    vector<int> edgesRem(n + 1, k);
    
    int d = 0;
    while (!ct.empty() and d < n) {
    	// Connect dist with d + 1
    	// dbg(d);
    	int idxd = 0, idxe = 0;
    	while (idxe < (int)ct[d + 1].size()) {
    		while (idxd < (int)ct[d].size() and !edgesRem[ct[d][idxd]]) idxd++;
    		while (idxe < (int)ct[d + 1].size() and !edgesRem[ct[d + 1][idxe]]) idxe++;
    		
    		if (idxd == (int)ct[d].size() or idxe == (int)ct[d + 1].size()) {
    			break;
    		}
    		
    		edgesRem[ct[d][idxd]]--;
    		edgesRem[ct[d + 1][idxe]]--;
    		
    		
    		AL[ct[d][idxd]].pb(ct[d + 1][idxe]);
    		AL[ct[d + 1][idxe]].pb(ct[d][idxd]);
    		
    		idxe++;
    	}
    	d++;
    }
    
    visited.assign(n + 1, 0);
    dfs(1, AL);
    
    // dbg(visited.size());
    for (int i = 1; i <= n; i++) {
    	if (!visited[i]) connected = false;
    }
    
    if (!connected) cout << -1 << ln;
    else {
    	vector<pair<int, int>> edges;
    	for (int i = 1; i <= n; i++) {
    		for (auto& j : AL[i]) {
    			if (j < i) continue;
    			edges.pb({i, j});
    		}
    	}
    	
    	cout << edges.size() << ln;
    	for (auto& [u, v] : edges) {
    		cout << u << " " << v << ln;
    	}
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
