// Problem: D. Eternal Victory
// Contest: Codeforces - Codeforces Beta Round 57 (Div. 2)
// URL: https://codeforces.com/contest/61/problem/D
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
int res = 0;

void dfs(int u, int p, int cw) {
	bool hasChild = false;
	
	for (auto& [v, w] : AL[u]) {
		if (v == p) continue;
		
		hasChild = true;
		dfs(v, u, w + cw);
	}
	
	if (!hasChild) {
		res = max(res, cw);
	}
}

void solve() {
    int n;
    cin >> n;
    AL.assign(n, vector<pair<int, int>> ());
    int ans = 0;
    for (int i = 1; i < n; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	ans += w;
    	AL[u].pb({v, w});
    	AL[v].pb({u, w});
    }
    
    dfs(0, -1, 0);
    
    cout << 2 * ans - res << ln;
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
