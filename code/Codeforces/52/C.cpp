// Problem: C. Circular RMQ
// Contest: Codeforces - Codeforces Testing Round 1
// URL: https://codeforces.com/contest/52/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

struct Segtree {
	vector<int> st, lazy;
	int n;
	
	Segtree(int n) : st(4 * n, 0), lazy(4 * n, 0), n(n) {}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a);
		build(2*p+1, m+1, r, a);
		st[p] = min(st[2*p], st[2*p + 1]);
	}
	
	void push(int p, int l, int r) {
		if (lazy[p] == 0) return;
		if (l == r) {
		    lazy[p] = 0;
		    return;
		}
		
		
		st[2*p] += lazy[p];
		st[2*p+1] += lazy[p];
		
		lazy[2*p] += lazy[p];
		lazy[2*p + 1] += lazy[p];
		
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (i > r or j < l) return;
		if (l >= i and r <= j) {
			st[p] += v;
			lazy[p] += v;
			return;
		}
		
		push(p,l,r);
		
		int m = (l + r) / 2;
		update(2*p, l, m, i, j, v);
		update(2*p + 1, m + 1, r, i, j, v);
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return INF;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p,l,r);
		
		int m = (l + r) / 2;
		return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
	}
	
	void update(int i, int j, int v) {
		update(1, 0, n - 1, i, j, v);
	} 
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
	
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    Segtree st(n);
    
    st.build(1, 0, n - 1, a);
    
    int q;
    cin >> q;
    cin.ignore();
    while(q--) {
    	string s;
    	getline(cin, s);
    	
    	vector<int> nums;
    	s += ' ';
    	string cur;
    	for (auto& i : s) {
    		if (i == ' ') {
    			if (cur.empty()) continue;
    			nums.pb(stoll(cur));
    			cur.clear();
    		}
    		else cur += i;
    	}
    	
    	int l = nums[0];
    	int r = nums[1];
    	
    	if (nums.size() == 3) {
    		int v = nums[2];
    		if (l <= r) {
    			st.update(l, r, v);
    		}
    		else {
    			st.update(l, n - 1, v);
    			st.update(0, r, v);
    		}
    	}
    	else {
    		if (l <= r) {
    			cout << st.query(l, r) << ln;
    		}
    		else {
    			cout << min(st.query(l, n - 1), st.query(0, r)) << ln;
    		}
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
