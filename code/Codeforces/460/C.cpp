// Problem: C. Present
// Contest: Codeforces - Codeforces Round 262 (Div. 2)
// URL: https://codeforces.com/contest/460/problem/C
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

int n, m, w;
vector<int> a;

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree(int n) : n(n), st(4 * n, INF), lazy(4 * n, 0) {}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a);
		build(2*p+1, m+1, r, a);
		
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
	
	void push(int p, int l, int r) {
		if (!lazy[p]) return;
		
		int m = (l + r) / 2;
		
		st[2*p] += (m - l + 1) * lazy[p];
		st[2*p + 1] += (r - m) * lazy[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		
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
		update(2 * p + 1, m + 1, r, i ,j , v);
		
		st[p] = min(st[2*p], st[2*p + 1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return INF;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i ,j));
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
	
	int query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

bool f(int x, Segtree st) {
	int days = 0;
	for (int i = 0; i < n; i++) {
		int cur = st.query(i, i);
		if (cur < x) {
			int d = x - cur;
			days += d;
			st.update(i, min(i + w - 1, n - 1), d);
		}
	}
	
	return (days <= m);
}

void solve() {
    cin >> n >> m >> w;
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    Segtree st(n);
    
    st.build(1, 0, n - 1, a);
    
    int l = 1, r = 1e10;
    int ans = 1;
    while (l <= r) {
    	int mid = (l + r) / 2;
    	
    	if (f(mid, st)) {
    		ans = max(ans, mid);
    		l = mid + 1;
    	}
    	else {
    		r = mid - 1;
    	}
    }
    
    cout << ans << ln;
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
