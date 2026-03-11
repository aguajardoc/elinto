// Problem: B. Add Arithmetic Progression On Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
// Memory Limit: 256 MB
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
	vector<int> st, lazy_a, lazy_d, marked;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4*n, 0);
		lazy_a.assign(4*n, 0);
		lazy_d.assign(4*n, 0);
		marked.assign(4*n, 0);
	}
	
	void push(int p, int l, int r) {
		if (!marked[p]) return;
		
		int m = (l + r) / 2;
		int range1 = m - l;
		int range2 = r - (m + 1);
		// local a is once again offset by its length
		int loc2 = lazy_a[p] + (m - l + 1) * lazy_d[p];
		
		st[2*p] += (m - l + 1) * lazy_a[p] + (range1 * (range1 + 1) / 2) * lazy_d[p];
		st[2*p+1] += (r - m) * loc2 + (range2 * (range2 + 1) / 2) * lazy_d[p];
		
		lazy_a[2*p] += lazy_a[p];
		lazy_a[2*p+1] += loc2;
		lazy_a[p] = 0;
		
		lazy_d[2*p] += lazy_d[p];
		lazy_d[2*p+1] += lazy_d[p];
		lazy_d[p] = 0;
		
		marked[2*p] = true;
		marked[2*p+1] = true;
		marked[p] = false;
	}
	
	void update(int p, int l, int r, int i, int j, int a, int d) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			int local = a + (l - i) * d; // offset by diff btw current l and range's i
			int range = r - l;
			st[p] += (r - l + 1) * local + (range * (range + 1) / 2) * d;
			lazy_a[p] += local;
			lazy_d[p] += d;
			marked[p] = true;
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2*p, l, m, i, j, a, d);
		update(2*p+1, m + 1, r, i, j, a, d);
		
		st[p] = st[2*p] + st[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		
		return query(2*p, l, m, i, j) + query(2*p + 1, m + 1, r, i, j);
	}
	
	void update(int i, int j, int a, int d) {
		update(1, 0, n - 1, i,j, a, d);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
};

void print(Segtree& st, int n) {
	for (int i = 0; i < n; i++) {
		cout << st.query(i, i) << " ";
	}
	cout << ln;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	Segtree st(n);
	
	for (int i = 0; i< m; i++) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int l, r, a, d;
			cin >> l >> r >> a >> d;
			l--, r--;
			
			st.update(l, r, a, d);
			// print(st, n);
		}
		else {
			int x;
			cin >> x;
			x--;
			
			cout << st.query(x, x) << ln;
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
