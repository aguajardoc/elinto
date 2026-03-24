// Problem: D. Sum of XOR Functions
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/D
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 998244353;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    vector<vector<bool>> inc(32, vector<bool> (n+1, 0));
    
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	for (int j = 0; j < 31; j++) {
    		if (x & (1ll << j)) {
    			inc[j][i+1] = 1;
    		}
    		
    		inc[j][i+1] = (inc[j][i] ^ inc[j][i+1]);
    	}
    }
    
    vector<vector<vector<ll>>> prefinc(2, vector<vector<ll>> (32, vector<ll> (n+1, 0)));
    vector<vector<vector<int>>> ele(2, vector<vector<int>> (32, vector<int> (n+1, 0)));
     
    for (int i = 0; i < 31; i++) {
    	for (int j = 0; j < n; j++) {
    		int v = inc[i][j+1];
    		prefinc[v][i][j+1] = prefinc[v][i][j] + (j + 1);
    		prefinc[v][i][j+1] %= MOD;
    		prefinc[1-v][i][j+1] = prefinc[1-v][i][j];
    		prefinc[1-v][i][j+1] %= MOD;
    		
    		ele[v][i][j+1] = ele[v][i][j] + 1;
    		ele[v][i][j+1] %= MOD;
    		ele[1-v][i][j+1] = ele[1-v][i][j];
    		ele[1-v][i][j+1] %= MOD;
    	}
    }
    
    // for (int i = 0; i <= n; i++) {
    	// cout << ele[1][0][i] << " ";
    // }
    // cout << ln;
    
    ll ans = 0;
    
    for (ll j = 0; j < 31; j++) {
    	ll res = 0;
    	ll cur = 1;
    	
    	for (ll i = 0; i < n; i++) {
    		ll add = prefinc[cur][j][n] - prefinc[cur][j][i];
    		ll elem = ele[cur][j][n] - ele[cur][j][i];
    		add %= MOD;
    		elem %= MOD;
    		
    		// if (j == 0) dbg(add, elem, cur);
    		add -= i * elem;
    		add = ((add % MOD) + MOD) % MOD;
    		// dbg(add);
    		
    		res += add;
    		res %= MOD;
    		// dbg(i, j);
    		
    		if (inc[j][i+1] == cur) cur ^= 1;
    	}
    	
    	res *= (1ll << j);
    	res %= MOD;
    	ans += res;
    	ans %= MOD;
    	// dbg(j, res);
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
