// Problem: D. Design Tutorial: Inverse the Problem
// Contest: Codeforces - Codeforces Round 270
// URL: https://codeforces.com/contest/472/problem/D
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
	int u, v, w;
	bool operator<(const auto& c) {
		return w < c.w;
	}
};

vector<int> bfs(vector<vector<pair<int, int>>>& AL, int s) {
	queue<pair<int, int>> q;
	q.push({s, 0});
	vector<int> dist(AL.size(), INF);
	dist[s] = 0;
	
	while (!q.empty()) {
		auto [u, d] = q.front();
		q.pop();
		
		for (auto& [v, w] : AL[u]) {
			if (dist[v] != INF) continue;
			
			dist[v] = d + w;
			q.push({v, dist[v]});
		}
	}
	
	return dist;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int> (n, 0));
    for (auto&i : d) for (auto& j : i) cin >> j;
    
    vector<Edge> EL;
    for (int i = 0; i < n; i++) {
    	for (int j = i+1; j < n; j++) {
    		EL.pb({i, j, d[i][j]});
    	}
    }
    sort(EL.begin(), EL.end());
    
	UnionFind dsu(n);
	
	vector<vector<pair<int, int>>> AL(n);
	
	for (auto & [u, v, w] : EL) {
		if (dsu.isSameSet(u, v)) continue;
		
		AL[u].pb({v, w});
		AL[v].pb({u, w});
		
		dsu.unionSet(u, v);
	}
	
	bool poss = true;
	for (int i = 0; i < n; i++) {
		vector<int> dist = bfs(AL, i);
		
		for (int j = 0; j < n; j++) {
			if (i != j and (d[i][j] == 0 or d[j][i] == 0)) poss = false;
			if (dist[j] == d[i][j] and dist[j] == d[j][i]) continue;
			poss = false;
		}
	}
	
	cout << (poss ? "YES":"NO") << ln;
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
