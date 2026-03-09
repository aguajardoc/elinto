// Problem: F - Exactly K Steps
// Contest: AtCoder - NEC Programming Contest 2022 (AtCoder Beginner Contest 267)
// URL: https://atcoder.jp/contests/abc267/tasks/abc267_f
// Memory Limit: 1024 MB
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

// Usage: pass in a vector of parents to initialize
// Nodes are 1-indexed, but parent indices are 0-indexed
// Queries are also 1-indexed
class Tree {
  // From USACO Guide
  private:
	const int log2dist;
	vector<int> par;
	vector<vector<int>> pow2ends;
  
  public:
	Tree(const vector<int> &parents)
	    : log2dist(std::ceil(std::log2(parents.size() + 1))), par(parents),
	      pow2ends(parents.size(), vector<int>(log2dist + 1)) {

		// pow2ends[n][k] contains the 2^kth parent of node n
		// if there is no 2^kth parent, the value is -1
		for (int n = 0; n < par.size(); n++) { pow2ends[n][0] = par[n]; }
		for (int p = 1; p <= log2dist; p++) {
			for (int n = 0; n < par.size(); n++) {
				int halfway = pow2ends[n][p - 1];
				if (halfway == -1) {
					pow2ends[n][p] = -1;
				} else {
					pow2ends[n][p] = pow2ends[halfway][p - 1];
				}
			}
		}
	}

	/** @return the kth parent of node n */
	int kth_parent(int n, int k) {
		int at = n;
		// break down k into powers of 2 by looping through its bits
		for (int pow = 0; pow <= log2dist; pow++) {
			if ((k & (1 << pow)) != 0) {
				at = pow2ends[at][pow];
				if (at == -1) {
					break;  // stop when we're past the root
				}
			}
		}
		return at;
	}
};

vector<vector<int>> AL;
vector<int> dist, dL, dR, parL, parR;

void dfs(int u, int p, int depth, vector<int>& d, vector<int>& par) {
	d[u] = depth;
	par[u] = p;
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u, depth + 1, d, par);
	}
}

void solve() {
    int n;
    cin >> n;
    AL.assign(n, vector<int>());
    dist.assign(n, 0);
    parL.assign(n, 0);
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    // Get Farthest to 0
    dfs(0, -1, 0, dist, parL);
    
    int L = max_element(dist.begin(), dist.end()) - dist.begin();
    // Get farthest to L
    dist.assign(n, 0);
    parL.assign(n, 0);
    dfs(L, -1, 0, dist, parL);
    
    int R = max_element(dist.begin(), dist.end()) - dist.begin();
    
    // Get paths to R
    dR.assign(n, 0);
    parR.assign(n, 0);
    dfs(R, -1, 0, dR, parR);
    
    Tree LeftTree(parL), RightTree(parR);
    int q;
    cin >> q;
    // dbg(L, R);
    while(q--) {
    	int x, k;
    	cin >> x >> k;
    	x--;
    	
    	int r = LeftTree.kth_parent(x, k);
    	// dbg(x, r);
    	if (r == -1) {
    		r = RightTree.kth_parent(x, k);
    	}
    	
    	// dbg(x, r);
    	
    	if (r == -1) {
    		cout << -1 << ln;
    	}
    	else cout << r + 1 << ln;
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
