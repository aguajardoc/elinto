// Problem: G. Nastiness of Segments
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	vector<int> st;
	int TREE_SIZE = 1;
	
	Segtree(int n) {
		while (TREE_SIZE <= n) {
			TREE_SIZE <<= 1;
		}
		st.assign(2 * TREE_SIZE, INF);
	}
	
	void update(int i, int x) {
		i += TREE_SIZE;
		st[i] = x;
		i >>= 1;
		
		while (i) {
			st[i] = min(st[2*i], st[2*i+1]);
			i>>=1;
		}
	}
	
	int query(int l, int r) {
		l += TREE_SIZE;
		r += TREE_SIZE;
		int res = INF;
		
		while(l <= r) {
			if (l&1) res = min(res, st[l++]);
			if (!(r&1)) res = min(res, st[r--]);
			
			l>>=1;
			r>>=1;
		}
		
		return res;
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    Segtree st(n);
    for (int i =0; i < n; i++) {
    	int x;
    	cin >> x;
    	st.update(i, x);
    }
    
    while(q--) {
    	int t;
    	cin >> t;
    	if (t == 1) {
    		int i, x;
    		cin >> i >> x;
    		i--;
    		st.update(i, x);
    	}
    	else {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		
    		int L = 0, R = r-l;
    		int ans = 0;
    		while  (L <= R) {
    			int m = (L + R) / 2;
    			
    			int res = st.query(l, l + m);
    		
    			if (res == m) {
    				ans = 1;
    				break;
    			}
    			else if (res < m) {
    				R = m - 1;
    			}
    			else {
    				L = m + 1;
    			}
    		}
    		
    		cout << ans << ln;
    	}
    }
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
