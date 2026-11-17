// Problem: Monster Game II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2085
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
const int N = 200001;
const int MAXX = 1000001;
int f[N], s[N];

struct Line {
	int m, b;
	Line(int m = 0, int b = INF) : m(m), b(b) {}
	
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
	};
	
	void add_line(int p, int l, int r, Line line) {
		int m = (l + r) / 2;
		bool lef = line.eval(l) < st[p].eval(l);
		bool mid = line.eval(m) < st[p].eval(m);
		
		if (mid) swap(st[p], line);
		
		if (l == r) return;
		
		if (lef != mid) add_line(2*p, l, m, line);
		else add_line(2*p + 1, m + 1, r, line);
	}
	
	int query(int p, int l, int r, int x) {
		int res = st[p].eval(x);
		if (l == r) return res;
		
		int m = (l + r) / 2;
		
		if (x <= m) return min(res, query(2*p, l, m, x));
		else return min(res, query(2*p+1, m + 1, r, x));
	}
	
	void add_line(int m, int b) {
		add_line(1, 0, n - 1, Line(m, b));
	}
	
	int query(int x) {
		return query(1, 0, n - 1, x);
	}
};

void solve() {
    int n, x; cin >> n >> x;
    LiChao st(MAXX);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> f[i];
    
    st.add_line(x, 0);
    for (int i = 0; i < n; i++) {
    	st.add_line(f[i], st.query(s[i]));
    }
    
    cout << st.query(s[n-1]);
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
