// Problem: E - Period of Stable Temperature
// Contest: AtCoder - AtCoder Weekday Contest 0065 Beta
// URL: https://atcoder.jp/contests/awc0065/tasks/awc0065_e
// Memory Limit: 1024 MB
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

const int TREE_SIZE = 1 << 20;
int mn[2 * TREE_SIZE], mx[2*TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	mn[i] = x;
	mx[i] = x;
	i >>= 1;
	
	while(i) {
		mn[i] = min(mn[2*i],mn[2*i+1]);
		mx[i] = max(mx[2*i],mx[2*i+1]);
		
		i >>= 1;
	}
}
int n, k, d;

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int MN = INF;
	int MX = -INF;
	
	while (l <= r) {
		if (l&1) {
			MN = min(MN, mn[l]);
			MX = max(MX, mx[l]);
			
			l++;
		}
		if (!(r&1)) {
			MN = min(MN, mn[r]);
			MX = max(MX, mx[r]);
			
			r--;
		}
		
		l >>= 1;
		r >>= 1;
	}
	
	return (MX - MN) <= d;
}

void solve() {
    cin >> n >> k >> d;
    
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	update(i, x);
    }
    
    int ans = -1;
    
    for (int i = 0; i < n; i++) {
    	int l = i, r = n - 1;
    	int local = -1;
    	while (l <= r) {
    		int m = (l + r) / 2;
    		
    		int fm = query(i, m);
    		
    		if (fm) {
    			local = max(local, m - i + 1);
    			l = m + 1;
    		}
    		else {
    			r = m - 1;
    		}
    	}
    	
    	if (local >= k) {
    		ans = max(ans, local);
    	}
    }
    
    cout << ans << ln;
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
