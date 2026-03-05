// Problem: C. King's Path
// Contest: Codeforces - Codeforces Round 149 (Div. 2)
// URL: https://codeforces.com/problemset/problem/242/C
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

void solve() {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    
    map<pair<int, int>, set<pair<int, int>>> AL;
    int n;
    cin >> n;
    vector<vector<int>> seg(n);
    for (int i = 0; i < n; i++) {
    	int r, L, R;
    	cin >> r >> L >> R;
    	// dbg(r, L, R);
    	seg[i] = {r, L, R};
    	for (int j = L; j <= R; j++) {
    		AL[{r, j}]; // Call into existence
    	}
    }
    
    vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    for (int i = 0; i < n; i++) {
    	int r = seg[i][0];
    	int L = seg[i][1];
    	int R = seg[i][2];
    	for (int j = L; j <= R; j++) {
    		// dbg(r, j);
    		// dbg(AL.count({r, j}));
    		
    		for (auto& [dx, dy] : dir) {
    			int nx = r + dx;
    			int ny = j + dy;
    			if (AL.count({nx, ny})) {
    				AL[{r, j}].insert({nx, ny});
    				AL[{nx, ny}].insert({r, j});
    			}
    		}
    	}
    }
    
    
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;
    
    q.push({sx, sy});
    dist[{sx, sy}] = 0;
    
    while (!q.empty()) {
    	pair<int,int> u = q.front();
    	q.pop();
    	
    	for (auto& [dx, dy] : dir) {
    		int nx = u.first + dx;
    		int ny = u.second + dy;
    		if (dist.count({nx, ny})) continue;
    		if (!AL[{u.first, u.second}].count({nx, ny})) continue;
    		     		
    		dist[{nx, ny}] = dist[{u.first, u.second}] + 1;
    		q.push({nx, ny});
    	}
    }
    
    if (!dist.count({ex, ey})) {
    	cout << -1 << ln;
    }
    else {
    	cout << dist[{ex, ey}] << ln;
    }
    
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
