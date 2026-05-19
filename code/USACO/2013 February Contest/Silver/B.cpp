// Problem: Problem 2. Tractor
// Contest: USACO - USACO 2013 February Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=245
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("tractor.in", "r", stdin); \
    freopen("tractor.out", "w", stdout)
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

struct Point {
	int x, y;
};

struct Entry {
	int cost;
	Point u, v;
	
	bool operator<(const auto& oth) {
		return cost < oth.cost;
	}
};

// Usage: UnionFind(n). unionSet() merges sets
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
                          // vi p is the key part
  int numSets;
public:
vi p, rank, setSize, res;   
int mx = 1;
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    res.assign(N, 0);
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j, int cost) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
   	res[y] = max({res[y], res[x], cost});
   	mx = max(mx, setSize[y]);
    --numSets;                                   // a union reduces numSets
  }
  
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> E(n, vector<int> (n, 0));
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> E[i][j];
    	}
    }
    
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<Entry> EL;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		for (auto& [dx, dy] : dir) {
    			int nx = i + dx;
    			int ny = j + dy;
    			
    			Point u = {i, j};
    			Point v = {nx, ny};
    			
    			if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
    			
    			int cost = abs(E[i][j] - E[nx][ny]);
    			EL.pb({cost, u, v});
    		}
    	}
    }
    
    sort(EL.begin(), EL.end());
    
    int ans = 0;
    UnionFind dsu(n * n);
    
    for (auto& e : EL) {
    	int X = e.u.x*n+e.u.y;
    	int Y = e.v.x*n+e.v.y;
    	if (dsu.isSameSet(X, Y)) continue;
    	
    	ans += e.cost;
    	
    	dsu.unionSet(X, Y, e.cost);
    	
    	if (dsu.mx >= (n*n) / 2) break;
    }
    
    for (int i = 0; i  <n*n; i++) {
		if (dsu.sizeOfSet(i) == dsu.mx) {
			ans = dsu.res[dsu.findSet(i)];
		}
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
