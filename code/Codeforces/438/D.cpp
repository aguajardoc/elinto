// Problem: D. The Child and Sequence
// Contest: Codeforces - Codeforces Round 250 (Div. 1)
// URL: https://codeforces.com/contest/438/problem/D
// Memory Limit: 256 MB
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
const int MOD = 1000000007;
const double eps = 1e-9;

struct Node {
	int sum=0, mx=0;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.assign(4 * n, Node());
	}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p].sum = a[l];
			st[p].mx = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a);
		build(2*p+1, m + 1, r, a);
		
		st[p].sum = st[2*p].sum + st[2*p+1].sum;
		st[p].mx = max(st[2*p].mx, st[2*p+1].mx);
	}
	
	void update(int p, int l, int r, int i, int j, int type, int v) {
		if (l > j or r < i) return;
		if (type == 1 and st[p].mx < v) return;
		if (l == r) {
			if (type == 0) {
				st[p].sum = v;
				st[p].mx = v;
			}
			else {
				st[p].sum = st[p].sum % v;
				st[p].mx = st[p].sum;
			}
			return;
		}
		
		int m = (l + r) >> 1;
		update(2*p, l, m, i, j, type, v);
		update(2*p+1, m+1, r, i, j, type, v);
		
		st[p].sum = st[2*p].sum + st[2*p+1].sum;
		st[p].mx = max(st[2*p].mx, st[2*p+1].mx);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			return st[p].sum;
		}
		
		int m = (l + r) >> 1;
		return query(2*p, l, m, i, j) + query(2*p+1, m+1,r,i,j);
	}
	
	void build(vector<int>& a) {
		build(1, 0, n - 1, a);
	}
	
	void update(int i , int j, int type, int v) {
		update(1, 0 , n - 1, i , j , type, v);
	}
	
	int query(int i, int j) {
		return query(1, 0, n - 1, i , j);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    Segtree st(n);
    st.build(a);
    
    while(m--) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		cout << st.query(l, r) << ln;
    	}
    	else if (type == 2) {
    		int l, r, x;
    		cin >> l >> r >> x;
    		l--, r--;
    		
    		st.update(l, r, 1, x);
    	}
    	else if (type == 3) {
    		int k, x;
    		cin >> k >> x;
    		k--;
    		
    		st.update(k, k, 0, x);
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

