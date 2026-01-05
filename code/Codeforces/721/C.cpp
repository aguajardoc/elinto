// Problem: C. Journey
// Contest: Codeforces - Codeforces Round 374 (Div. 2)
// URL: https://codeforces.com/contest/721/problem/C
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

int n, m, T;
vector<vector<pair<int, int>>> AL;
vector<int> p, ans;

void buildAns() {
	ans.clear();
	int start = n - 1;
	while (start != -1) {
		ans.pb(start);
		start = p[start];
	}
}

vector<vector<int>> dp;

void dfs(int u, int time, int len) {
	if (time > T) {
		return;
	}
	if (u == n - 1) {
		if (len >= ans.size()) {
			buildAns();
		}
		return;
	}
	
	if (dp[u][len] <= time) return;
	dp[u][len] = time;
	
	for (auto& [v, w] : AL[u]) {
		p[v] = u;
		dfs(v, time + w, len + 1);
	}
}

void solve() {
	cin >> n >> m >> T;
	AL.assign(n, vector<pair<int, int>> ());
	p.assign(n, -1);
	dp.assign(n, vector<int> (n, INF));
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		AL[u].pb({v, w});
	}
	
	dfs(0, 0, 0);
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << ln;
	for (auto& i : ans) {
		cout << i + 1 << " ";
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