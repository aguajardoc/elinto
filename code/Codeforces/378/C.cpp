// Problem: C. Maze
// Contest: Codeforces - Codeforces Round 222 (Div. 2)
// URL: https://codeforces.com/contest/378/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mat(n);
    int free =0;
    int sx, sy;
    for (auto& i : mat) cin >> i;
    if (!k) {
    	for (auto& i : mat) {
    	cout << i << ln;
    }
    cout << ln;
    return;
    }
    for (auto& i : mat) {
    	for (auto& j : i) {
    		if (j == '.') {
    			free++;
    			j = 'X';
    		}
    	}
    }
    
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j <m; j++) {
    		if (mat[i][j] == 'X') {
    			sx = i, sy = j;
    		}
    	}
    }
    
    
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    q.emplace(sx, sy);
    mat[sx][sy] = '.';
    free--;
    
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[sx][sy] = 0;
    while (!q.empty() and free > k) {
    	pair<int, int> u = q.front();
    	q.pop();
    	
    	for (auto& [dx, dy] : dir) {
    		int nx = u.first + dx;
    		int ny = u.second + dy;
    		
    		if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
    		if (mat[nx][ny] != 'X') continue;
    		if (dist[nx][ny] != 1e9) continue;
    		
    		dist[nx][ny] = 1;
    		mat[nx][ny] = '.';
    		free--;
    		if (free == k) break;
    		q.emplace(nx, ny);
    	}
    }
    
    for (auto& i : mat) {
    	cout << i << ln;
    }
    cout << ln;
    
    
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
