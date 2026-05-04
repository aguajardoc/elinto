// Problem: D - Repainting the Fence
// Contest: AtCoder - AtCoder Weekday Contest 0053 Beta
// URL: https://atcoder.jp/contests/awc0053/tasks/awc0053_d
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

struct Segtree {
	vector<int> st, lazy;
	int n;
	// set
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy.assign(4*n, 0);
	}
	
	void push(int p, int l, int r) {
		if (!lazy[p]) return;
		
		st[2*p] = lazy[p];
		st[2*p+1] = lazy[p];
		
		lazy[2*p] = lazy[p];
		lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int c) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p] = c;
			lazy[p] = c;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, c);
		update(2*p+1, m+1, r, i, j, c);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		int ans = query(2*p, l, m, i, j) + query(2*p+1, m + 1, r, i, j);
		return ans;
	}
	
	
	void update(int i, int j, int c) {
		update(1, 0, n - 1, i, j, c);
	}
	
	int query(int l, int r) {
		return query(1, 0, n- 1, l, r);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    Segtree st(n);
    
    for (int i = 0; i < m; i++) {
    	int l, r, c;
    	cin >> l >> r >> c;
    	l--, r--;
    	
    	st.update(l, r, c);
    }
    
    for (int i = 0; i < n; i++) {
    	cout << st.query(i, i) << " ";
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
