// Problem: D. Buy a Ticket
// Contest: Codeforces - Educational Codeforces Round 38 (Rated for Div. 2)
// URL: https://codeforces.com/contest/938/problem/D
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

vector<vector<pair<int, int>>> AL;
vector<int> visited;
vector<set<int>> DSU;
int n, m;

void dfs(int u) {
	DSU.back().insert(u);
	visited[u] = true;
	
	for (auto& [v, w] : AL[u]) {
		if (visited[v]) continue;
		
		dfs(v);
	}
}

void solve() {
    cin >> n >> m;
    AL.assign(n, vector<pair<int, int>> ());
    visited.assign(n, 0);
    
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({v, w});
    	AL[v].pb({u, w});
    }
    
    vector<int> cost(n), ans(n, 0);
    for (auto& i : cost) cin >> i;
    
    // Get components
    for (int i = 0; i < n; i++) {
    	if (visited[i]) continue;
    	DSU.pb(set<int>());
    	dfs(i);
    }
    
    // For each component
    for (auto& comp : DSU) {
	    // Get ticket costs
	    map<int, set<int>> ticket_nodes;
	    map<int, int> node_ticket;
	    for (auto& u : comp) {
	    	ticket_nodes[cost[u]].insert(u);
	    	node_ticket[u] = cost[u];
	    }
	    
	    // Process map till empty, in ascending order
	    while (!ticket_nodes.empty()) {
	    	// Get current node
	    	int price = ticket_nodes.begin()->first;
	    	// dbg(ticket_nodes[price].size());
	    	int node = *(ticket_nodes.begin()->second.begin());
	    	// dbg(price, node);
	    	// Set ans to current
	    	cost[node] = price;
	    	
	    	
	    	
	    	// Check its neighbors
	    	for (auto& [v, w] : AL[node]) {
	    		// If cost exceeds its value, dont go
	    		if (price + 2 * w >= cost[v]) continue;
	    		
	    		// dbg(node, v);
	    		
	    		// Else, change its cost
	    		int current_cost = node_ticket[v];
	    		int new_cost = price + 2 * w;
	    		
	    		// Update maps
	    		ticket_nodes[current_cost].erase(v);
	    		if (ticket_nodes[current_cost].empty()) ticket_nodes.erase(current_cost);
	    		
	    		ticket_nodes[new_cost].insert(v);
	    		
	    		node_ticket[v] = new_cost;
	    		cost[v] = new_cost;
	    		
	    		// dbg(current_cost);
	    		// dbg(new_cost);
	    		// cout << ln;
	    	}
	    	
	    	// Remove this one
	    	ticket_nodes[price].erase(node);
	    	if (ticket_nodes[price].empty()) ticket_nodes.erase(price);
	    }
    }
    
    for (auto& i : cost) {
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
