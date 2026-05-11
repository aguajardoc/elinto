// Problem: I. Rabid Rabbit
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/I
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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

vector<int> fib = {1, 2};

struct Segtree {
	int TREE_SIZE = 1;
	vector<vector<int>> stmn, stmx;
	
	Segtree(int n) {
		while (TREE_SIZE <= n) TREE_SIZE <<= 1;
		stmn.assign(45, vector<int> (2 * TREE_SIZE, INF));
		stmx.assign(45, vector<int> (2 * TREE_SIZE, 0));
	}
	
	void update(int tree, int i, int x, bool mode) {
		i += TREE_SIZE;
		if (!mode) stmn[tree][i] = x;
		else stmx[tree][i] = x;
		i >>= 1;
		
		while (i) {
			if (!mode) stmn[tree][i] = min(stmn[tree][2*i], stmn[tree][2*i+1]);
			else stmx[tree][i] = max(stmx[tree][2*i], stmx[tree][2*i+1]);

			i >>= 1;
		}
	}
	
	bool query(int tree, int l, int r) {
		int L = l, R = r;
		l += TREE_SIZE;
		r += TREE_SIZE;
		int mn = INF, mx = 0;
		
		while (l <= r) {
			if (l & 1) {
				mn = min(mn, stmn[tree][l]);
				mx = max(mx, stmx[tree][l]);
				l++;
			}
			if (!(r&1)) {
				mn = min(mn, stmn[tree][r]);
				mx = max(mx, stmx[tree][r]);
				r--;
			}
			
			l >>= 1;
			r >>= 1;
		}
		
		// dbg(mn);
		// dbg(mx);
		return (mx >= L and mn <= R);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    Segtree st(n);
    
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    map<int, int> fafter, fbefore;
    
    // after
    vector<int> curA(45, INF);
    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j < 45; j++) {
    		int comp = fib[j] - a[i];
    		
    		if (fafter.count(comp)) {
    			curA[j] = min(curA[j], fafter[comp]);
    		}
    		st.update(j, i, curA[j], 0);
    	}
    	fafter[a[i]] = i;
    }
    
    // before
    vector<int> curB(45, -INF);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 45; j++) {
    		int comp = fib[j] - a[i];
    		
    		if (fbefore.count(comp)) {
    			curB[j] = max(curB[j], fbefore[comp]);
    		}
    		st.update(j, i, curB[j], 1);
    	}
    	fbefore[a[i]] = i;
    }
    
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	
    	int ans = 0;
    	for (int i = 0; i < 45; i++) {
    		ans += st.query(i, l, r);
    	}
    	
    	cout << ans << ln;
    }
}

signed main() {
    fast_cin();
    
    for (int i = 0; fib.back() <= 3e9; i++) {
    	fib.pb(fib[fib.size() - 2] + fib.back());
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
