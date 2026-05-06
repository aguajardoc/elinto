// Problem: Zhily and Barknights
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2224/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
const int MOD = 998244353;
const double eps = 1e-9;

struct Elem {
	int val, i, j;
	bool operator<(const auto& oth) {
		if (val != oth.val) return val < oth.val;
		if (j != oth.j) return j < oth.j;
		else return i < oth.i;
	}
};

struct Segtree {
	vector<int> st;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4 * n, 0);
	}
	
	void update(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p]++;
			return;
		}
		int m = (l + r) / 2;
		
		update(2 * p, l, m, i, j);
		update(2*p + 1,m + 1, r, i, j);
		
		st[p] = st[2*p] + st[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		int m = (l + r) / 2;
		
		int res = query(2 * p, l, m, i, j) +
				query(2 * p + 1, m + 1, r, i, j);
		
		return res;
	}
	
	void update(int i) {
		update(1, 0, n - 1, i, i);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
};

vector<int> fac = {1, 1};

ll binexp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(b.begin(), b.end());
    
    vector<vector<int>> mat(n, vector<int> (n, 0));
    vector<Elem> order;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		mat[i][j] = a[i] * b[j];
    		order.pb({mat[i][j], j, i});
    	}
    }
    
    sort(order.begin(), order.end());
    
    // keep how many in cols after mine
    Segtree st(n);
    // keep how many in my row
    vector<Segtree> rows(n, Segtree(n));
    
    int num = 0;
    
    for (auto& e : order) {
    	// get how many
    	int after = st.query(e.j + 1, n - 1);
    	int mine = rows[e.i].query(e.j + 1, n - 1);
    	
    	int res = after - mine;
    	// dbg(e.val, e.i, e.j);
    	// dbg(after, mine);
    	// dbg(res*fac[n-2]);
    	// cout << ln;
    	
    	num += (res * fac[n-2])%MOD;
    	num %= MOD;
    	
    	st.update(e.j);
    	rows[e.i].update(e.j);
    }
    
    int den = fac[n];
    // dbg(num, den);
    int ans = (num * binexp(den, MOD - 2)) % MOD;
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    for (int i = 2; i <= 2001; i++) {
    	fac.pb(fac.back() * i);
    	fac.back() %= MOD;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
