// Problem: C. DZY Loves Physics
// Contest: Codeforces - Codeforces Round 254 (Div. 2)
// URL: https://codeforces.com/contest/445/problem/C
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

void getPath(int i, int j, vector<int>& path, vector<vector<int>>& p) {
	if (i != j) getPath(i, p[i][j], path, p);
	path.pb(j);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> val(n);
    for (auto& i : val) cin >> i;
    
    vector<vector<int>> FW(n + 1, vector<int>(n + 1, 1e14));
    vector<vector<int>> p(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++) {
    	FW[i][i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		p[i][j] = i;
    	}
    }
    
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	FW[u][v] = min(FW[u][v], w);
    	FW[v][u] = min(FW[v][u], w);
    }
    
    
    for (int k = 0; k < n; k++) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if (FW[i][k] + FW[k][j] < FW[i][j]) {
    				FW[i][j] = FW[i][k] + FW[k][j];
    				p[i][j] = p[k][j];
    			}
    		}
    	}
    }
    
    ld ans = 0.0;
    
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		vector<int> path;
    		getPath(i, j, path, p);
    		
    		if (FW[i][j] == 1e14) continue;
    		
    		ll v = 0;
    		ll e = FW[i][j];
    		for (auto& k : path) v += val[k];
    		
    		ld res = (ld)v/(ld)e;
    		
    		
    		if ((res - ans) > eps) {
    			ans = res;
    		}
    	}
    }
    
    
    cout << fixed << setprecision(14) << ans << ln;
    
    
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
