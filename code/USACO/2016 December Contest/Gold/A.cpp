// Problem: Problem 1. Moocast
// Contest: USACO - USACO 2016 December Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=669
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
    freopen("moocast.in", "r", stdin); \
    freopen("moocast.out", "w", stdout)
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

struct Point {
	int x, y;
};

struct Entry {
	int d, u, v;
	bool operator<(const auto& oth) {
		return d < oth.d;
	}
};

void solve() {
    int n;
    cin >> n;
	UnionFind dsu(n);
	
	vector<Point> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	
	vector<Entry> dist;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dist.pb({
				(a[i].x - a[j].x) * (a[i].x - a[j].x) + 
				(a[i].y - a[j].y) * (a[i].y - a[j].y),
				i, j
				}
			);
		}
	}
	
	sort(dist.begin(), dist.end());
	
	int ans = 0;
	for (auto& e : dist) {
		ans = e.d;
		
		dsu.unionSet(e.u, e.v);
		
		if (dsu.numDisjointSets() == 1) break;
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
