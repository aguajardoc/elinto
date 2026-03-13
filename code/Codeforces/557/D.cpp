// Problem: D. Vitaly and Cycle
// Contest: Codeforces - Codeforces Round 311 (Div. 2)
// URL: https://codeforces.com/contest/557/problem/D
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

vector<vector<int>> AL;
vector<set<int>> DSU;
vector<int> visited;
int sz2comps = 0;

int nc3(int n) {
	return (n * (n - 1) * (n - 2)) / 6;
}

void dfs(int u) {
	DSU.back().insert(u);
	visited[u] = true;
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		
		dfs(v);
	}
}


bool allCompsAtMostSz2(int n) {
	for (int u = 0; u < n; u++) {
		if (!visited[u]) {
			DSU.pb(set<int>());
			dfs(u);
			
			if (DSU.back().size() > 2) return false;
			else if (DSU.back().size() == 2) sz2comps++;
		}
	}
	
	return true;
}

// bool dfs2(int u, int par) {
	// v2[u] = true;
	// for (auto& v : AL[u]) {
		// if (v == par) continue;
// 		
		// if (v2[v]) {
			// cyc_e = u;
			// cyc_s = v;
			// return true;
		// }
// 		
		// p[v] = u;
		// if (dfs2(v, p[v])) {
			// return true;
		// }
	// }
// 	
	// return false;
// }

// bool oddLengthedCycle(int n) {
	// v2.assign(n, 0);
	// p.assign(n, -1);
	// cyc_s = -1;
// 	
	// for (int u = 0; u < n; u++) {
		// if (!v2[u] and dfs2(u, p[u])) break;
	// }
// 	
	// if (cyc_s == -1) return false;
// 	
	// vector<int> cyc;
	// cyc.pb(cyc_s);
	// for (int u = cyc_e; u != cyc_s; u = p[u]) {
		// cyc.pb(u);
	// }
// 	
	// return ((int)cyc.size() % 2);
// }

void solve() {
	int n, m;
	cin >> n >> m;
	AL.assign(n, vector<int>());
	visited.assign(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		AL[u].pb(v);
		AL[v].pb(u);
	}
	
	// t = 3
    // No edges exist -> m = 0
    // aka all components are of size 1
    // Implies adding (x, y), (y, z) and (z, x)
    // ans = n C 3 
    if (m == 0) {
    	cout << 3 << " " << nc3(n) << ln;
    	return;
    }
	
    // t = 0
    // There are odd-lengthed cycles already.
    // ans = 1
    // if (oddLengthedCycle(n)) {
    	// cout << "0 1" << ln;
    	// return;
    // }
    
    // t = 2
    // Edge (x, y) exists
    // Implies adding (y, z) and (z, x)
    // Implies all components are at most of size 2
    // Obviously at least one does have size 2
    // Ways to connect size 2 comps w/any other node
    // ans = sz2comps * (n - 2)
    if (allCompsAtMostSz2(n)) {
    	cout << 2 << " " << (sz2comps * (n - 2)) << ln;
    	return;
    }
    
    // t = 1
    // Edges (x, y) and (y, z) exist
    // Implies adding (z, x)
    // Simplifies to having (y, x) and (y, z)
    // Aka any one node has two connections
    // Focused on already established components
    // Worst case scenario, graph is a star
    // Graph must be bipartite atp
    vector<int> bfsvis(n, 0);
    vector<int> color(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	if (bfsvis[i]) continue;
    	
    	int c1 = 1, c2 = 0;
    	queue<int> q;
    	
    	bfsvis[i] = true;
    	q.push(i);
    	color[i] = 1;
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    	
    		
    		for (auto& v : AL[u]) {
    			if (bfsvis[v]) {
    				if (color[u] == color[v]) {
    					cout << 0 << " " << 1 << ln;
    					return;
    				}
    				continue;
    			}
    			
    			q.push(v);
    			if (color[u] == 1) {
    				color[v] = 2;
    				c2++;
    			}
    			else {
    				color[v] = 1;
    				c1++;
    			}
    			
    			bfsvis[v] = true;
    		}
    	}
    	ans += (c1 * (c1 - 1)) / 2;
    	ans += (c2 * (c2 - 1)) / 2;
    }
    
    cout << 1 << " " << ans << ln;
    
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
