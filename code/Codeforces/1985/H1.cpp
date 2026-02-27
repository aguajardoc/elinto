// Problem: H1. Maximize the Largest Component (Easy Version)
// Contest: Codeforces - Codeforces Round 952 (Div. 4)
// URL: https://codeforces.com/contest/1985/problem/H1
// Memory Limit: 512 MB
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

class DSU {
  private:
	vector<int> p, sz;
	// stores previous unites
	vector<pair<int &, int>> history;

  public:
	DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }

	int get(int x) { return x == p[x] ? x : get(p[x]); }
	
	int setSize(int x) {return sz[get(x)];}

	void unite(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) { return; }
		if (sz[a] < sz[b]) { swap(a, b); }

		// save this unite operation
		history.push_back({sz[a], sz[a]});
		history.push_back({p[b], p[b]});

		p[b] = a;
		sz[a] += sz[b];
	}

	int snapshot() { return history.size(); }

	void rollback(int until) {
		while (snapshot() > until) {
			history.back().first = history.back().second;
			history.pop_back();
		}
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n * m);
    
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
    	cin >> mat[i];
    }
    
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (mat[i][j] == '.') continue;
    		
    		int co = i * m + j;
    		
    		for (auto [dx, dy] : dir) {
    			int nx = i + dx;
    			int ny = j + dy;
    			
    			if (nx < 0 or ny < 0 or nx == n or ny == m) continue;
    			
    			if (mat[nx][ny] == '#') {
    				int cn = nx * m + ny;
    				dsu.unite(co, cn);
    			}
    		}
    	}
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
    	int last = dsu.snapshot();
    	// Add conns
    	for (int j = 0; j < m; j++) {
    		int co = i * m + j;
    		
    		for (auto [dx, dy] : dir) {
    			int nx = i + dx;
    			int ny = j + dy;
    			
    			if (nx < 0 or ny < 0 or nx == n or ny == m) continue;
    			
    			if (mat[nx][ny] == '#' or nx == i) {
    				int cn = nx * m + ny;
    				dsu.unite(co, cn);
    			}
    		}
    		ans = max(ans, dsu.setSize(co));
    	}
    	
    	dsu.rollback(last);
    }
    
    for (int i = 0; i < m; i++) {
    	int last = dsu.snapshot();
    	// Add conns
    	for (int j = 0; j < n; j++) {
    		int co = j * m + i;
    		
    		for (auto [dx, dy] : dir) {
    			int nx = j + dx;
    			int ny = i + dy;
    			
    			if (nx < 0 or ny < 0 or ny == m or nx == n) continue;
    		
    			
    			if (mat[nx][ny] == '#' or ny == i) {
    				int cn = nx * m + ny;
    				
    				// dbg(nx, ny);
    				// dbg(j, i);
    				// dbg(co, cn);
    				dsu.unite(co, cn);
    			}
    		}
    		
    		
    		// dbg(j, i);
    		// dbg(dsu.setSize(co));
    		ans = max(ans, dsu.setSize(co));
    	}
    	
    	dsu.rollback(last);
    	
    	// cout << ln;
    }
    
    cout << ans << ln;
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
