// Problem: B. Make Connected
// Contest: Codeforces - Pinely Round 5 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2161/problem/B
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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

vector<string> stair(vector<string> mat, int mode) {
	int n = mat.size();
	
	// Find first
	int x = -1, y;
	for (int i = 0; i < n and x == -1; i++) {
		for (int j = 0; j < n and x == -1; j++) {
			if (mat[i][j] == '#') {
				x = i, y = j;	
			}
		}
	}
	
	// Stair based on mode
	int dir = 0;
	while (x < n and y < n and x >= 0 and y >= 0) {
		mat[x][y] = '#';
		if (mode == 0) {
			if (!dir) x++;
			else y++;
		}
		else if (mode == 1) {
			if (!dir) x++;
			else y--;
		}
		else if (mode == 2) {
			if (dir) x++;
			else y++;
		}
		else if (mode == 3) {
			if (dir) x++;
			else y--;
		}
		
		dir = 1 - dir;
	}
	
	return mat;
}

void print(vector<string> mat) {
	for (auto& i : mat) {
		cout << i << ln;
	}
	cout << ln;
}

bool check(vector<string> mat) {
	int n = mat.size();
	
	// print(mat);
	
	// Check for consec
	int ct = 0;
	for (int i = 0; i < n; i++) {
		ct += (count(mat[i].begin(), mat[i].end(), '#'));
		for (int j = 0; j < n; j++) {
			if (j + 2 < n) {
				if (mat[i][j] == '#'
					and mat[i][j+1] == '#'
					and mat[i][j+2] == '#'
				) return false;
			}
			
			if (i + 2 < n) {
				if (mat[i][j] == '#'
					and mat[i+1][j] == '#'
					and mat[i+2][j] == '#'
				) return false;
			}
		}
	}
	
	// Check if all are reachable w/bfs
	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '#') {
				ct--;
				
				queue<pair<int, int>> q;
				q.push({i, j});
				vector<vector<int>> visited(n, vector<int> (n, 0));
				visited[i][j] = 1;
				
				while (!q.empty()) {
					auto [ux, uy] = q.front();
					q.pop();
					
					for (auto& [dx, dy] : dir) {
						int nx = ux + dx;
						int ny = uy + dy;
						
						if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
						if (visited[nx][ny]) continue;
						if (mat[nx][ny] == '.') continue;
						
						visited[nx][ny] = true;
						ct--;
						q.push({nx, ny});
					}
				}
		
				
				return !ct;
			}
		}
	}
	
	return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> mat(n);
    int ct = 0;
    for (int i = 0; i < n; i++) {
    	cin >> mat[i];
    	ct += (count(mat[i].begin(), mat[i].end(), '#'));
    }
    
    if (ct <= 1) {
    	cout << "YES" << ln;
    	return;
    }
    
    if (ct == 4) {
    	bool valid = false;
    	for (int i = 0; i < n-1; i++){
    		for (int j = 0; j < n-1; j++) {
    			if (mat[i][j] == '#' 
    				and mat[i+1][j] == '#'
    				and mat[i][j+1] == '#'
    				and mat[i+1][j+1] == '#'
    			) valid = true;
    		}
    	}
    	
    	if (valid) {
			cout << "YES" << ln;
			return;
    	}
    }
    
    bool ans = (check(stair(mat, 0)) or check(stair(mat, 1)) or check(stair(mat, 2)) or check(stair(mat, 3)));
    
    cout << (ans ? "YES":"NO") << ln;
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
