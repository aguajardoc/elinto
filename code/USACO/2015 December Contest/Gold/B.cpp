// Problem: Problem 2. Fruit Feast
// Contest: USACO - USACO 2015 December Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=574
// Memory Limit: 256 MB
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
    freopen("feast.in", "r", stdin); \
    freopen("feast.out", "w", stdout)
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

int dp[5000001][2];

void solve() {
    int T,a,b;
    cin >> T >> a >> b;
    fill_n(&dp[0][0], 2*5000001, 0);
    dp[0][0] = 1;
    dp[0][1] = 1;
    
    for (int i = 0; i <= T; i++) {
    	if (i >= a) dp[i][0] |= dp[i - a][0];
    	if (i >= b) dp[i][0] |= dp[i - b][0];
    }
    
    for (int i = 0; i <= T; i++) {
    	if (2*i <= T) dp[i][1] |= dp[2*i][0];
    	if (2*i <= T) dp[i][1] |= dp[2*i+1][0];
    	if (i >= a) dp[i][1] |= dp[i - a][1];
    	if (i >= b) dp[i][1] |= dp[i - b][1];
    }
    
    int mx = 0;
    for (int i = 0; i <= T; i++) {
    	if (dp[i][0] or dp[i][1]) mx = max(mx, i);
    }
    
    cout << mx << ln;
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
