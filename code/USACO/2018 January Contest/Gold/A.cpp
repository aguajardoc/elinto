// Problem: Problem 1. MooTube
// Contest: USACO - USACO 2018 January Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=789
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
    freopen("mootube.in", "r", stdin); \
    freopen("mootube.out", "w", stdout)
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

struct Edge {
	int u, v, w, idx;
	bool operator<(const auto& oth) {
		if (w != oth.w) return w < oth.w;
		return idx < oth.idx;
	}
};

struct Query {
	int k, v, idx;
	bool operator<(const auto& oth) {
		if (k != oth.k) return k < oth.k;
		return idx < oth.idx;
	}
};

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

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> EL(n-1);
    
    for (int i = 0; i < n-1; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	EL[i] = {u, v, w, i};
    }
    
    sort(EL.rbegin(), EL.rend());
    
    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
    	int k, v;
    	cin >> k >> v;
    	v--;
    	queries[i] = {k, v, i};
    }
    
    sort(queries.rbegin(), queries.rend());
    
    int idx = 0;
    vector<int> ans(m);
    
    UnionFind dsu(n);
    
    for (int i = 0; i < m; i++) {
    	while (idx < n-1 and EL[idx].w >= queries[i].k) {
    		dsu.unionSet(EL[idx].u, EL[idx].v);
    		idx++;
    	}
    	
    	ans[queries[i].idx] = dsu.sizeOfSet(queries[i].v) - 1;
    }
    
    for (auto& i : ans) {
    	cout << i << ln;
    }
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
