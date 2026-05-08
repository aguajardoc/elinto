// Problem: I. River Game
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/I
// Memory Limit: 256 MB
// Time Limit: 500 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int adjacent(vector<string>& mat, vector<vector<int>>& which, int x, int y, int n) {
	if (x > 0 and mat[x-1][y] == '*') return which[x-1][y];
	if (x < n - 1 and mat[x+1][y] == '*') return which[x+1][y];
	if (y > 0 and mat[x][y-1] == '*') return which[x][y-1];
	if (y < n - 1 and mat[x][y+1] == '*') return which[x][y+1];
	return false;
}

struct Component {
	vector<vector<int>> component;
	Component() {
		component.assign(11, vector<int> (11, 0));
	}
};

int dfs(int u, Component& C, vector<int>& visited, vector<int>& dp, int& n, vector<pair<int, int>>& banned) {
	// Check for dead
	if (dp[u] != -1) return dp[u];
	for (auto& [i, j] : banned) {
		if ((u & (1ll << i)) and (u & (1ll << j))) {
			return 67;
		}
	}
	
	// get nimbers of all possible states
	int nimber = 0;
	set<int> nimbers;
	for (int i = 0; i < n; i++) {
		if (u & (1ll << i)) continue;
		int v = (u ^ (1ll << i));
		
		nimbers.insert(dfs(v, C, visited, dp, n, banned));
	}
	
	for (auto& i : nimbers) {
		if (i != nimber) break;
		nimber++;
	}
	
	// dbg(u, nimber);
	
	return dp[u] = nimber;
}

int running = 0;

int getNimber(Component& C) {
	// dfs on states
	int n = 0;
	vector<pair<int, int>> nums;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (C.component[i][j]) {
				nums.pb({i, j});
				n++;
			}
		}
	}
	vector<int> nimber(1ll << n, -1);
	vector<int> visited(1ll << n, 0);
	
	// get banned pairs from touching
	vector<pair<int, int>> banned;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(nums[i].first - nums[j].first)
				+ abs(nums[i].second - nums[j].second) == 1
			) {
				// dbg(i, j);
				// dbg(nums[i].first, nums[i].second);
				// dbg(nums[j].first, nums[j].second);
				banned.pb({i, j});
			}
		}
	}
	
	dfs(0, C, visited, nimber, n, banned);
	
	return nimber[0];
}

vector<int> getGrundy(vector<Component>& C) {
	// Get nimber for each component
	vector<int> res;
	for (auto& i : C) {
		res.pb(getNimber(i));
	}
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
    	cin >> mat[i];
    }
    
    vector<vector<int>> when(n, vector<int>(n, -1)), which = when;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (mat[i][j] == 'x' or mat[i][j] == '.') continue;
    		if (which[i][j] != -1) continue;
    		
    		int time = i * n + j + 1;
    		
    		
			pair<int, int> now = {i, j};
			queue<pair<int, int>> q;
			q.push(now);
			which[i][j] = time;
			
			while (!q.empty()) {
				auto [ux, uy] = q.front();
				q.pop();
				
				for (auto& [dx, dy] : dir) {
					int nx = ux + dx;
					int ny = uy + dy;
					
					if (nx < 0 or nx == n or ny < 0 or ny == n) continue;
					if (mat[nx][ny] != '*') continue;
					if (which[nx][ny] == time) continue;
					
					which[nx][ny] = time;
					q.push({nx, ny});
				}
			}
    		
    	}
    }
    
    // for (int i = 0; i < n; i++) {
    	// for (int j = 0; j < n; j++) {
    		// cout << which[i][j] << " ";
    	// }
    	// cout << ln;
    // }
//     
    // cout << ln;
    
    vector<Component> components;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (mat[i][j] == 'x' or mat[i][j] == '*') continue;
    		if (when[i][j] != -1) continue;
    		
    		int time = i * n + j;
    		
    		if (adjacent(mat, which, i, j, n)) {
    			int component = adjacent(mat, which, i, j, n);
    			
    			// dbg(component);
    			components.pb(Component());
    			components.back().component[i][j] = 1;
    			
    			pair<int, int> now = {i, j};
    			queue<pair<int, int>> q;
    			q.push(now);
    			when[i][j] = time;
    			
    			while (!q.empty()) {
    				auto [ux, uy] = q.front();
    				q.pop();
    				
    				for (auto& [dx, dy] : dir) {
    					int nx = ux + dx;
    					int ny = uy + dy;
    					
    					if (nx < 0 or nx == n or ny < 0 or ny == n) continue;
    					if (mat[nx][ny] != '.') continue;
    					if (adjacent(mat, which, nx, ny, n) != component) continue;
    					if (when[nx][ny] == time) continue;
    					
    					components.back().component[nx][ny] = 1;
    					
    					when[nx][ny] = time;
    					q.push({nx, ny});
    				}
    			}
    		}
    	}
    }
    
    vector<int> times(n * n + 1, 0);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		// cout << when[i][j] << " ";
    		if (when[i][j] == -1) continue;
    		times[when[i][j]]++;
    	}
    	// cout << ln;
    }
    
    vector<int> nimbers = getGrundy(components);
    int ans = 0;
    for (auto& i : nimbers) ans ^= i;
    
    cout << (ans ? "First":"Second");
    cout << " player will win";
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
