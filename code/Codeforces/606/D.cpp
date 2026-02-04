// Problem: D. Lazy Student
// Contest: Codeforces - Codeforces Round 335 (Div. 2)
// URL: https://codeforces.com/contest/606/problem/D
// Memory Limit: 256 MB
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

struct Edge {
	int w, inc, idx;
	bool operator<(const auto& a) const {
		return w < a.w;
	}
};

struct NEdge {
	int u, v, w, idx;
	bool operator<(const auto& a) const {
		return w < a.w;
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> a(m), og(m);
    map<int, int> ct;
    for (int i = 0; i < m; i++) {
    	cin >> a[i].w >> a[i].inc;
    	a[i].idx = i;
    	og[i] = a[i];
    	
    	if (a[i].inc) ct[a[i].w]++;
    }
    sort(a.begin(), a.end());
    
    vector<NEdge> EL;
    int idx = 0;
    for (int i = 0; i < n-1; i++) {
    	while (!a[idx].inc) idx++;
    	
    	EL.pb({i, i + 1, a[idx].w, a[idx].idx});
    	idx++;
    }
    
    idx = 0;
    for (int i = 3; i <= n; i++) {
    	for (int j = 1; EL.size() < m and j + 1 < i; j++) {
    		while (a[idx].inc) idx++;
    		
    		EL.pb({i-1, j-1, a[idx].w, a[idx].idx});
    		idx++;
    	}
    }
    
    sort(EL.begin(), EL.end());
    
    UnionFind dsu(n);
    
    bool poss = true;
    
    for (auto& [u, v, w, idx] : EL) {
    	if (dsu.isSameSet(u, v)) continue;
    	
    	dsu.unionSet(u, v);
    	if (ct[w] == 0) poss = false;
    	else ct[w]--;
    }
    
    if (!poss) {
    	cout << -1 << ln;
    	return;
    }
    
    sort(EL.begin(), EL.end(), [](const auto& a, const auto& b) {
    	return a.idx < b.idx;
    });
    
    for (auto& [u,v,w,idx] : EL) {
    	cout << u + 1 << " " << v + 1 << ln;
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
