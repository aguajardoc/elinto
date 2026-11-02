// Problem: 1090. In the Army Now
// Contest: Timus Online Judge - USU Open Collegiate Programming Contest March'2001 Senior Session 
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1090
// Memory Limit: 64 MB
// Time Limit: 500 ms
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

const int ts = 1 << 14;
int st[21][2*ts];

void update(int i, int tree) {
	i += ts;
	st[tree][i] = 1;
	i >>= 1;
	
	while(i) {
		st[tree][i] = st[tree][2*i] + st[tree][2*i+1];
		i >>= 1;
	}
}

int query(int l, int r, int tree) {
	l += ts;
	r += ts;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res += st[tree][l++];
		if (!(r&1)) res += st[tree][r--];
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

void solve() {
    int n, k; cin >> n >> k;
    ll mx = 0;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
    	ll res = 0;
    	
    	for (int j = 0; j < n; j++) {
	    	int x; cin >> x;
	    	x = n - x + 1;
	    	res += query(0, x - 1, i);
	    	update(x, i);
    	}
    	
    	if (res > mx) {
    		mx = res;
    		ans = i;
    	}
    }
    
    cout << ans + 1 << ln;
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
