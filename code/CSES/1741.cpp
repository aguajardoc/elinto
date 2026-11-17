// Problem: Area of Rectangles
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1741
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

struct Node {
	int v, ct, lazy;
	Node() {
		v = 0, ct = 0, lazy = 0;
	}
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree(int n) {
		this->n = n;
		st.assign(4*n, Node());
		build(1, 0, n - 1);
	}
	
	void build(int p, int l, int r) {
		if (l == r) {
			st[p].ct = 1;
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m);
		build(2*p + 1, m + 1, r);
		
		st[p].ct = st[2*p].ct + st[2*p+1].ct;
	}
	
	void push(int p, int l, int r) {
		if (!st[p].lazy) return;
		
		st[2*p].v += st[p].lazy;
		st[2*p+1].v += st[p].lazy;
		
		st[2*p].lazy += st[p].lazy;
		st[2*p+1].lazy += st[p].lazy;
		
		st[p].lazy = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].v += v;
			st[p].lazy += v;
			return;
		}
		
		push(p,l,r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p+1, m + 1, r, i, j, v);
		
		st[p].v = min(st[2*p].v, st[2*p+1].v);
		st[p].ct = st[2*p].ct * (st[2*p].v == st[p].v) + 
					st[2*p+1].ct*(st[2*p+1].v==st[p].v);
	}
	
	int query() {
		return st[1].ct;
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
};

struct Event {
	int time, l, r, type;
	Event(int t, int lr, int rr, int ty) : time(t), l(lr), r(rr), type(ty) {}
	
	bool operator<(const auto& oth) const {
		return time < oth.time;
	}
};

void solve() {
	int n; cin >> n;
	int N = 2e6 + 1;
	Segtree st(N);
	
	vector<Event> events;
	
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1e6; x2 += 1e6;
		y1 += 1e6; y2 += 1e6;
		
		events.pb({x1, y1, y2-1, 1});
		events.pb({x2, y1, y2-1, -1});
	}  
	
	sort(events.begin(), events.end());
	int idx = 0;
	int m = events.size();
	int ans = 0;
	for (int t = 0; t <= 2e6; t++) {
		while (idx < m and events[idx].time == t) {
			st.update(events[idx].l, events[idx].r, events[idx].type);
			idx++;
			
		}
		
		ans += (N - st.query());
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
