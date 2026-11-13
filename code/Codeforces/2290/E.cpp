// Problem: E. Avalanche
// Contest: Codeforces - Codeforces Round 1134 (Div. 4)
// URL: https://codeforces.com/contest/2290/problem/E
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

struct Node {
	int v, lazy;
	Node() {
		v = 0, lazy = 0;
	}
};

struct Segtree {
	vector<Node> st;
	int ts = 1, n;
	
	Segtree(int n) {
		this->n = n;
		while (ts < n) ts <<= 1;
		
		st.assign(2*ts, Node());
	}
	
	void push(int p, int l, int r) {
		if (!st[p].lazy) return;
		
		int m = (l + r) / 2;
		st[2*p].v += (m - l + 1) * st[p].lazy;
		st[2*p+1].v += (r - m) * st[p].lazy;
		
		st[2*p].lazy += st[p].lazy;
		st[2*p+1].lazy += st[p].lazy;
		
		st[p].lazy = 0;
		return;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].v += (r - l + 1) * v;
			st[p].lazy += v;
			return;
		}
		
		push(p, l,r );
		
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p + 1, m + 1, r, i, j , v);
		
		st[p].v = st[2*p].v + st[2*p+1].v;
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) return st[p].v;
		push(p, l, r);
		
		int m = (l + r) / 2;
		
		int res =0;
		res += query(2*p, l, m, i, j);
		res += query(2*p + 1, m + 1, r, i, j);
		
		return res;
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i, j, v);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& i : a) cin >> i;
    Segtree st(n);
    
    for (int i = 0; i < n; i++) {
    	st.update(i, i, a[i]);
    }
    
    int moves = 0;
    for (int i = n - 1; i >= 0; i--) {
    	int j = i - k;
    	j = max(j, 0ll);
    	int here = st.query(i, i);
    	moves += here;
    	if (i) st.update(j, i - 1, here);
    }
    
    cout << (moves % 2 ? "Alice":"Bob") << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
