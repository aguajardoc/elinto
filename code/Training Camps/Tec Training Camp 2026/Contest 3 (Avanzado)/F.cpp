// Problem: F. Omar and Trees
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/F
// Memory Limit: 256 MB
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

vector<vector<int>> AL;
vector<int> tin, tout;
int timer = 0;

void dfs(int u, int p=-1) {
	tin[u] = timer++;
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u);
	}
	
	tout[u] = timer-1;
}

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree (int _n) {
		n = _n;
		st.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
	}
	
	void push(int p, int l, int r) {
		if (!lazy[p]) return;
		
		int m = (l + r) / 2;
		st[2*p] = (m - l + 1) * lazy[p];
		st[2*p+1] = (r - m) * lazy[p];
		
		lazy[2*p] = lazy[p];
		lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p] = (r - l + 1) * v;
			lazy[p] = v;
			return;
		}
		
		push(p,l, r);
		int m = (l + r) / 2;
		
		update(2*p, l, m, i, j, v);
		update(2*p+1, m + 1, r, i, j, v),
		
		st[p] = st[2*p] + st[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		int ans = query(2*p, l, m, i, j) + query(2*p + 1, m + 1 , r, i, j);
		
		return ans;
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i, j, v);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
};

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    Segtree st(n);
    
    tin.assign(n, 0);
    tout.assign(n, 0);
    AL.assign(n, vector<int>());
    
    for (int i = 0; i < n-1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    dfs(0);
    
    for (int i = 0; i < n; i++) {
    	st.update(tin[i], tin[i], a[i]);
    }
    
    int q;
    cin >> q;
    while(q--){
    	int type;
    	cin >> type;
    	
    	if (type == 1) {
    		int u, v;
    		cin >> u >> v;
    		u--;
    		st.update(tin[u], tout[u], v);
    	}
    	else {
    		int u;
    		cin >> u;
    		u--;
    		int num = st.query(tin[u], tout[u]);
    		
    		if (num >= 4 and (num % 2 == 0 or MillerRabin(num - 2))) {
    			cout << "YES" << ln;
    		}
    		else cout << "NO" << ln;
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
