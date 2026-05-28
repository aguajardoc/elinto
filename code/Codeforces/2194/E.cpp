// Problem: E. The Turtle Strikes Back
// Contest: Codeforces - Codeforces Round 1078 (Div. 2)
// URL: https://codeforces.com/contest/2194/problem/E
// Memory Limit: 512 MB
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dpF(n + 2, vector<int> (m + 2, -INF)), dpB = dpF, a = dpF, pathm = dpF;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i+1][j+1];
    	}
    }
    
    dpF[0][1] = 0;
    dpF[1][0] = 0;
    
    dpB[n][m+1] = 0;
    dpB[n+1][m] = 0;
    
    // fill dps and get path
    vector<pair<int, int>> path = {{n, m}};
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		int L = dpF[i][j-1];
    		int T = dpF[i-1][j];
    		
    		if (L > T) {
    			pathm[i][j] = 0; // left
    		}
    		else {
    			pathm[i][j] = 1;
    		}
    		
    		dpF[i][j] = max(L, T) + a[i][j];
    	}
    }
    
    for (int i = n; i >= 1; i--) {
    	for (int j = m; j >= 1; j--) {
    		int R = dpB[i][j+1];
    		int D = dpB[i+1][j];
    		
    		dpB[i][j] = max(R, D) + a[i][j];
    	}
    }
    
    int cx = n, cy = m;
    while (true and !(cx == 1 and cy == 1)) {
    	if (pathm[cx][cy] == 0) {
    		cy--;
    	}
    	else cx--;
    	
    	path.pb({cx, cy});
    }
    
    int ans = dpF[n][m];
    int og = ans;
    for (auto& [x, y] : path) {
    	int take = og - 2 * a[x][y];
    	int alternate = take;
    	
    	for (int i = x + y - 1, j = 1; i >= 1 and j <= m; i--, j++) {
    		if (i > n) {
    			int diff = i - n;
    			i -= diff;
    			j += diff;
    		}
    		
    		if ((x == i and y == j)) continue;
    		alternate = max(alternate, 
    			dpF[i][j] +
    			dpB[i][j] - 
    			a[i][j]
    		);
    	}
    	
    	int res = max(take, alternate);
    	ans = min(ans, res);
    }
    
    cout << ans << ln;
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
