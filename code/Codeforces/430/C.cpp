// Problem: C. Xor-tree
// Contest: Codeforces - Codeforces Round 245 (Div. 2)
// URL: https://codeforces.com/contest/430/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

vector<int> init, goal, visited;
vector<vector<int>> AL;
int ans = 0;
vector<int> c;

void dfs(int u, int odd, int even, int vis) {
	visited[u] = true;
	int extra;
	if (vis % 2) extra = odd;
	else extra = even;
	int tv = (init[u] + extra) % 2;

	if (tv != goal[u])  {
		ans++;
		c.push_back(u);
		if (vis % 2) {
			odd++;
		}
		else even++;
	}
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		
		dfs(v, odd, even, vis + 1);
	}
}

void solve() {
    int n;
    cin >> n;
    AL.assign(n, vector<int>());
    init.assign(n, 0);
    goal.assign(n, 0); 
    visited.assign(n, 0);       
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].push_back(v);
    	AL[v].push_back(u);
    }
    for (auto& i : init) cin >> i;
    for (auto& i : goal) cin >> i;    
    
    dfs(0, 0, 0, 0);
    cout << ans << ln;
    for (auto& i : c) {
    	cout << i + 1 << ln;
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
