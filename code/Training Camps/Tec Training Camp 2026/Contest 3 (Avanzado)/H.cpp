// Problem: H. Lomsat gelral
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/H
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<vector<int>> AL;
map<ll, ll> ct[100010], num[100010];
vector<ll> colors, visited, ans;

void dfs(int u) {
	visited[u] = 1;
	
	ct[u][1] = colors[u];
	num[u][colors[u]] = 1;
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		dfs(v);
		
		map<ll, ll>& numu = num[u];
		map<ll, ll>& numv = num[v];
		map<ll, ll>& ctu = ct[u];
		map<ll, ll>& ctv = ct[v];
		
		if (numv.size() > numu.size()) {
			swap(ctv, ctu);
			swap(numv, numu);
		}
		
		for (auto& [x, CT] : numv) {
			ctv[numu[x]] -= x;
			if (!ctu[numu[x]]) ctv.erase(numu[x]);
			numu[x] += CT;
			ctu[numu[x]] += x;
		}
		
		// ct[v].clear();
		num[v].clear();
	}
	
	ans[u] = ct[u].rbegin()->second;
}

void solve() {
    int n;
    cin >> n;
    colors.assign(n, 0);
    visited.assign(n, 0);
    ans.assign(n, 0);
    AL.assign(n, vector<int>());
    
    for (int i = 0; i < n; i++) {
    	cin >> colors[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    dfs(0);
    
    // for (int i = 0; i < n; i++) {
    	// cout << i << ": ";
    	// for (auto& j : ct[i]) {
    		// cout << j.first << " " << j.second << ln;
    	// }
    	// cout << ln;
    // }
    
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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