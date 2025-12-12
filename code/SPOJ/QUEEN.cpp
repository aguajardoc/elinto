// Problem: Wandering Queen
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/QUEEN/
// Memory Limit: 1536 MB
// Time Limit: 703 ms
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
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007
 
double eps = 1e-9;

char mat[1001][1001];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int dist[1001][1001];
int done[1001][1001];
 
void solve() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start, ending;
    for (int i = 0; i < n; i++) {
		string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		mat[i][j] = s[j];
    		dist[i][j] = 1e9;
    		done[i][j] = 0;
    		if (mat[i][j] == 'S') {
    			start = {i, j};
    		}
    		if (mat[i][j] == 'F') {
    			ending = {i, j};
    		}
    	}
    }
    
    queue<pair<int, int>> q;
    q.push(start);

    dist[start.first][start.second] = 0;
	done[start.first][start.second] = 255;
    
    while (!q.empty()) {
    	pair<int, int> u = q.front();
    	q.pop();
    	ll nx, ny;
    	
    	if (u.first == ending.first and u.second == ending.second) {
    		cout << dist[ending.first][ending.second] << ln;
    		return;
    	}
    	
    	for (int j = 0; j < 8; j++) {
    		for (int i = 1; i <= max(n, m); i++) {
    			nx = u.first + dx[j]*i;
    			ny = u.second + dy[j]*i;
    			
    			if (nx < 0 or ny < 0 or nx >= n or ny >= m) break;
    			if (mat[nx][ny] == 'X') break;
    			if (done[nx][ny]&(1<<j)) break;
    			if (!done[nx][ny]) {
    				dist[nx][ny] = dist[u.first][u.second] + 1; 
    				q.push({nx, ny});
    			}
    			done[nx][ny] |= (1 << j);

    		}
    	}
    }
    cout << -1 << ln;
}
 
int main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out