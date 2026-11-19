// Problem: Network Breakdown
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1677
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    set<pair<int, int>> EL;
    vector<pair<int,int>> bad;
    for (int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v;
    	u--, v--;
    	if (u > v) swap(u, v);
    	EL.insert({u, v});
    } 
    
    for (int i = 0; i < k; i++) {
    	int u, v; cin >> u >> v;
    	u--, v--;
    	if (u > v) swap(u, v);
    	if (EL.count({u, v})) {
    		EL.erase({u, v});
    		bad.pb({u, v});
    	}
    }
    
    reverse(bad.begin(), bad.end());
    UnionFind dsu(n);
    for (auto& [u, v] : EL) {
    	dsu.unionSet(u, v);
    }
    
    vector<int> ans;
    for (int i = 0; i < k; i++) {
    	ans.pb(dsu.numDisjointSets());
    	dsu.unionSet(bad[i].first, bad[i].second);
    }
    
    reverse(ans.begin(), ans.end());
    
    for (auto& i : ans) {
    	cout << i << " ";
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
