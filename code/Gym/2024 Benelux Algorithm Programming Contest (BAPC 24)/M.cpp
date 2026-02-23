// Problem: M. Museum Visit
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/M
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

const int TREE_SIZE = (1 << 20);
int st[2 * TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] = x;
	
	i >>= 1;
	
	while (i) {
		st[i] = min(st[2 * i], st[2*i + 1]);
		i >>= 1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = INF;
	
	while (l <= r) {
		if (l&1) res = min(res, st[l++]);
		if (!(r&1)) res = min(res, st[r--]);
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    fill_n(&st[0], 2 * TREE_SIZE, INF);
    vector<int> cost(n), dp(n+2, INF);
    for (auto& i : cost) cin >> i;
    
    vector<pair<int, int>> intervals(m);
    map<int, int> endings;
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	intervals[i] = {x, y};
    	if (!endings.count(y)) endings[y] = x;
    	else {
    		endings[y] = max(endings[y], x);
    	} 
    }
    
    int lgs = 0;
    cost.pb(0);
    dp[0] = 0;
    update(0, 0);
    
    for (int i = 1; i <= n + 1; i++) {
    	dp[i] = cost[i-1] + query(lgs, i - 1);
    	update(i, dp[i]);
    	
    	if (endings.count(i)) {
    		lgs = max(lgs, endings[i]);
    	}
    }
    
    cout << dp[n+1] << ln;
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
