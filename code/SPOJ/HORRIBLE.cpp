// Problem: Horrible Queries
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/HORRIBLE/
// Memory Limit: 1536 MB
// Time Limit: 2329 ms
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

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree(int n) : n(n), st(4 * n, 0), lazy(4 * n, 0) {}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2 * p, l, m, a);
		build(2 * p + 1, m + 1, r, a);
		
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	
	void push(int p, int l, int r) {
		if (lazy[p] == 0) return;
		
		int m = (l + r) / 2;
		st[2 * p] += (m - l + 1) * lazy[p];
		st[2 * p + 1] += (r - m) * lazy[p];
		
		lazy[2 * p] += lazy[p];
		lazy[2 * p + 1] += lazy[p];
		
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			st[p] += (r - l + 1) * v;
			lazy[p] += v;
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, v);
		update(2 * p + 1, m + 1, r, i, j , v);
		
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		return query(2 * p, l, m, i, j) + query(2 * p + 1, m + 1, r, i, j);
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
	
	int query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    Segtree st(n);
    
    for (int i = 0; i < m ;i++) {
    	int type;
    	cin >> type;
    	if (!type) {
    		int x, y, v;
    		cin >> x >> y >> v;
    		st.update(x - 1, y - 1, v);
    	}
    	else {
    		int x, y;
    		cin >> x >> y;
    		cout << st.query(x - 1, y - 1) << ln;
    	}
    }
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
