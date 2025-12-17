// Problem: C. Text Editor
// Contest: Codeforces - Codeforces Round 154 (Div. 2)
// URL: https://codeforces.com/contest/253/problem/C
// Memory Limit: 256 MB
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
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

pair<int, int> valid(int x, int y, vector<vector<int>>& d) {
	if (x < 0) { // up invalid
		return {x + 1, y};
	}
	if (x == d.size()) { // down invalid
		return {x - 1, y};
	}
	if (y < 0) { // left invalid
		return {x, y + 1};
	}
	if (y >= d[x].size()) { // right invalid
		return {x, d[x].size() - 1};
	}
	return {x, y}; // valid;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n);
    // dbg(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	dist[i] = vector<int> (x + 1, 1e9);
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    
    queue<pair<int, int>> q;
    q.emplace(x1, y1);
    // dbg(x1);
    // dbg(x1, y1, dist[x1].size());
    dist[x1][y1] = 0;
    
    while (!q.empty()) {
    	pair<int, int> u = q.front();
    	q.pop();
    	
    	for (auto& [dx, dy] : dir) {
    		int nx = u.first + dx;
    		int ny = u.second + dy;
    		pair<int, int> help;
    		
    		do {
    			help = valid(nx, ny, dist);
	    		nx = help.first;
	    		ny = help.second;
	    	} while (help != make_pair(nx, ny));
    		// dbg(nx, ny);
    		if (dist[nx][ny] != 1e9) continue;
    		
    		dist[nx][ny] = dist[u.first][u.second] + 1;
    		q.emplace(nx, ny);
    	}
    }
    
    cout << dist[x2][y2] << ln;
}

signed main() {
    fast_cin();
    iofiles();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
