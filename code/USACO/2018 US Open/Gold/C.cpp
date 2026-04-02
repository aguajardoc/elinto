// Problem: Problem 3. Talent Show
// Contest: USACO - USACO 2018 US Open Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=839
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
    freopen("talent.in", "r", stdin); \
    freopen("talent.out", "w", stdout)
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

bool f(int n, int w, vector<int>& T, vector<int>& W, ld x) {
	vector<ld> dp(1001, -INF);
	dp[0] = 0;
	
	for (int i = 0; i < n; i++) {
		ld v = T[i] - x * W[i];
		for (int j = w; j >= 0; j--) {
			int next = min(w, j + W[i]);
			if (dp[j] != -INF) {
				dp[next] = max(dp[next], dp[j] + v);
			}
		}
	}
	
	return dp[w] >= 0;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> T(n), W(n);
    for (int i = 0; i < n ;i++) {
    	cin >> W[i] >> T[i];
    }
    
    ld l = 0, r = 1000;
    ld ans = 0;
    while (r - l >= eps) {
    	ld m = (l + r) / 2;
    	
    	bool fm = f(n, w, T, W, m);
    	
    	if (fm) {
    		ans = max(ans, m);
    		l = m;
    	}
    	else {
    		r = m;
    	}
    }
    
    ans *= 1000;
    cout << floor(ans) << ln;
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
