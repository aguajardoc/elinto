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


// From CP4: https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/unionfind_ds.cpp
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
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
    int sx = setSize[x];
    int sy = setSize[y];
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;  
                                     // a union reduces numSets
  	
  	// Ans is some number
  	// ans included sy * (sy - 1) / 2
  	// ans included sx * (sx - 1) / 2
  	// now it will exclude those and include
  	// (sx + sy) * (sx + sy - 1) / 2
  	// dbg(sx, sy);
  	// dbg(ans);
  	ans -= sy * (sy - 1)/ 2;
  	ans -= sx * (sx - 1)/ 2;
  	ans += (sx + sy) * (sx + sy - 1) / 2;
  	// dbg(ans);
  }
};

void solve() {
    int n;
    cin >> n;
    UnionFind dsu(n);
    
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<vector<int>> diff(n);
    for (int i = 1; i < n; i++) {
    	// right idx
    	// dbg(i);
    	diff[abs(a[i] - a[i - 1])].pb(i);
    }
    
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 1; i--) {
    	// For all indices that have this difference
    	// If can be added to left component do so
    	// If can be added to right component do so
    	for (auto& j : diff[i]) {
    		// left idx is automatically good
    		dsu.unionSet(j - 1, j);
    	}
    	// dbg(dsu.ans);
    	ans[i] = dsu.ans;
    }
    
    for (int i = 1; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout <<ln;
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
