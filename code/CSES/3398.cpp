// Problem: Permutation Rounds
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3398
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

bitset<1000001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 1000000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000000; j+=i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b&1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b>>=1;
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    for (auto& i : a) i--;
    
    vector<int> vis(n, 0);
    map<int, int> pct;
    for (int i = 0; i < n; i++) {
    	if (vis[i]) continue;
    	
    	int cur = i;
    	int ct = 0;
    	while (!vis[cur]) {
    		vis[cur] = true;
    		cur = a[cur];
    		ct++;
    	}
    	
    	for (int j = 0; p[j] * p[j] <= ct and j < p.size(); j++) {
    		int pow = 0;
    		while (ct % p[j] == 0) {
    			ct /= p[j];
    			pow++;
    		}
    		
    		pct[p[j]] = max(pct[p[j]], pow);
    	}
    	if (ct > 1) {
    		pct[ct] = max(pct[ct], 1ll);
    	}
    }
    
    int ans = 1;
    for (auto& i : pct) {
    	int num = i.first;
    	int pow = i.second;
    	
    	ans *= binexp(num, pow);
    	ans %= MOD;
    }
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
