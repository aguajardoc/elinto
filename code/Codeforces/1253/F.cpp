// Problem: F. Cheap Robot
// Contest: Codeforces - Codeforces Round 600 (Div. 2)
// URL: https://codeforces.com/contest/1253/problem/F
// Memory Limit: 512 MB
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

struct Query {
	int target, index;
};
vector<vector<Query>> Q;
vector<int> ans;
vector<int> dist; 

// Usage: UnionFind(n). unionSet() merges sets
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
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

  void unionSet(int i, int j, int w) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (Q[x].size() > Q[y].size()) swap(x, y);           // keep x 'shorter' than y
    
    for (auto& [target, idx] : Q[x]) {
    	
    	if (ans[idx] == INF and findSet(target) == y) {
    		ans[idx] = w;
    	}
    	else if (ans[idx] == INF){
    		Q[y].pb({target, idx});
    	}
    }
    
    Q[x].clear();
    Q[x].shrink_to_fit();
    
    p[x] = y;
  }
};

struct Edge {
	int u, v, w;
	bool operator<(const auto& oth) {
		return (w < oth.w);
	}
};

void solve() {
    // Run dijkstra on all sources
    // Build new graph
    	// If v is not visited, source is u
    	// Else if sources are not the same, 
    	// Connect sources...
    	// Does that guarantee minimality?
    	// Nah
    	// Do kruskal asw
    	
    	// All queries regarding components in src u and src v are considered
    	// How to efficiently?
    	// ndp small to large 
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<pair<int, int>>> AL(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AL[u].pb({v, w});
    	AL[v].pb({u, w});
    }
    
    Q.assign(k, vector<Query>());
    ans.assign(q, INF);
    for (int i = 0; i < q; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--, b--;
    	Q[a].pb({b, i});
    	Q[b].pb({a, i});
    }
    
    UnionFind dsu(k);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> source(n, -1);
    dist.assign(n, INF);
    
    for (int i = 0; i < k; i++) {
    	pq.push({0, i});
    	dist[i] = 0;
    	source[i] = i;
    }
    
    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	
    	if (d > dist[u]) continue;
    	
    	for (auto& [v, w] : AL[u]) {
    		if (d + w <= dist[v]) {
    			dist[v] = d + w;
    			source[v] = source[u];
    			pq.push({dist[v], v});
    		}
    	}
    }
    
    vector<Edge> EL;
    for (int u = 0; u < n; u++) {
    	for (auto& [v, w] : AL[u]) {
    		if (source[u] != source[v]) {
    			int nw = dist[u] + dist[v] + w;
    			EL.pb({source[u], source[v], nw});
    		}
    	}
    }
    
    sort(EL.begin(), EL.end());
    
    for (auto& [u, v, w] : EL) {
    	dsu.unionSet(u, v, w);
    }
    
    
    for (auto& i : ans) {
    	cout << i << ln;
    }
    cout << ln;
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
