// Problem: All Manhattan Distances
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3411
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Segtree {
	vector<int> st;
	int n;
	int ts = 1;
	
	Segtree(int n) {
		this->n = n;
		while (ts < n) ts <<= 1;
		
		st.assign(2*ts, 0);
	}
	
	void update(int i, int x) {
		i += ts;
		st[i] = x;
		i >>= 1;
		
		while (i) {
			st[i] = st[2*i] + st[2*i+1];
			i >>= 1;
		}
	}
	
	int query(int l, int r) {
		l += ts;
		r += ts;
		int res = 0;
		
		while(l <= r) {
			if (l&1) res += st[l++];
			if (!(r&1)) res += st[r--];
			
			l >>= 1;
			r >>= 1;
		}
		
		return res;
	}
};

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    Segtree XST(n), YST(n);
    for (int i = 0; i < n; i++) {
    	XST.update(i, x[i]);
    	YST.update(i, y[i]);
    }
    
	__int128 ans = 0;
    for (int i = n - 2; i >= 0; i--) {
    	int RX = XST.query(i + 1, n - 1) - x[i] * (n - i - 1);
    	int RY = YST.query(i + 1, n - 1) - y[i] * (n - i - 1);
    	
    	// if (RX < 0 or RY < 0)dbg(RX, RY);
    	ans += RX + RY;
    }
    
    string r;
    while (ans) {
    	r += (ans % 10) + '0';
    	ans /= 10;
    }
    
    if (r.empty()) r = "0";
    
    reverse(r.begin(), r.end());
    
    cout << r << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
