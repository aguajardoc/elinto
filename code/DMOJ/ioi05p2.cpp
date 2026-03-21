// Problem: P2 - Mountain
// Contest: DMOJ - IOI '05
// URL: https://dmoj.ca/problem/ioi05p2
// Memory Limit: 256 MB
// Time Limit: 1400 ms
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
	int val = 0, pref_sum = 0, lazy = 0;
	int lc = -1;
	int rc = -1;
	bool marked = false;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.reserve(8e6);
		st.pb(Node());
	}
	
	void extend(int p, int child=3) {
		if ((child & 1) and st[p].lc == -1) {
			st[p].lc = st.size();
			st.pb(Node());
		}
		if ((child & 2) and st[p].rc == -1) {
			st[p].rc = st.size();
			st.pb(Node());
		}
	}
	
	void push(int p, int l, int r) {
		if (!st[p].marked) return;
		extend(p);
		
		int m = (l + r) / 2;
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		st[lc].val = (m - l + 1) * st[p].lazy;
		st[rc].val = (r - m) * st[p].lazy;
		
		st[lc].pref_sum = max(0, st[lc].val);
		st[rc].pref_sum = max(0, st[rc].val);
		
		st[lc].lazy = st[p].lazy;
		st[rc].lazy = st[p].lazy;
		st[p].lazy = 0;
		
		st[lc].marked = true;
		st[rc].marked = true;
		st[p].marked = false;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].val = (r - l + 1) * v;
			st[p].pref_sum = max(0, st[p].val);
			
			st[p].lazy = v;
			st[p].marked = true;
			return;
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		if (i <= m){
			extend(p, 1);
			lc = st[p].lc;
			update(lc, l, m, i, j, v);
		}
		if (j > m) {
			extend(p, 2);
			rc = st[p].rc;
			update(rc, m+1, r, i, j, v);
		}
		
		st[p].val = (lc == -1 ? 0:st[lc].val) + 
					(rc == -1 ? 0:st[rc].val);
		
		st[p].pref_sum = max((lc == -1 ? 0:st[lc].pref_sum), 
							(lc == -1 ? 0:st[lc].val) + (rc == -1 ? 0:st[rc].pref_sum));
		
	}
	
	pair<int, int> query(int p, int l, int r, int i, int j) {
		if (p == -1 or l > j or r < i) return {0,0};
		if (l >= i and r <= j) {
			return {st[p].pref_sum, st[p].val};
		}
		
		push(p, l, r);
		
		int m = (l + r) / 2;
		int lc = st[p].lc;
		int rc = st[p].rc;
		
		pair<int,int> L = query(lc, l, m, i, j);
		pair<int,int> R = query(rc, m+1,r, i, j);
		
		int PSUM = max({0, L.first, L.second + R.first});
		int SUM = max(0, L.second + R.second);
		
		return {PSUM, SUM};
	}
	
	
	void update(int i, int j, int v) {
		update(0, 0, n - 1, i, j, v);
	}
	
	int query(int i , int j) {
		return query(0, 0, n - 1, i, j).first;
	}
};

void print(Segtree& st) {
	for (int i = 0; i < 6; i++) {
		cout << st.query(i, i) << " ";
	}
	cout << ln;
}

void solve() {
	int n;
	cin >> n;
	
	Segtree st(n+1);
	
	char type;
	while (cin >> type and type != 'E') {
		// print(st);
		if (type == 'Q') {
			int h;
			cin >> h;
			
			int L = 0, R = n;
			int ans = 0;
			while(L <= R) {
				int M = (L + R) / 2;
				
				int fm = st.query(0, M);
				
				if (fm <= h) {
					ans = max(ans, M);
					L = M + 1;
				}
				else {
					R = M - 1;
				}
			}
			
			cout << ans << ln;
		}
		else {
			int i, j, v;
			cin >> i >> j >> v;
			st.update(i, j, v);
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
