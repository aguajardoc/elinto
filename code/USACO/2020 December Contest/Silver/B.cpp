// Problem: Problem 2. Rectangular Pasture
// Contest: USACO - USACO 2020 December Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=1063#
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
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    vector<vector<int>> pref(n + 2, vector<int> (n + 2, 0)), mat = pref;
    
    vector<int> rows, cols;
    
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	cows[i] = {x, y};
    	rows.pb(x);
    	cols.pb(y);
    }
    
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    
    rows.resize(unique(rows.begin(), rows.end()) - rows.begin());
    cols.resize(unique(cols.begin(), cols.end()) - cols.begin());
    
    for (auto& [x, y] : cows) {
    	x = lower_bound(rows.begin(), rows.end(), x) - rows.begin();
    	y = lower_bound(cols.begin(), cols.end(), y) - cols.begin();
    	
    	mat[x][y] = 1;
    }
    
    sort(cows.begin(), cows.end());
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
    	}
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
    	int x1 = cows[i].first + 1;
    	int y1 = cows[i].second + 1;
    	for (int j = i + 1; j < n; j++) {
    		int x2 = cows[j].first + 1;
    		int y2 = cows[j].second + 1;
    		
    		int X1 = min(x1,x2);
    		int Y1 = min(y1, y2);
    		int X2 = max(x1, x2);
    		int Y2 = max(y1, y2);
    		
    		int up = pref[X1-1][Y2] - pref[X1-1][Y1-1];
    		int down = pref[n][Y2] - pref[n][Y1-1] - pref[X2][Y2] + pref[X2][Y1-1];
    		
    		ans += (up + 1) * (down + 1);
    	}
    }
    
    cout << ans + n + 1 << ln;
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
