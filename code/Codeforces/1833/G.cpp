// Problem: G. Ksyusha and Chinchilla
// Contest: Codeforces - Codeforces Round 874 (Div. 3)
// URL: https://codeforces.com/contest/1833/problem/G
// Memory Limit: 256 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<set<pair<int, int>>> AL;
vector<int> edge_to_parent;
vector<int> cuts;
vector<vector<pair<int,int>>> FAL;
vector<pair<int, int>> P;
vector<int> visited;

bool is_rule(int u) {
	if (AL[u].size() > 2) return false;
	if (AL[u].empty()) return false;
	
	if (AL[u].size() == 1) {
		int v = AL[u].begin()->first;
		if (AL[v].size() == 1) {
			int w = AL[v].begin()->first;
			if (AL[w].empty()) return true;
			return false;
		}
		return false;
	}
	
	int v1 = AL[u].begin()->first;
	int v2 = AL[u].rbegin()->first;
	if (!AL[v1].empty() or !AL[v2].empty()) return false;
	return true;
}

void cut(int i) {
	if (i == -1) return;
	cuts.pb(i);
}

void remove_edge(int i, int v) {
	if (i == -1 or edge_to_parent[i] == -1) return;
	AL[edge_to_parent[i]].erase({v, i});
}

void dfs(int u, int ei) {
	visited[u] = true;
	if (is_rule(u)) {
		cut(ei);
		remove_edge(ei, u);
		return;
	}
	
	while (true) {
		int sz = AL[u].size();
		int i = 0;
		for (auto& [v, ej] : AL[u]) {
			dfs(v, ej);
			if (AL[u].size() != sz) break;
			i++;
		}
		
		if (i == sz) break;
	}
	
	if (is_rule(u)) {
		cut(ei);
		remove_edge(ei, u);
		return;
	}
}

void fdfs(int u) {
	visited[u] = 1;
	
	for (auto& [v, e] : FAL[u]) {
		if (visited[v]) continue;
		P[v] = {u, e};
		fdfs(v);
	}
}

void get_parents(int n) {
	fdfs(0);
	for (int v = 0; v < n; v++) {
		if (P[v].first == -1) continue;
		auto [u, e] = P[v];
		AL[u].insert({v, e});
		edge_to_parent[e] = u;
	}
}

void solve() {
    int n; cin >> n;
    AL.clear(); AL.resize(n);
    edge_to_parent.assign(n, -1);
    cuts.clear();
    FAL.clear(); FAL.resize(n);
    P.assign(n, {-1, -1});
    visited.assign(n, 0);
    
    for (int i = 0; i < n - 1; i++) {
    	int u, v; cin >> u >> v;
    	u--, v--;
    	FAL[u].pb({v, i+1});
    	FAL[v].pb({u, i+1});
    }
    
    if (n % 3) {
    	cout << -1 << ln;
    	return;
    }
    
    get_parents(n);
    
    visited.assign(n, 0);
    dfs(0, -1);
    if (cuts.size() != n/3 - 1) {
    	cout << -1 << ln;
    	return;
    }
    
    cout << cuts.size() << ln;
    for (auto& i : cuts) {
    	cout << i << " ";
    }
    cout << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
