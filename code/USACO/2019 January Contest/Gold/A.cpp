// Problem: Problem 1. Cow Poetry
// Contest: USACO - USACO 2019 January Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=897
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("poetry.in", "r", stdin); \
    freopen("poetry.out", "w", stdout)
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

int n, m, k;
int dp[5001];
vector<int> syl, classes;

int recurse(int taken) {
	if (taken >= k) {
		return (taken == k);
	}
	
	if (dp[taken] != -1) return dp[taken];
	
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		res += recurse(taken + syl[i]);
		res %= MOD;
	}
	
	return dp[taken] = res;
}

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b& 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}


void solve() {
    cin >> n >> m >> k;
    syl.assign(n, 0);
    classes.assign(n, 0);
    for (int i = 0; i < n; i++) {
    	cin >> syl[i] >> classes[i];
    }
    fill_n(&dp[0], 5001, -1);
    
    recurse(0);
    
    vector<int> class_ways(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
    	int x = recurse(syl[i]);
    	class_ways[classes[i]] += x;
    	class_ways[classes[i]] %= MOD;
    }
    
    vector<int> ct(26, 0);
    while(m--) {
    	char x;
    	cin >> x;
    	ct[x-'A']++;
    }
    
    int ans = 1;
    
    for (int i = 0; i < 26; i++) {
    	if (!ct[i]) continue;
    	
    	int local = 0;
    	for (int j = 0; j <= n; j++) {
    		local += binexp(class_ways[j], ct[i]);
    		local %= MOD;
    	}
    	
    	// dbg(i, local);
    	ans *= local;
    	ans %= MOD;
    }
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
