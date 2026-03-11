// Problem: Polynomial Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1736
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
	vector<int> st, lazy, lazy_d, marked;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy.assign(4*n, 0);
		lazy_d.assign(4*n, 0);
		marked.assign(4*n, 0);
	}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a);
		build(2*p + 1, m+1, r, a);
		
		st[p] = st[2*p] + st[2*p+1];
	}
	
	void push(int p,int l,int r){
		if (!marked[p]) return;
		
		int m = (l + r) / 2;
		int l1 = (m - l + 1);
		int l2 = (r - m);
		
		int rsum = lazy[p] + l1 * lazy_d[p];
		
		
		st[2*p] += l1 * lazy[p] + (l1 * (l1 - 1)/2) * lazy_d[p];
		st[2*p+1] += l2 * rsum + (l2 * (l2 - 1)/2) * lazy_d[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += rsum;
		lazy[p] = 0;
		
		lazy_d[2*p] += lazy_d[p];
		lazy_d[2*p+1] += lazy_d[p];
		lazy_d[p] = 0;
		
		marked[2*p] = true;
		marked[2*p+1] = true;
		marked[p] = false;
	}
	
	void update(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			int loc = 1 + l - i;
			st[p] += (r - l + 1) * loc + (r - l) * (r - l + 1) / 2;
			lazy[p] += loc;
			lazy_d[p]++;
			marked[p] = true;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j);
		update(2*p + 1, m + 1, r, i, j);
		
		st[p] = st[2*p] + st[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		return query(2*p,l, m, i, j) + query(2*p + 1, m + 1, r, i, j);
	}

	void update(int i, int j) {
		update(1, 0, n - 1, i, j);
	}
	
	int query(int i, int j) {
		return query(1, 0, n- 1, i, j);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	Segtree st(n);
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	st.build(1, 0, n - 1, a);
	
	for (int i = 0; i<  m; i++) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			st.update(l, r);
		}
		else {
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			cout << st.query(l, r) << ln;
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
