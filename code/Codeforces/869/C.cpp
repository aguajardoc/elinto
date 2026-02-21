// Problem: C. The Intriguing Obsession
// Contest: Codeforces - Codeforces Round 439 (Div. 2)
// URL: https://codeforces.com/contest/869/problem/C
// Memory Limit: 256 MB
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
const int MOD = 998244353;
const double eps = 1e-9;

int factorial[5001];

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		
		a = (a * a) % MOD;
		 b >>= 1;
	}
	
	return res;
}

int ncr(int n, int r) {
	int num = factorial[n];
	int den = factorial[n - r] * factorial[r];
	
	den %= MOD;
	
	int ans = num * binexp(den, MOD - 2);
	ans %= MOD;
	
	return ans;
}


int npr(int n, int r) {
	int num = factorial[n];
	int den = factorial[n - r];
	
	den %= MOD;
	
	int ans = num * binexp(den, MOD - 2);
	ans %= MOD;
	
	return ans;
}

int getR(int x, int y) {
	if (y < x) swap(x, y);
	
	int ans = 0;
	
	for (int i = 0; i <= x; i++) {
		int local = ncr(x, i) * npr(y, i);
		local %= MOD;
		ans += local;
		ans %= MOD;
	}
	
	return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
	
	int ans = getR(a, b);
	ans = (ans * getR(b, c)) % MOD;
	ans = (ans * getR(c, a)) % MOD;
	
	cout << ans << ln;
}

signed main() {
    fast_cin();
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= 5000; i++) {
    	factorial[i] = factorial[i - 1] * i;
    	factorial[i] %= MOD;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
