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

struct Node {
	int val = 0, lazy = 0;
	bool marked = false;
	
	int lc = -1;
	int rc = -1;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.reserve(1e7);
		st.pb(Node());
	}
	
	void extend(int p) {
		if (st[p].lc == -1) {
			st[p].lc = st.size();
			st.pb(Node());
		}
		if (st[p].rc == -1) {
			st[p].rc = st.size();
			st.pb(Node());
		}
	}
	
	void push(int p, int l, int r) {
		if (!st[p].marked) return;
		
		extend(p);
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		int m = (l + r) / 2;
		st[lc].val = (m - l + 1) * st[p].lazy;
		st[rc].val = (r - m) * st[p].lazy;
		
		
		st[lc].lazy = st[p].lazy;
		st[rc].lazy = st[p].lazy;
		st[p].lazy = 0;
		
		st[lc].marked = true;
		st[rc].marked = true;
		st[p].marked = false;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].val = (r - l + 1);
			st[p].lazy = 1;
			st[p].marked = true;
			return;
		}
		
		push(p, l, r);
		extend(p);
		
		int m = (l + r) / 2;
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		update(lc, l, m, i, j, v);
		update(rc, m+1,r,i,j,v);
		
		st[p].val = st[lc].val + st[rc].val;
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (p == -1 or l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p].val;
		}
		
		push(p, l, r);
		int lc = st[p].lc;
		int rc = st[p].rc;
		int m = (l + r) / 2;
		
		int res = query(lc, l, m, i, j) + query(rc, m + 1, r, i, j);
		
		return res;
	}
	
	
	void update(int i, int j, int v) {
		update(0, 0, n - 1, i, j, v);
	}
	
	int query(int i, int j) {
		return query(0, 0, n - 1, i, j);
	}
};

void solve() {
    int n;
    cin >> n;
    
    Segtree st(1e10);
    int c = 0;
    
    for (int i = 0; i < n; i++) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		l += c, r+= c;
    		int res = st.query(l, r);
    		c = res;
    		cout << res << ln;
    	}
    	else {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		l += c;
    		r += c;
    		st.update(l, r, 1);
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
