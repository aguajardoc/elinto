// Problem: I. The Volcano Eruption
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/I
// Memory Limit: 64 MB
// Time Limit: 5000 ms
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

struct Circle {
	int x, y, r;
};

bool intersects(Circle a, Circle b) {
	int LHS = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	int RHS = (a.r + b.r) * (a.r + b.r);
	
	return (LHS <= RHS);
}

void solve() {
    int n, w, l;
    cin >> n >> w >> l;
    vector<Circle> a(n);
    
    for (int i = 0; i < n; i++) {
    	cin >> a[i].x >> a[i].y >> a[i].r;
    }
    
    UnionFind dsu(n);
    
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		if (intersects(a[i], a[j])) {
    			dsu.unionSet(i, j);
    		}
    	}
    }
    
    int ans = 0;
    vector<int> left(n, INF), right(n, -INF);
    for (int i = 0; i < n; i++) {
    	int idx = dsu.findSet(i);
    	left[idx] = min(left[idx], a[i].x - a[i].r);
    	right[idx] = max(right[idx], a[i].x + a[i].r);
    }
    
    for (int i = 0; i < n; i++) {
    	if (left[i] <= 0 and right[i] >= w) ans++;
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
