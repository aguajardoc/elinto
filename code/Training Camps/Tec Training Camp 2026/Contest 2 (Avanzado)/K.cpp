// Problem: K. Rectangles
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/K
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Event {
	int start, l, r, type;
	bool operator<(const auto& oth) {
		return (start < oth.start);
	}
};

struct Node {
	int st = 0, lazy = 0, lc = -1, rc = -1;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree (int _n) {
		n = _n;
		st.reserve(1e7);
		st.pb(Node());
	}
	
	void extend(int p) {
		if (st[p].lc == -1) {
			st[p].lc = st.size();
			st.pb(Node());
		}
		if (st[p].rc == -1) {
			st[p].rc = st.size();
			st.pb(Node());
		}
	}
	
	void push(int p, int l, int r) {
		if (!st[p].lazy) return;
		
		int m = (l + r) / 2;
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		st[lc].st = (m - l + 1) - st[lc].st;
		st[rc].st = (r - m) - st[rc].st;
		
		st[lc].lazy ^= 1;
		st[rc].lazy ^= 1;
		
		st[p].lazy = 0;
	}
	
	void update(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].st = (r - l + 1) - st[p].st;
			st[p].lazy ^= 1;
			return;
		}
		
		extend(p);
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(st[p].lc, l, m, i, j);
		update(st[p].rc, m + 1, r, i, j);
		
		st[p].st = st[st[p].lc].st + st[st[p].rc].st;
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p].st;
		}
		
		extend(p);
		push(p, l, r);
		
		int m = (l + r) / 2;
		
		int res = query(st[p].lc, l, m, i, j) + 
					query(st[p].rc, m + 1, r, i, j);
		
		return res;
	}
	
	void update(int i, int j) {
		update(0, 0, n - 1, i, j);
	}
	
	int query(int i, int j) {
		return query(0, 0, n - 1, i, j);
	}
};

void solve() {
    int n;
    cin >> n;
    
    vector<Event> a;
    for (int i = 0; i < n; i++) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	a.pb({x1, y1, y2-1, 0});
    	a.pb({x2, y1, y2-1, 1});
    }
    
    sort(a.begin(), a.end());
    
    Segtree st(1e9 + 1e8);
    
    int time = a[0].start;
    int prev = 0;
    int idx = 0;
    ll ans = 0;
    while (idx < a.size()) {
    	time = a[idx].start;
    	ans += 1ll * st.query(0, 1e9) * (time - prev);
    	while (idx < a.size() and a[idx].start == time) {
    		st.update(a[idx].l, a[idx].r);
    		idx++;
    	}
    	
    	prev = time;
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
