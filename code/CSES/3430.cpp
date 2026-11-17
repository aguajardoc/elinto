// Problem: Lines and Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3430
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
const int MAXX = 1e5 + 67;

struct Line {
	int m, b;
	
	Line(int m = 0, int b = -INF) : m(m), b(b) {}
	
	int eval(int x) const {
		return m * x + b;
	}
};

struct LiChao {
	vector<Line> st;
	int n;
	
	LiChao(int n) {
		this->n = n;
		st.assign(4*n, Line());
	}
	
	void add_line(int p, int l, int r, Line line) {
		int m = (l + r) / 2;
		bool lef = line.eval(l) > st[p].eval(l);
		bool mid = line.eval(m) > st[p].eval(m);
		
		if (mid) swap(st[p], line);
		
		if (l == r) return;
		
		if (lef != mid) add_line(2*p, l, m, line);
		else add_line(2*p+1, m + 1, r, line);
	}
	
	void add_segment(int p, int l, int r, int i, int j, Line line) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			add_line(p, l, r, line);
			return;
		}
		
		int m = (l + r) / 2;
		add_segment(2*p, l, m, i, j, line);
		add_segment(2*p+1, m + 1, r, i, j, line);
	}
	
	int query(int p, int l, int r, int x) {
		int res = st[p].eval(x);
		if (l == r) return res;
		
		int m = (l + r) / 2;
		
		if (x <= m) return max(res, query(2*p, l, m, x));
		else return max(res, query(2*p+1, m + 1, r, x));
	}
	
	void add_line(int m, int b) {
		add_line(1, 0, n - 1, Line(m, b));
	}
	
	void add_segment(int l, int r, int m, int b) {
		add_segment(1, 0, n - 1, l, r, Line(m, b));
	}
	
	int query(int x) {
		return query(1, 0, n - 1, x);
	}
};

void solve() {
    int n; cin >> n;
    LiChao st(MAXX);
    
    for (int i = 0; i < n; i++) {
    	int type; cin >> type;
    	
    	if (type == 1) {
    		int a, b, l, r;
    		cin >> a >> b >> l >> r;
    		st.add_segment(l, r, a, b);
    	}
    	else {
    		int x; cin >> x;
    		int res = st.query(x);
    		
    		if (res == -INF) cout << "NO" << ln;
    		else cout << res << ln;
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
