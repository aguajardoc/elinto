// Problem: Missing Coin Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2184
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
// #define int ll
#define ld long double
#define pb push_back
 
const int INF = INT32_MAX;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Quark {
	ll val;
	int idx, l, r;
	bool operator<(const auto& oth) const {
		if (val != oth.val) return val > oth.val;
		return idx > oth.idx;
	}
	
	Quark(int i, int l, int r, ll x) {
		val = x;
		idx = i;
		this->l = l;
		this->r = r;
	}
};

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

 
void solve() {
    int n, q;
    cin >> n >> q;
    priority_queue<Quark> pq;
    vector<pair<int, int>> a;
    vector<vector<Quark>> process(n + 1);
    map<ll, pair<int, int>> val_to_lidx;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	a.push_back({x, i});
    }
    
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
    	if (val_to_lidx.count(a[i].first)) val_to_lidx[a[i].first].second = i;
    	else val_to_lidx[a[i].first].first = i;
    }
    
    FenwickTree st(n);
    
    for (int i = 0; i < q; i++) {
    	int l, r; cin >> l >> r; l--, r--;
    	Quark Q(i, l, r, 1);
    	
    	if (val_to_lidx.count(1)) {
    		process[val_to_lidx[1].second + 1].pb(Q);
    	}
    }
    
    vector<ll> ans(q, 1);
    
    for (int i = 0; i <= n; i++) {
    	while (!process[i].empty()) {
    		Quark Q = process[i].back();
	    	process[i].pop_back();
	    	
	    	ll res = st.sum(Q.l, Q.r);
	    	if (res >= Q.val) {
	    		Q.val = res + 1;
	    		ans[Q.idx] = Q.val;
	    		auto it = val_to_lidx.upper_bound(Q.val);
	    		
	    		if (it == val_to_lidx.end()) {
	    			process[n].pb(Q);
	    		}
	    		else {
	    			process[it->second.first].pb(Q);
	    		}
	    	}
    	}
    	
    	if (i < n) st.add(a[i].second, a[i].first);
    }
    
    for (int i = 0; i < q; i++) {
    	cout << ans[i] << ln;
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