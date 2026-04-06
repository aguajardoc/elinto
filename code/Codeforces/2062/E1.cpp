// Problem: E1. The Game (Easy Version)
// Contest: Codeforces - Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2062/problem/E1
// Memory Limit: 512 MB
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

int timer = 0;
vector<int> tin, tout, val, visited;
vector<vector<int>> AL;

void dfs(int u) {
	visited[u] = true;
	tin[u] = timer++;
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		
		dfs(v);
	}
	
	tout[u] = timer - 1;
}

struct Node {
	int mn = INF, mx = 0, lazy = 0;
	bool operator==(const auto& oth) {
		return (mn == oth.mn and mx == oth.mx);
	}
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree (int _n) {
		n = _n;
		st.assign(4 * n, Node());
	}
	
	void merge(int p) {
		st[p].mx = max(st[2*p].mx, st[2*p+1].mx);
		st[p].mn = min(st[2*p].mn, st[2*p+1].mn);
	}
	
	void push(int p, int l, int r) {
		if (!st[p].lazy) return;
		
		st[2*p].mn = st[p].mn;
		st[2*p+1].mn = st[p].mn;
		
		st[2*p].mx = st[p].mx;
		st[2*p+1].mx = st[p].mx;
		
		st[2*p].lazy = true;
		st[2*p+1].lazy = true;
		st[p].lazy = false;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].mn = v;
			st[p].mx = v;
			st[p].lazy = true;
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2*p, l, m, i, j, v);
		update(2*p+1, m+1,r,i,j,v);
		
		merge(p);
	}
	
	Node query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return Node();
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		Node L = query(2*p, l, m, i, j);
		Node R = query(2*p + 1, m + 1, r, i, j);
		
		Node P;
		P.mn = min(L.mn, R.mn);
		P.mx = max(L.mx, R.mx);
		
		return P;
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i, j, v);
	}
	
	Node query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

void solve() {
    int n;
    cin >> n;
    timer = 0;
    val.assign(n, 0);
    tin.assign(n, 0);
    tout.assign(n, 0);
    visited.assign(n, 0);
    AL.assign(n, vector<int>());
    vector<int> valComp = {0};
    for (auto& i : val) {
    	cin >> i;
    	valComp.pb(i);
    }
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    // Coord compress
    sort(valComp.begin(), valComp.end());
    valComp.resize(unique(valComp.begin(), valComp.end()) - valComp.begin());
    int D = valComp.size();
    for (auto& i : val) {
    	i = lower_bound(valComp.begin(), valComp.end(), i) - valComp.begin();
    }
    // Flatten
    dfs(0);
    // Make segtree
    Segtree st(n);
    // Put nodes in buckets by value
    vector<vector<int>> buckets(D);
    for (int i = 0; i < n; i++) {
    	buckets[val[i]].pb(i);
    }
    // For every value, in descending order,
    Node basic;
    for (int i = D - 1; i >= 0; i--) {
	    for (auto& u : buckets[i]) {
	    	// Check if min and max outside of range is equal
	    	int L = tin[u];
	    	int R = tout[u];
	    	Node LQ; 
	    	if (L) LQ = st.query(0, L - 1);
	    	Node RQ; 
	    	if (R != n - 1) RQ = st.query(R + 1, n - 1);
	    	bool res = false;
	    	int mn = min(LQ.mn, RQ.mn);
	    	int mx = max(LQ.mx, RQ.mx);
	    	// If yes, output
	    	if (mn == mx) {
	    		cout << u + 1 << ln;
	    		return;
	    	}
	    }
	    // Update segtree with all nodes in bucket
    	for (auto& u : buckets[i]) {
    		st.update(tin[u], tout[u], val[u]);
    	}
    }
    // no :(
    cout << 0 << ln;
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
