// Problem: G. Group forming
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/G
// Memory Limit: 256 MB
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
    int n, m;
    cin >> n >> m;
    UnionFind dsu(n);
    
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	dsu.unionSet(a, b);
    }
    
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
    	g[dsu.findSet(i)].pb(i);
    }
    
    priority_queue<pair<int, int>> pq;
    set<int> included;
    for (int i = 0; i < n; i++) {
    	if (!included.insert(dsu.findSet(i)).second) continue;
    	pq.push({dsu.sizeOfSet(i), dsu.findSet(i)});
    }
    
    vector<pair<int, int>> ans;
    while (pq.size() >= 2) {
    	pair<int, int> A = pq.top();
    	pq.pop();
    	pair<int, int> B = pq.top();
    	pq.pop();
    	ans.pb({g[A.second].back(), g[B.second].back()});
    	g[A.second].pop_back();
    	g[B.second].pop_back();
    	
    	if (--A.first) pq.push(A);
    	if (--B.first) pq.push(B);
    }
    
    cout << ans.size() << ln;
    for (auto& [x, y] : ans) {
    	cout << x << " " << y << ln;
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
