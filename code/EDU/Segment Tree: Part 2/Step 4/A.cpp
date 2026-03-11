// Problem: A. Assignment, Addition, and Sum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
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
	vector<int> st, lz_add, lz_assign, marked;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lz_add.assign(4*n, 0);
		lz_assign.assign(4*n, 0);
		marked.assign(4*n, 0);
	}
	
	void push(int p, int l, int r) {
		int m = (l + r) / 2;
		
		// First assign, then add
		if (marked[p] == 1) {
			st[2*p] = (m - l + 1) * lz_assign[p];
			st[2*p+1] = (r - m) * lz_assign[p];
			
			lz_assign[2*p] = lz_assign[p];
			lz_assign[2*p+1] = lz_assign[p];
			lz_assign[p] = 0;
			
			
			lz_add[2*p] = 0;
			lz_add[2*p+1] = 0;
			
			
			marked[2*p] = true;
			marked[2*p+1] = true;
			marked[p] = false;
			
		}
		
		if (lz_add[p]) {
			st[2*p] += (m - l + 1) * lz_add[p];
			st[2*p+1] += (r - m) * lz_add[p];
			
			lz_add[2*p] += lz_add[p];
			lz_add[2*p+1] += lz_add[p];
			lz_add[p] = 0;
		}
		
	}
	
	void update(int p, int l, int r, int i, int j, int v, int t) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			if (t == 0) {
				// dbg(l, r);
				// assign, remove add!
				st[p] = (r - l + 1) * v;
				lz_add[p] = 0;
				lz_assign[p] = v;
				marked[p] = 1;
			}
			else {
				// add
				st[p] += (r - l + 1) * v;
				lz_add[p] += v;
				lz_assign[p] = lz_assign[p];
			}
			
			return;
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v, t);
		update(2*p+1, m+ 1, r, i, j, v, t);
		st[p] = st[2*p] + st[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		return query(2*p, l, m, i, j) + query(2*p+1, m + 1, r, i, j);
	}
	
	void update(int i, int j, int v, int t) {
		update(1, 0, n - 1, i, j, v, t);
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
		
		if (type <= 2) {
			int l, r, v;
			cin >> l >> r >> v;
			r--;
			
			// Literally ignore when you want to add 0 bc why bro
			if (type == 2 and v == 0) continue;
			
			st.update(l, r, v, type-1);
		}
		else {
			int l, r;
			cin >> l >> r;
			r--;
			
			cout << st.query(l, r) << ln;
		}
		
		// print(st, n);
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
