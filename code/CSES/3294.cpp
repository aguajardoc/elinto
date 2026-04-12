// Problem: Subarray Sum Constraints
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3294
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Edge {
	int v, s;
};

vector<int> p;
bool poss = true;
vector<int> visited;
vector<vector<Edge>> AL;

void dfs(int u) {
	visited[u] = true;
	
	for (auto& v : AL[u]) {
		if (visited[v.v]) {
			if (p[v.v] != p[u] + v.s) {
				poss = false;
			}
			continue;
		}
		
		// p[v] = p[u] + s
		p[v.v] = p[u] + v.s;
		dfs(v.v);
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    p.assign(n + 1, -1);
    AL.assign(n + 1, vector<Edge>());
    visited.assign(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
    	int u, v, s;
    	cin >> u >> v >> s;
    	AL[u-1].pb({v, s});
    	AL[v].pb({u - 1, -s});
    }
    
    for (int i = 0; i < n; i++) {
    	if (p[i] != -1 or visited[i]) continue;
    	p[i] = 0;
    	dfs(i);
    }
    
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
    	a[i-1] = p[i] - p[i-1];
    }
    
    if (!poss) {
    	cout << "NO"<< ln;
    	return;
    }
    cout << "YES" << ln;
    for (auto& i : a) {
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
