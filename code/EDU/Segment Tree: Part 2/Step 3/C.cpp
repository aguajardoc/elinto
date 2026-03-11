// Problem: C. Addition and First element at least X
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/C
// Memory Limit: 1024 MB
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
	vector<int> st, lazy, marked;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy.assign(4*n, 0);
		marked.assign(4*n, 0);
	}
	
	void push(int p, int l, int r) {
		if (!marked[p]) return;
		
		int m = (l + r) / 2;
		
		st[2*p] += lazy[p];
		st[2*p+1] += lazy[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
		
		marked[2*p] = 1;
		marked[2*p+1] = 1;
		marked[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			st[p] += v;
			lazy[p] += v;
			marked[p] = 1;
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p+1, m + 1, r, i, j, v);
		
		st[p] = max(st[2*p], st[2*p+1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		return max(query(2*p, l, m, i, j), query(2*p+1, m +1, r, i, j));
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i , j, v);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
};

void print(Segtree& st, int n) {
	for (int i = 0; i < n; i++) {
		cout << st.query(i,i) << " ";
	}
	cout << ln;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	Segtree st(n);
	
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			r--;
			
			st.update(l, r, v);
			
			// print(st, n);
		}
		else {
			int x, l;
			cin >> x >> l;
			
			int L = l, R = n - 1;
			int ans = INF;
			while (L <= R) {
				int M = (L + R) / 2;
				
				int fm = st.query(l, M);
				
				if (fm >= x) {
					ans = min(ans, M);
					R = M - 1;
				}
				else {
					L = M + 1;
				}
			}
			
			if (ans == INF) ans = -1;
			
			cout << ans << ln;
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
