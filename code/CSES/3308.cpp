// Problem: Graph Coloring
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3308
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int n, m;

vector<vector<int>> AL;
vector<pair<int, int>> EL;
vector<int> valid_coloring;

void print_coloring() {
	for (auto& i : valid_coloring) {
		cout << i << " ";
	}
	cout << ln;
}

bool validate_coloring(vector<int>& coloring) {
	for (auto& [u, v] : EL) {
		if (coloring[u] == coloring[v]) return false;
	}
	
	valid_coloring = coloring;
	return true;
}

bool check_coloring(int u, int colors, vector<int>& coloring) {
	if (u == n) {
		return validate_coloring(coloring);
	}
	
	bool poss = false;
	vector<int> invalid(n, 0);
	for (auto & v : AL[u]) {
		if (coloring[v]) invalid[coloring[v]] = 1;
	}
	
	for (int i = 1; i <= colors; i++) {
		if (invalid[i]) continue;
		coloring[u] = i;
		
		poss |= check_coloring(u + 1, colors, coloring);
		if (poss) break;
	}
	
	return poss;
}

void solve() {
    cin >> n >> m;
    AL.resize(n);
    for (int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    	EL.pb({u, v});
    }
    
    for (int colors = 1; colors <= n; colors++) {
    	vector<int> coloring(n, 0);
    	bool poss = check_coloring(0, colors, coloring);
    	if (poss) {
    		cout << colors << ln;
    		print_coloring();
    		return;
    	}
    }
    cout << -1 << ln;
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
