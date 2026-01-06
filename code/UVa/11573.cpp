// Problem: 11573 - Ocean Currents
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2620
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
    vector<string> wind(n);
    for (auto& i : wind) cin >> i;
    
    vector<pair<int, int>> dx = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	
	int q;
	cin >> q;
	while(q--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sx--;sy--;ex--;ey--;
		
		#define Node pair<int, pair<int, int>>
		
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push({0, {sx, sy}});
		vector<vector<int>> dist(n, vector<int>(m, 1e9));
		dist[sx][sy] = 0;
		
		while (!pq.empty()) {
			Node node = pq.top();
			pq.pop();
			int d = node.first;
			int ux = node.second.first;
			int uy = node.second.second;
			
			if (dist[ux][uy] > d) continue;
			
			for (int i = 0; i < 8; i++) {
				int nx = ux + dx[i].first;
				int ny = uy + dx[i].second;
				
				if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
				int w = 1;
				if (i == (wind[ux][uy] - '0')) w--;
				if (dist[ux][uy] + w >= dist[nx][ny]) continue;
				
				dist[nx][ny] = dist[ux][uy] + w;
				pq.push({dist[nx][ny], {nx, ny}});
			} 
		}
		
		// for (int i = 0; i < n; i++) {
			// for (int j = 0; j < m; j++) {
				// cout << dist[i][j] << " ";
			// }
			// cout << ln;
		// }
		
		cout << dist[ex][ey] << ln;
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
