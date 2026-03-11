// Problem: E. Placing Jinas
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/E
// Memory Limit: 512 MB
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

vector<int> facs;

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b&1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1, 0);
	for (auto& i : a) cin >> i;
    
    int ans = 0;
    vector<int> k(a[0] + 1, 0);
    int idx = 0;
    for (int i = a[0]; i >= 0; i--) {
    	while (idx <= n and a[idx] >= i) {
    		idx++;
    	}
    	
    	k[i] = idx;
    }
    
    
    // Get ans
    for (int i = 1; i <= a[0]; i++) {
    	int local = facs[k[i] + i - 1];
    	local *= binexp(facs[k[i] - 1], MOD - 2);
    	local %= MOD;
    	local *= binexp(facs[i], MOD - 2);
    	local %= MOD;
    	
    	ans += local;
    	ans %= MOD;
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    facs = {1, 1};
    for (int i = 2; i <= 6.7e5; i++) {
    	facs.pb(facs.back() * i);
    	facs.back() %= MOD;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
