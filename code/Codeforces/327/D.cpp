// Problem: D. Block Tower
// Contest: Codeforces - Codeforces Round 191 (Div. 2)
// URL: https://codeforces.com/contest/327/problem/D
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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    
    vector<vector<int>> ops;
    // B = 0, R = 1, D = 2
    // 1-indexed
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j] == '#') continue;
    		ops.pb({0, i + 1, j + 1});
    	}
    }
    
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    vector<vector<int>> dist(n, vector<int> (m, INF));
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j] == '#') continue;
    		if (dist[i][j] != INF) continue;
    		
    		// BFS
    		dist[i][j] = 0;
    		queue<pair<int, int>> q;
    		q.push({i, j});
    		
    		while (!q.empty()) {
    			pair<int, int> u = q.front();
    			
    			q.pop();
    			
    			for (auto& [dx, dy] : dir) {
    				int vx = u.first + dx;
    				int vy = u.second + dy;
    				
    				if (vx == n or vx < 0 or vy == m or vy < 0) continue;
    				if (a[vx][vy] == '#') continue;
    				if (dist[vx][vy] != INF) continue;
    				
    				dist[vx][vy] = dist[u.first][u.second] + 1;
    				q.push({vx, vy});
    			}
    		}
    	}
    }
    
    vector<pair<int, pair<int, int>>> od;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (dist[i][j] > 0 and dist[i][j] != INF)
    		od.pb({dist[i][j], {i+1, j+1}});
    	}
    }
    
    sort(od.rbegin(), od.rend());
    
    for (auto& i : od) {
    	ops.pb({2, i.second.first, i.second.second});
    	ops.pb({1, i.second.first, i.second.second});
    }
    
    cout << ops.size() << ln;
    for (auto& i : ops) {
    	if (i[0] == 0) cout << "B ";
    	if (i[0] == 1) cout << "R ";
    	if (i[0] == 2) cout << "D ";
    	cout << i[1] << " " << i[2] << ln;
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
