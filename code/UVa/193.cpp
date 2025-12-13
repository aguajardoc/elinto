// Problem: 193 - Graph Coloring
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129
// Memory Limit: 32 MB
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
vector<vector<int>> AL;
int ans = 0;
vector<int> bColor;

bool canBeBlack(int v, vector<int>& color) {
	for (auto& u : AL[v]) {
		if (color[u] == 1) return false;
	}
	return true;
}

map<vector<int>, int> dp;

void dfs(int u, vector<int>& color, int& ct) {
	if (dp.count(color)) return;
	dp[color] = 1;
	for (auto& v : AL[u]) {
		if (color[v]!=-1) continue;
		
		color[v] = 0;
		dfs(v, color, ct);
		if (canBeBlack(v, color)) {
			color[v] = 1;
			ct++;
			dfs(v, color, ct);
			ct--;	
		}
		color[v] = -1;
	}
	
	if (ct > ans) {
		ans = ct;
		bColor = color;
	}
}

void solve() {
     int n, k;
     cin >> n >> k;
     AL.assign(102, vector<int>());
     ans = 0;
     bColor.clear();
     
     AL[101] = {0};
     for (int i = 0; i < k; i++) {
     	int u, v;
     	cin >> u >> v;
     	u--, v--;
     	AL[u].push_back(v);
        AL[v].push_back(u);
     }
     
     vector<int> color(n, -1);
     int ct = 0;
     dfs(101, color, ct);
     
     cout << ans << ln;
     for (int i = 0;i < n; i++) {
     	if (bColor[i] == 1) {
     		cout << i + 1 << " ";
     	}
     }
     cout << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
