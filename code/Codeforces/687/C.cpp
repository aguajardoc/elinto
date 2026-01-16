// Problem: C. The Values You Can Make
// Contest: Codeforces - Codeforces Round 360 (Div. 1)
// URL: https://codeforces.com/contest/687/problem/C
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

int dp[2][501][501];
int n, c;
vector<int> a;


void solve() {
    cin >> n >> c;
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    
    sort(a.begin(), a.end());
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	for (int j = 0; j <= 500; j++) {
    		for (int k = 0; k <= 500; k++) {
    			dp[now][j][k] |= dp[last][j][k];
    			if (j + a[i - 1] <= c) 
    				dp[now][j + a[i-1]][k] |= dp[last][j][k];
	    		if (j + a[i - 1] <= c and k + a[i - 1] <= c)
	    			dp[now][j + a[i-1]][k + a[i - 1]] |= dp[last][j][k];
    			
    		}
    	}
    	
    	fill_n(&dp[last][0][0], 501*501, 0);
    	
    }
    
    vector<int> ans;
    
    for (int i = 0; i <= c; i++) {
    	if (dp[n%2][c][i]) {
    		ans.pb(i);
    	}
    }
    
    cout << ans.size() << ln;
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
}

signed main() {
    fast_cin();
    fill_n(&dp[0][0][0], 2*501*501, 0);
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out