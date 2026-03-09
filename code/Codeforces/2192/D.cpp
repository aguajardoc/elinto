// Problem: D. Cost of Tree
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/D
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
vector<int> base_cost, dp, gain, sum_a, max_d1, max_d2, a;
vector<vector<int>> AL;

void dfs(int u, int p, int depth) {
	dp[u] = 0;
	sum_a[u] = a[u];
	base_cost[u] = 0;
	gain[u] = 0;
	
	max_d1[u] = depth;
	max_d2[u] = depth;
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u, depth + 1);
		
		sum_a[u] += sum_a[v];
		base_cost[u] += base_cost[v] + sum_a[v];
		if (max_d1[v] > max_d1[u]) {
			max_d2[u] = max_d1[u];
			max_d1[u] = max_d1[v];
		}
		else if (max_d1[v] > max_d2[u]) {
			max_d2[u] = max_d1[v];
		}
	}
	
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		gain[u] = max(gain[u], gain[v]);
		
		int LD;
		if (max_d1[v] == max_d1[u]) {
			LD = max_d2[u];
		}
		else LD = max_d1[u];
		
		int change = LD - depth;
		
		gain[u] = max(gain[u], change * sum_a[v]);
	}
	
	dp[u] = base_cost[u] + gain[u];
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    AL.assign(n, vector<int>());
    dp.assign(n, 0);
    gain.assign(n, 0);
    max_d1.assign(n, 0);
    max_d2.assign(n, 0);
    sum_a.assign(n, 0);
    base_cost.assign(n, 0);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >>u >> v;
    	u--, v--;
    	
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    dfs(0, -1, 0);
    
    for (auto& i : dp) {
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
