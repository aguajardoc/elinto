// Problem: Problem 2. Reachable Pairs
// Contest: USACO - USACO 2025 January Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=1474
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

// Usage: UnionFind(n). unionSet() merges sets
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
public:
vi p, rank, setSize;                           // vi p is the key part
  int numSets;
  int ans = 0;
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
   
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
   	ans -= ((setSize[x]) * (setSize[x] - 1)) / 2;
   	ans -= ((setSize[y]) * (setSize[y] - 1)) / 2;
   	// dbg(i, j);
   	// dbg(setSize[x], setSize[y]);
   	setSize[y] += setSize[x];                    // combine set sizes at y
    ans += ((setSize[y]) * (setSize[y] - 1)) / 2;
    --numSets;                                   // a union reduces numSets
  }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    vector<vector<int>> AL(2*n), NAL = AL;
    
    UnionFind prev(n);
    
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	prev.unionSet(u, v);
    	
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    UnionFind dsu(2*n);
    
    for (int u = 0; u < n; u++) {
    	if (s[u] == '1') {
    		int superNode = prev.findSet(u);
    		NAL[u].pb(n + superNode);
    		NAL[n + superNode].pb(u);
	    	for (auto& v : AL[u]) {
	    		NAL[n + superNode].pb(v);
	    		NAL[v].pb(n + superNode);
	    	}
	    }
	    else {
	    	for (auto& v : AL[u]) {
	    		NAL[u].pb(v);
	    		NAL[v].pb(u);
	    	}
	    }
    }
    
    
    for (int i = n; i < 2 * n; i++) {
    	dsu.setSize[i] = 0;
    }
    
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
    	if (s[i] == '1') {
    		int superNode = prev.findSet(i);
    		dsu.unionSet(n+superNode, i);
    		for (auto& v : NAL[n+i]) {
    			if (v > i) dsu.unionSet(n+superNode, v);
    		}
    	}
    	else {
    		for (auto& v : NAL[i]) {
    			if (v > i) dsu.unionSet(i, v);
    		}
    	}
    	
    	ans[i] = dsu.ans;
    }
    
    for (auto& i : ans) {
    	cout << i << ln;
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
