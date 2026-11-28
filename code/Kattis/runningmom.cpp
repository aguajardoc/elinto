// Problem: Running MoM
// Contest: Kattis
// URL: https://open.kattis.com/problems/runningmom
// Memory Limit: 1024 MB
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

vector<vector<int>> AL;
vector<pair<int, int>> cycles;
vector<int> visited, dfs_par, cycle;

void dfs(int u) {
	visited[u] = 1;
	
	for (auto& v : AL[u]) {
		if (visited[v] == 1) {
			// Cycle edge!
			cycles.pb({u, v});
			
			int x = u;
			while (x != v) {
				cycle[x] = 1;
				x = dfs_par[x];
			}
			cycle[x] = 1;
		}
		else if (visited[v] == 0) {
			dfs_par[v] = u;
			dfs(v);
		}
		
		if (cycle[v]) cycle[u] = 1;
	}
	
	visited[u] = 2;
}

void solve() {
    int n; cin >> n;
    map<string, int> mapping;
    visited.assign(2*n+1, 0);
    dfs_par.assign(2*n+1, -1);
    cycle.assign(2*n+1, 0);
    vector<string> inv_map(2*n + 1, "");
    
    AL.resize(2 * n + 1);
    for (int i = 0; i < n; i++) {
    	string s, t;
    	cin >> s >> t;
    	if (!mapping.count(s)) {
    		mapping[s] = mapping.size();
    	}
    	if (!mapping.count(t)) {
    		mapping[t] = mapping.size();
    	}
    	
    	int u = mapping[s], v = mapping[t];
    	inv_map[u] = s;
    	inv_map[v] = t;
    	AL[u].pb(v);
    }
    
    for (int i = 0; i < 2 * n + 1; i++) {
    	if (!visited[i]) dfs(i);
    }
    
    string s;
    while (cin >> s and !s.empty()) {
    	int u = mapping[s];
    	cout << s << " " << (cycle[u] ? "safe":"trapped") << ln;
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
