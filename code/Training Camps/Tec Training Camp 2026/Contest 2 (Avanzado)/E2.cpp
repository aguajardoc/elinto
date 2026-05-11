// Problem: E. Game of Pieces
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/E
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

struct Query {
	int l, r, v;
};

struct Node {
	int mn, mx, lazy;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree (int _n) {
		n = _n;
		st.assign(4 * n, Node());
	}
	
	void push(int p, int l, int r) {
		if (st[p].lazy == 0) return;
		
		st[2*p].mn += st[p].lazy;
		st[2*p+1].mn += st[p].lazy;
		
		st[2*p].mx += st[p].lazy;
		st[2*p+1].mx += st[p].lazy;
		
		st[2*p].lazy += st[p].lazy;
		st[2*p+1].lazy += st[p].lazy;
		st[p].lazy = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].mn += v;
			st[p].mx += v;
			st[p].lazy += v;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p+1, m+1, r, i, j, v);
		
		st[p].mn = min(st[2*p].mn, st[2*p+1].mn);
		st[p].mx = max(st[2*p].mx, st[2*p+1].mx);
	}
	
	int query_max(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p].mx;
		}
		push(p, l, r);
		
		int m = (l + r) / 2;
		
		int L = query_max(2*p, l, m, i, j);
		int R = query_max(2*p+1, m+1, r, i, j);
		
		return max(L, R);
	}
	
	int query_min(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return INF;
		if (l >= i and r <= j) {
			return st[p].mn;
		}
		push(p, l, r);
		
		int m = (l + r) / 2;
		
		int L = query_min(2*p, l, m, i, j);
		int R = query_min(2*p+1, m+1, r, i, j);
		
		return min(L, R);
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
	
	int query_max(int l, int r) {
		return query_max(1, 0, n - 1, l, r);
	}
	
	int query_min(int l, int r) {
		return query_min(1, 0, n - 1, l, r);
	}
};

void solve() {
    int n;
    cin >> n;
    vector<Query> queries;
    
    vector<int> vals;
    
    for (int i = 0; i < n; i++) {
    	char type;
    	cin >> type;
    	int p,l;
    	cin >> l >> p;
    	if (type == '|') {
    		vals.pb(p);
    		vals.pb(p+1);
    		vals.pb(p-1);
    		queries.pb({p, p, l});
    	}
    	else {
    		vals.pb(p);
    		vals.pb(p+1);
    		vals.pb(p-1);
    		vals.pb(p+l-1);
    		vals.pb(p+l+1);
    		vals.pb(p+l-2);
    		queries.pb({p, p + l - 1, 1});
    	}
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    Segtree st(vals.size());
    
    for (auto& e : queries) {
    	e.l = lower_bound(vals.begin(), vals.end(), e.l) - vals.begin();
    	e.r = lower_bound(vals.begin(), vals.end(), e.r) - vals.begin();
    	
    	st.update(e.l, e.r, e.v);
    	
    	if (st.query_max(e.l, e.r) != st.query_min(e.l, e.r)) {
    		st.update(e.l, e.r, -e.v);
    		cout << "U";
    	}
    	else cout << "S";
    }
	
	cout << ln;
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
