// Problem: D. Reverse Partition
// Contest: Codeforces - Codeforces Round 1135 (Div. 2)
// URL: https://codeforces.com/contest/2285/problem/D
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

map<int, vector<int>> buckets;
vector<int> fac = {1, 1};

int get(int v, int i, int n) {
	if (buckets[v].empty()) return 0;
	auto it = lower_bound(buckets[v].begin(), buckets[v].end(), i);
	return (buckets[v].end() - it);
}

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = (res * a) % MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	
	return res;
}

int ncr(int n, int r) {
	if (n < r) return 0;
	int num = fac[n];
	int den = fac[r] * fac[n-r];
	den %= MOD;
	
	int res = num * binexp(den, MOD - 2);
	res %= MOD;
	
	return res;
}

void solve() {
    int n, k, q; cin >> n >> k >> q;
    buckets.clear();
    
    vector<int> a(n); for (auto& i : a) cin >> i;
    vector<int> bwd(n), fwd(n);
    for (int i = 0, j = n - 1; i < n; i++, j--) {
    	if (!i) {
    		bwd[i] = a[j];
    		fwd[i] = a[i];
    	}
    	else {
    		bwd[i] = bwd[i-1] + a[j];
    		fwd[i] = fwd[i-1] + a[i];
    	}
    	
    	int diff = bwd[i] - fwd[i];
    	// dbg(bwd[i], fwd[i]);
    	// dbg(diff);
    	buckets[diff].pb(i);
    }
    
    int total = buckets[0].size();
    
    while (q--) {
    	int i, v; cin >> i >> v; i--;
    	
    	int i1 = i;
    	int i2 = (n - 1 - i);
    	int mn = min(i1, i2);
    	int mx = max(i1, i2);
    	
    	int sign = 1;
    	if (i2 < i1) sign = -1;
    	
    	int f = total 
    		- get(0, mn, n) + get(0, mx, n)
    		+ get(sign*v, mn, n) - get(sign*v, mx, n);
    		
    	int ans = ncr(f - 1, k - 1);
    	// dbg(f);
    	// dbg(get(sign*1,mn,n));
    	cout << ans << ln;
    }
}

signed main() {
    fast_cin();
    for (int i = 2; i <= 3e5; i++) {
    	fac.pb(fac[i-1] * i);
    	fac.back() %= MOD;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
