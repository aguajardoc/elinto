// Problem: L. CGCDSSQ
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/L
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

struct SparseTable {
	vector<vector<int>> st;
	int k;
	
	
	SparseTable(vector<int>& a) {
		int n = a.size();
		k = __lg(n);
		
		st.assign(k + 1, vector<int>(n));
		
		for (int i = 0; i < n; i++) {
			st[0][i] = a[i];
		}
		
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j + (1<<i) <= n; j++) {
				st[i][j] = gcd(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
			}
		}
	}
	
	int query(int l, int r) {
		int i = __lg(r - l + 1);
		
		return gcd(st[i][l], st[i][r - (1 << i) + 1]);
	}
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    SparseTable st(a);

    map<int, int> count;
    for (int i = 0; i < n; i++) {
    	int idx = i;
    	while (idx < n) {
    		int l = idx, r = n - 1;
    		int cur = st.query(i, idx);
    		
    		int last = idx;
    		
    		while (l <= r) {
    			int m = (l + r) / 2;
    			
    			int fm = st.query(i, m);
    			
    			if (fm != cur) {
    				r = m - 1;
    			}
    			else {
    				l = m + 1;
    				last = max(last, m);
    			}
    		}
    		
    		count[cur] += (last - idx + 1);
    		idx = last + 1;
    	}
    }
    
    int q;
    cin >> q;
    while(q--) {
    	int x;
    	cin >> x;
    	cout << count[x] << ln;
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
