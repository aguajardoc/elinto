// Problem: Brackets
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BRCKTS/
// Memory Limit: 1536 MB
// Time Limit: 11000 ms
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

struct SegtreeSum {
	vector<int> st;
	int TREE_SIZE;
	
	SegtreeSum(int n) {
		TREE_SIZE = 1;
		while (TREE_SIZE < n) TREE_SIZE <<= 1;
		st.assign(2 * TREE_SIZE, 0);
	}
	
	void update(int i, int v) {
		i += TREE_SIZE;
		st[i] = v;
		i >>= 1;
		while (i) {
			st[i] = st[2*i] + st[2*i + 1];
			i>>=1;
		}
	}
	
	int query(int l, int r) {
		l += TREE_SIZE;
		r += TREE_SIZE;
		int res = 0;
		while(l <= r) {
			if (l & 1) res += st[l++];
			if (!(r&1)) res += st[r--];
			
			l>>=1;
			r>>=1;
		}
		
		return res;
	}
};

struct SegtreeMin {
	vector<int> st, lazy;
	int n;
	
	SegtreeMin(int n) : n(n), st(4 * n, 0), lazy(4 * n, 0) {}
	
	void build(int p, int l, int r, vector<int>& a) {
		if (l == r) {
			st[p] = a[l];
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p,l,m,a);
		build(2*p+1,m+1,r,a);
		
		st[p] = min(st[2*p], st[2 * p + 1]); 
	}
	
	void push(int p, int l, int r) {
		if (!lazy[p]) return;
		
		int m = (l + r) / 2;
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
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, v);
		update(2*p + 1, m + 1, r, i, j , v);
		
		st[p]= min(st[2*p], st[2*p + 1]);
	}
	
	int query(int p, int l, int r, int i, int j) {
		if (i > r or j < l) return INF;
		if (l >= i and r <= j) {
			return st[p];
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		return min(query(2*p, l, m, i, j), query(2* p + 1, m + 1, r, i, j));
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n - 1, l, r, v);
	}
	
	int query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

void print(SegtreeSum& st, int n) {
	for (int i = 0; i < n; i++) {
		cout << st.query(i, i) << " ";
	}
	cout << ln;
}

void print(SegtreeMin& st) {
	for (int i = 0; i < st.n; i++) {
		cout << st.query(i, i) << " ";
	}
	cout << ln;
}

void solve(int c) {
    cout << "Test " << c++ << ":\n";
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    SegtreeSum sts(n);
    SegtreeMin stm(n);
    
    vector<int> sum(n);
    int prev = 0;
    for (int i = 0; i < n; i++) {
    	int add = 1;
    	if (s[i] == ')') {
    		sts.update(i, -1);
    		add *= -1;
    	}
    	else sts.update(i, 1);
    	sum[i] = prev + add;
    	prev = sum[i];
    }
    
    
    stm.build(1, 0, n - 1, sum);
    
    int q;
    cin >> q;
    while(q--) {
    	int x;
    	cin >> x;
    	
    	if (!x) {
    		int rsum = sts.query(0, n - 1);
    		int rmin = stm.query(n-1, n - 1);
    		int rmin2 = stm.query(0, n - 1);
    		
    		// dbg(rsum);
    		// dbg(rmin2);
    		if (rmin == 0 and rmin2 >= 0) {
    			cout << "YES" << ln;
    		}
    		else cout << "NO" << ln;
    	}
    	else {
    		x--;
    		int cv = sts.query(x, x);
    		sts.update(x, cv * -1);
    		int val = -2 * cv;
    		stm.update(x, n - 1, val);
    	}
    	
    	
    	// print(sts, n);
    	// print(stm);
    	// cout << ln;
    }
    
    
}

signed main() {
    fast_cin();
    
    int T = 10;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve( i );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
