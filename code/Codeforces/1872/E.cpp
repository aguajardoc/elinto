// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/E
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

struct Segtree {
	vector<int> st0, st1, lazy, marked;
	int n;
	
	Segtree(int _n)  {
		n = _n;
		st0.assign(4 * n, 0);
		st1.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		marked.assign(4 * n, 0);
	}
	
	void build(int p, int l, int r, vector<int>& a, string& s) {
		if (l == r) {
			if (s[l] == '0') {
				st0[p] = a[l];
			}
			else st1[p] = a[l];
			
			return;
		}
		
		int m = (l + r) / 2;
		build(2*p, l, m, a, s);
		build(2*p+1, m+1, r, a, s);
		
		st0[p] = st0[2*p] ^ st0[2*p+1];
		st1[p] = st1[2*p] ^ st1[2*p+1];
	}
	
	void push(int p, int l, int r) {
		if (!marked[p]) return;
		
		swap(st0[2*p], st1[2*p]);
		swap(st0[2*p+1], st1[2*p+1]);
		marked[2*p] ^= true;
		marked[2*p+1] ^= true;		
		marked[p] = false;
	}
	
	void update(int p, int l, int r, int i, int j) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			swap(st0[p], st1[p]);
			marked[p] ^= true;
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		update(2*p, l, m, i, j);
		update(2*p+1, m+1, r, i, j);
		
		st0[p] = st0[2*p] ^ st0[2*p+1];
		st1[p] = st1[2*p] ^ st1[2*p+1];
	}
	
	int query(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return 0;
		if (l >= i and r <= j) {
			if (v == 0) return st0[p];
			else return st1[p];
		}
		
		push(p, l, r);
		int m = (l + r) / 2;
		return query(2*p, l, m, i, j, v) ^ query(2*p+1, m + 1, r, i, j, v);
	}
	
	void build(vector<int>& a, string& s) {
		build(1, 0, n - 1, a, s);
	}
	
	void update(int i, int j) {
		update(1, 0, n - 1, i, j);
	}
	
	int query(int i, int j, int v) {
		return query(1, 0, n - 1, i, j, v);
	}

};

void solve() {
    int n;
    cin >> n;
    Segtree st(n);
    vector<int> a(n);
    string s;
    for (auto& i : a) cin >> i;
    cin >> s;
    
    st.build(a, s);
    
    int q;
    cin >> q;
    while(q--) {
    	int type;
    	cin >> type;
    	
    	if (type == 1) {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		st.update(l, r);
    	}
    	else {
    		int g;
    		cin >> g;
    		cout << st.query(0, n - 1, g) << " ";
    	}
    }
    cout << ln;
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
