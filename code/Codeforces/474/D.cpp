// Problem: D. Flowers
// Contest: Codeforces - Codeforces Round 271 (Div. 2)
// URL: https://codeforces.com/contest/474/problem/D
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

void solve() {
    int t, k;
    cin >> t >> k;
    
    vector<int> f = {1};
    for (int i = 1; i <= 1e6; i++) {
    	int next = f[i - 1];
    	if (i - k >= 0) next += f[i - k];
    	next %= MOD;
    	
    	f.pb(next);
    }
    
    vector<int> pf(1e6 + 1e5, 0);
    for (int i = 0; i <= 4e5; i++) {
    	pf[i + 1] = pf[i] + f[i];
    	pf[i + 1] %= MOD;
    } 
    
    while(t--) {
    	int a, b;
    	cin >> a >> b;
    	ll ans = pf[b + 1] - pf[a];
    	ans = ((ans % MOD) + MOD) % MOD;
    	
    	cout << ans << ln;
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
