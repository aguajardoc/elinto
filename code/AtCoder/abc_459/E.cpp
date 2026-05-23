// Problem: E - Select from Subtrees
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2026  (AtCoder Beginner Contest 459)
// URL: https://atcoder.jp/contests/abc459/tasks/abc459_e
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
const int MOD = 998244353;
const double eps = 1e-9;

vector<int> ways, want, candy;
vector<vector<int>> AL;

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

int ncr(int n, int r) {
	ll num = 1, den = 1;
	for (int i = n - r + 1; i <= n; i++) {
		i %= MOD;
		num *= i;
		num %= MOD;
	}
	for (int i = 1; i <= r; i++) {
		den *= i;
		den %= MOD;
	}
	
	ll ans = num * binexp(den, MOD - 2);
	ans %= MOD;
	
	return ans;
}

int dfs(int u, int p) {
	int rem = candy[u];
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		rem += dfs(v, u);
	}
	
	if (rem < want[u]) return 0;
	ways[u] = ncr(rem % MOD, want[u]);
	
	rem -= want[u];
	
	return rem;
}

void solve() {
    int n;
    cin >> n;
    AL.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
    	int p;
    	cin >> p;
    	p--;
    	AL[i].pb(p);
    	AL[p].pb(i);
    }
    ways.assign(n, 0);
    want.assign(n, 0);
    candy.assign(n, 0);
    
    for (auto& i : candy) cin >> i;
    for (auto& i : want) cin >> i;
    
    dfs(0, -1);
    int ans = 1;
    for (auto& i : ways) {
    	ans *= i;
    	ans %= MOD;
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
