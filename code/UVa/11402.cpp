// Problem: 11402 - Ahoy, Pirates!
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
// Memory Limit: 32 MB
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

struct Segtree {
	vector<int> st, lazy, lazyx;
	int n;
	
	Segtree(int n) : n(n), st(4 * n, 0), lazy(4 * n, -1), lazyx(4 * n, 0) {}
	
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
		if (lazy[p] == -1 and !lazyx[p]) return;
		
		int m = (l + r) / 2;
		
		if (lazy[p] != -1) {
			st[2 * p] = (m - l + 1) * lazy[p];
			st[2 * p + 1] = (r - m) * lazy[p];
			
			lazy[2 * p] = lazy[p];
			lazy[2 * p + 1] = lazy[p];
			lazyx[2 * p] = 0;
			lazyx[2 * p + 1] = 0;
			
			lazy[p] = -1;
		}
		
		if (lazyx[p]) {
			st[2 * p] = m - l + 1 - st[2 * p];
			st[2 * p + 1] = r - m - st[2 * p + 1];
			
			lazyx[2*p] ^= lazyx[p];
			lazyx[2*p + 1] ^= lazyx[p];
			
			lazyx[p] = 0;
		}
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			if (v == 2) {
				st[p] = r - l + 1 - st[p];
				lazyx[p] ^= 1;
				lazy[p] = lazy[p];
			}
			else {
				st[p] = (r - l + 1) * v;
				lazyx[p] = 0;
				lazy[p] = v;
			}
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2*p, l, m, i, j, v);
		update(2*p+1, m+1, r, i, j, v);
		
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

void solve(int c) {
    int n = 0;
    int m;
    cin >> m;
    string pirates1;
    for (int i = 0; i < m; i++) {
    	int t; string s;
    	cin >> t >> s;
    	for (int j = 0; j < t; j++) {
    		pirates1 += s;
    	}
    	n += t * (int)s.length();
    }
    
    vector<int> pirates(n);
    for (int i = 0; i < n; i++) {
    	pirates[i] = (pirates1[i] - '0');
    }
    
    Segtree st(n);
    
    st.build(1, 0, n - 1, pirates);
    
    int q;
    cin >> q;
    cout << "Case " << c++ << ":\n";
    int y = 1;
    for (int i = 1; i <= q; i++) {
    	char type;
    	int l, r;
    	cin >> type >> l >> r;
    	
    	if (type == 'F') {
    		st.update(l, r, 1);
    	}
    	if (type == 'E') {
    		st.update(l, r, 0);
    	}
    	if (type == 'I') {
    		st.update(l, r, 2);
    	}
    	if (type == 'S') {
    		cout << "Q" << y++ << ": ";
    		cout << st.query(l, r) << ln;
    	}
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve( i );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
