// Problem: C. Counting heroes
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

ll global = 1;

int dens[1000001], nums[1000001];

ll brute(ll n) {
	int num = 0, den = 0;
	for (int a = 1; a <= n; a++) {
    	for (int b = a + 1; b <= n; b++) {
    		for (int c = b + 1; c <= n; c++) {
    			den++;
    			if (a + b == c) {
    				num++;
    			}
    		}
    	}
    }
    
    // dbg(num, den);
    
    ll ans = num * binexp(den, MOD - 2);
    ans %= MOD;
    ans *= global;
    ans %= MOD;
    
    return ans;
}

void solve() {
    int n;
    cin >> n;
    
    int num = nums[n], den = dens[n];
    
    ll ans = num * binexp(den, MOD - 2);
    ans %= MOD;
    ll temp = ans;
    ans *= global;
    ans %= MOD;

    global *= temp;
    global %= MOD;
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int cum = 0;
    int ntop = 0;
    int diff = 1;
    for (int i = 1; i <= 1000000 -2; i++) {
    	int local = (i * (i + 1)) / 2;
    	cum += local;
    	cum %= MOD;
    	dens[i+2] = cum;
    	
    	ntop += diff;
    	ntop %= MOD;
    	if (!(i % 2)) diff++;
    	
    	nums[i+2] = ntop;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
