// Problem: C. Quiz
// Contest: Codeforces - Codeforces Round 196 (Div. 2)
// URL: https://codeforces.com/contest/337/problem/C
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
const int MOD = 1000000009;
const double eps = 1e-9;

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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll y = m - n + n / k;
    
    if (y <= 0) {
    	cout << m << ln;
    	return;
    }
    
    ll ans = binexp(2, y + 1);
    ans = (ans - y - 2);
    ans = ((ans % MOD) + MOD) % MOD;
    ans *= k;
    ans = ((ans % MOD) + MOD) % MOD;
    ans += m;
    ans = ((ans % MOD) + MOD) % MOD;
    
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
