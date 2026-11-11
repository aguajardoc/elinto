// Problem: Distributing Apples
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1716
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

vector<int> fac;
ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

void solve() {
	int n, m; cin >> n >> m; n += m - 1;
	int num = fac[n];
	int den = fac[n-m] * fac[m];
	den %= MOD;
	
	int res = num * binexp(den, MOD - 2);
	res %= MOD;
	
	cout << res << ln;
}

signed main() {
    fast_cin();
    
    fac.pb(1); fac.pb(1);
    for (int i = 2; i <= 3e6; i++) {
    	fac.pb(fac.back() * i);
    	fac.back() %= MOD;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
