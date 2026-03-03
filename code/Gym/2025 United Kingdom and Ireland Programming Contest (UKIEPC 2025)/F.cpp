// Problem: F. Fell Walking
// Contest: Codeforces - 2025 United Kingdom and Ireland Programming Contest (UKIEPC 2025)
// URL: https://codeforces.com/gym/106157/problem/F
// Memory Limit: 1024 MB
// Time Limit: 3500 ms
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
	int u, v, w;
	
	bool operator<(const auto& b) {
		if (w != b.w) return w < b.w;
		else return u < v;
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> EL;
    vector<int> w(n);
    for (auto& i : w) cin >> i;
    
    
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--; 
    	
    	EL.pb({u, v, max(w[u], w[v])});
    	EL.pb({v, u, max(w[u], w[v])});
    }
    
    sort(EL.begin(), EL.end());
    int ans = INF;
    for (int i = 0; i < n; i++) {
	    int mw = w[i];
	    int mx = mw;
	    UnionFind dsu(n);
	    
	    for (auto& e : EL) {
	    	if (e.w < mw) continue;
	    	if (w[e.u] < mw) continue;
	    	if (w[e.v] < mw) continue;
	    	dsu.unionSet(e.u, e.v);
	    	mx = max(mx, e.w);
	    	mx = max(mx, w[e.v]);
	    	mx = max(mx, w[e.u]);
	    	
	    	if (dsu.isSameSet(0, 1)) break;
	    }
	    
	    if (!dsu.isSameSet(0, 1)) continue;
	    
	    // dbg(i, mx - mw);
	    
	    ans = min(ans, mx - mw);
    }
    
    cout << ans << ln;
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
