// Problem: D. Mahmoud and a Dictionary
// Contest: Codeforces - Codeforces Round 396 (Div. 2)
// URL: https://codeforces.com/contest/766/problem/D
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


string anti(string x) {
	x += '0';
	return x;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    UnionFind dsu(2 * n);
    map<string, int> idx;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	string t = anti(s);
    	idx[s] = i;
    	idx[t] = i + n;
    }
    
    for (int i = 0; i < m; i++) {
    	int type;
    	string u, v;
    	cin >> type >> u >> v;
    	
    	int U = idx[u];
    	int V = idx[v];
    	int antiu = U + n;
    	int antiv = V + n;
    	
    	if (type == 1) {
    		// u cant be in same set as anti of v
    		if (dsu.isSameSet(U, antiv) or dsu.isSameSet(V, antiu))  {
    			cout << "NO" << ln;
    		}
    		else {
    			cout << "YES" << ln;
    			dsu.unionSet(U, V);
    			dsu.unionSet(antiu, antiv);
    		}
    	}
    	else {
    		// u cant be in same set as v
    		if (dsu.isSameSet(U, V) or dsu.isSameSet(antiu, antiv)) {
    			cout << "NO" << ln;
    		}
    		else {
    			cout << "YES" << ln;
    			dsu.unionSet(U, antiv);
    			dsu.unionSet(V, antiu);
    		}
    	}
    }
    
    for (int i = 0; i < q; i++) {
    	string s, t;
    	cin >> s >> t;
    	int u = idx[s];
    	int v = idx[t];
    	int antiu = u + n;
    	int antiv = v + n;
    	
    	if (dsu.isSameSet(u, v)) {
    		cout << 1 << ln;
    	}
    	else if (dsu.isSameSet(u, antiv)) {
    		cout << 2 << ln;
    	}
    	else {
    		cout << 3 << ln;
    	}
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
