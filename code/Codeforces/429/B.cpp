// Problem: B. Working out
// Contest: Codeforces - Codeforces Round 245 (Div. 1)
// URL: https://codeforces.com/contest/429/problem/B
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

vector<vector<int>> verticalMirror(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	vector<vector<int>> newGrid = grid;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newGrid[i][j] = grid[n - i - 1][j];
		}
	}
	
	return newGrid;
}

vector<vector<int>> horizontalMirror(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	vector<vector<int>> newGrid = grid;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newGrid[i][j] = grid[i][m - j - 1];
		}
	}
	
	return newGrid;
}

void shiftBack(vector<vector<int>>& a) {
	int n = a.size();
	int m = a[0].size();
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			a[i-1][j-1] = a[i][j];
		}
	}
	
	for (auto& i : a) {
		i.resize(m-1);
	}
	a.resize(n-1);
}

void getRes(vector<vector<int>> grid, vector<vector<int>>& dp) {
	int n = grid.size();
	int m = grid[0].size();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
		}
	}
}

void print(vector<vector<int>>& dp) {
	for (auto& i : dp) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << ln;
	}
	cout << ln;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> grid[i][j];
    	}
    }
    
    vector<vector<vector<int>>> dp(4, vector<vector<int>> (n + 1, vector<int> (m + 1, 0)));
    
    // Normal (0, 0)
    getRes(grid, dp[0]);
    // Vertical mirror (n - 1, 0)
    getRes(verticalMirror(grid), dp[1]);
    // Horizontal mirror (0, m - 1)
    getRes(horizontalMirror(grid), dp[2]);
    // Both mirrors (n - 1, m - 1)
    getRes(verticalMirror(horizontalMirror(grid)), dp[3]);
    
    for (auto& i : dp) {
    	shiftBack(i);
    }
    
    dp[1] = verticalMirror(dp[1]);
    dp[2] = horizontalMirror(dp[2]);
    dp[3] = verticalMirror(horizontalMirror(dp[3]));
    
    
    // for (auto& i : dp) {
    	// print(i);
    	// cout << ln;
    // }
    
    // For every location, get max
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
    	for (int j = 1; j < m-1; j++) {
    		// Iahub to cell from top
    		int s1t = dp[0][i-1][j];
    		// Iahub from bottom to end
    		int e1t = dp[3][i+1][j];
    		// Iahub to cell from side
    		int s1s = dp[0][i][j-1];
    		// Iahub from side to end
    		int e1s = dp[3][i][j+1];
    		// Iahubina to cell from bottom
    		int s2t = dp[1][i+1][j];
    		// Iahubina from top to end
    		int e2t = dp[2][i-1][j];
    		// Iahubina to cell from side
    		int s2s = dp[1][i][j-1];
    		// Iahubina from side to end
    		int e2s = dp[2][i][j+1];
    		
    		// Iahub from top, Iahubina from side
    		int local1 = s1t+e1t+s2s+e2s;
    		// Iahub from side, Iahubina from bottom
    		int local2 = s1s+e1s+s2t+e2t;
    		
    		ans = max({ans, local1, local2});
    	}
    }
    
    cout << ans << ln;
    
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
