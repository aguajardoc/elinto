// Problem: E. Game of Pieces
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/E
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


struct Node {
	ll mn, mx, lazy;
	int pl, pr;
	Node() {
		mn = 0, mx = 0;
		lazy = 0;
		pl = -1, pr = -1;
	}
};

struct Segtree {
	ll n;
	vector<Node> st;
	
	Segtree(ll _n) {
		n = _n;
		// st.assign(4 * n, 0);
		st.reserve(3.2e7);
		
		st.pb(Node());
	}
	
	void extend(int p) {
		if (st[p].pl == -1) {
			st[p].pl = st.size();
			st.pb(Node());
		}
		if (st[p].pr == -1) {
			st[p].pr = st.size();
			st.pb(Node());
		}
	}
	
	void push(int p, ll l, ll r) {
		if (!st[p].lazy) return;
		
		st[st[p].pl].mn += st[p].lazy;
		st[st[p].pr].mn += st[p].lazy;
		
		st[st[p].pl].mx += st[p].lazy;
		st[st[p].pr].mx += st[p].lazy;
		
		st[st[p].pl].lazy += st[p].lazy;
		st[st[p].pr].lazy += st[p].lazy;
		
		st[p].lazy = 0;
	}
	
	void update(int p, ll l, ll r, ll i, ll j, ll v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].mn += v;
			st[p].mx += v;
			st[p].lazy += v;
			
			return;
		}
		
		extend(p);
		push(p, l, r);
		ll m = (l + r) / 2;
		
		update(st[p].pl, l, m, i, j, v);
		update(st[p].pr, m+1, r, i, j, v);
		
		// st[p] = st[2*p] + st[2*p+1];
		st[p].mn = min(st[st[p].pl].mn, st[st[p].pr].mn);
		st[p].mx = max(st[st[p].pl].mx, st[st[p].pr].mx);
	}
	
	pair<ll, ll> query(int p, ll l, ll r, ll i, ll j) {
		if (l > j or r < i) return {INF, 0ll};
		if (l >= i and r <= j) {
			return {st[p].mn, st[p].mx};
		}
		
		extend(p);
		push(p, l, r);
		
		ll m = (l + r) / 2;
		
		pair<ll, ll> L = query(st[p].pl, l, m, i, j);
		pair<ll, ll> R = query(st[p].pr, m + 1, r, i, j);
		
		return {min(L.first, R.first), max(L.second, R.second)};
	}
	
	void update(ll i, ll j, ll v) {
		update(0, 0, n - 1, i, j, v);
	}
	
	pair<ll, ll> query(ll i, ll j) {
		return query(0, 0, n - 1, i, j);
	}
};

void solve() {
    // point update of p += l
    // range min and max query
    int n;
    cin >> n;
    vector<vector<ll>> q;
    for (int i = 0; i < n; i++) {
    	char type;
    	cin >> type;
    	ll l, p;
    	cin >> l >> p;
    	
    	if (type == '|') {
    		q.pb({p, p, l});
    	}
    	else {
    		q.pb({p, p + l - 1ll, 1ll});
    	}
    }
    
	
	Segtree st(1000000010000000000);
	
	for (auto& a : q) {
		st.update(a[0], a[1], a[2]);
		pair<ll, ll> X = st.query(a[0], a[1]);

		// dbg(X.first, X.second);
		// dbg(a[0], a[1], a[2]);
		
		if (X.first == X.second) {
			cout << "S";
		}
		else {
			cout << "U";
			st.update(a[0], a[1], -a[2]);
		}
		// dbg(X.first, X.second);
		// cout << ln;
	}
	cout << ln;
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
