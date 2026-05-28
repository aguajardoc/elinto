// Problem: 1033. Labyrinth
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1033
// Memory Limit: 64 MB
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

void solve() {
    int n;
    cin >> n;
    vector<string> a(n + 2, string(n + 2, '#'));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	s = '#' + s + '#';
    	a[i+1] = s;
    }
    
    a[0][0] = '$';
    a[0][1] = '$';
    a[1][0] = '$';
    
    a[n+1][n+1] = '$';
    a[n+1][n] = '$';
    a[n][n+1] = '$';
    
    // for (auto& i : a) {
    	// cout << i << ln;
    // }
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n+2, vector<int> (n + 2, 0));
    q.push({1, 1});
    q.push({n, n});
    int ans = 0;
    visited[1][1] = 1;
    visited[n][n] = 1;
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    
    while (!q.empty()) {
    	pair<int, int> u = q.front();
    	q.pop();
    	
    	// check walls and go on
    	for (auto& [dx, dy] : dir) {
    		int nx = u.first + dx;
    		int ny = u.second + dy;
    		
    		if (nx < 0 or ny < 0 or nx >= n + 2 or ny >= n + 2) continue;
    		if (a[nx][ny] == '$') continue;
    		if (visited[nx][ny]) continue;
    		if (a[nx][ny] == '#') {
    			// dbg(nx, ny);
    			ans++;
    			continue;
    		}
    		
    		visited[nx][ny] = 1;
    		q.push({nx, ny});
    	}
    }
    
    cout << ans * 9 << ln;
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
