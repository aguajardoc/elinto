// Problem: Money Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1745
// Memory Limit: 512 MB
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

int dp[101][100001];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    fill_n(&dp[0][0], 101*100001, 0);
    for (int i = 0; i <= n; i++) {
    	dp[i][0] = 1;
    }
    
    set<int> poss;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= 1000*n; j++) {
    		dp[i][j] |= dp[i-1][j];
    		if (j - a[i-1] >= 0) 
    		dp[i][j] |= dp[i-1][j-a[i-1]];
    		if (dp[i][j]) {
    			poss.insert(j);
    		}
    	}
    }
    
    cout << poss.size() << ln;
    for (auto& i : poss) {
    	cout << i << " ";
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
