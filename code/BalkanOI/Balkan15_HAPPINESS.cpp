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
	int sum=0, min=INF, mxp=0, ct=0, lc=-1, rc=-1;
};

struct Segtree {
	vector<Node> st;
	int n;
	
	Segtree(int _n) {
		n = _n;
		st.reserve(2e7);
		st.pb(Node());
	}
	
	void extend(int p, int type=3) {
		if (st[p].lc == -1 and (type & 1)) {
			st[p].lc = st.size();
			st.pb(Node());
		}
		if (st[p].rc == -1 and (type & 2)) {
			st[p].rc = st.size();
			st.pb(Node());
		}
	}
	
	void merge(Node& res) {
		Node a;
		Node b;
		int L = res.lc;
		int R = res.rc;
		
		a = (L == -1 ? Node():st[L]);
		b = (R == -1 ? Node():st[R]);
		
		res.sum = a.sum + b.sum;
		res.min = min(a.min, b.min);
		if (a.mxp == a.sum and (a.sum + 1 >= b.min or b.min == INF)) {
			res.mxp = res.sum;
		}
		else res.mxp = 0;
		
		// dbg(res.sum);
		// dbg(res.min);
		// dbg(res.mxp);
		// cout << ln;
	}
	
	void update(int p, int l, int r, int i, int j, int v) {
		if (l > j or r < i) return;
		if (l >= i and r <= j) {
			st[p].ct += v;
			if (!st[p].ct) {
				st[p].sum = 0;
				st[p].min = INF;
			}
			else {
				st[p].sum = st[p].ct * i;
				st[p].min = i;
			}
			
			if (i == 1) {
				st[p].mxp = 1;
			}
			else st[p].mxp = 0;

			// dbg(i, v);
			// dbg(st[p].sum);
			// dbg(st[p].min);
			// dbg(st[p].mxp);
			// dbg(st[p].ct);
			// cout << ln;
			
			return;
		}
		
		int m = (l + r) / 2;
		if (i <= m) {
			extend(p,1);
			update(st[p].lc, l, m, i, j, v);
		}
		if (j > m) {
			extend(p, 2);
			update(st[p].rc, m+1, r, i, j, v);
		}
		
		merge(st[p]);
	}
	
	int query() {
		return (st[0].mxp == st[0].sum);
	}
	
	void update(int i, int v) {
		update(0, 0, n - 1, i, i, v);
	}
};

void solve() {
	// INIT FUNCTION
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    Segtree st(m);
    for (auto& i : a) {
    	cin >> i;
    	st.update(i,1);
    }
    
    cout << st.query() << ln;
    
    // QUERY PROCESSING
    int q;
    cin >> q;
    while (q--) {
    	int type, k;
    	cin >> type >> k;
    	vector<int> change(k);
    	for (int i = 0; i < k; i++) {
    		cin >> change[i];
    	}
    	
    	// HAPPINESS FUNCTION
    	for (auto& i : change) {
    		st.update(i, type);
    	}
    	
    	cout << st.query() << ln;
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
