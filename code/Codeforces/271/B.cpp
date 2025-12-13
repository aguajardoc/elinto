// Problem: B. Prime Matrix
// Contest: Codeforces - Codeforces Round 166 (Div. 2)
// URL: https://codeforces.com/contest/271/problem/B
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
#define int ll
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

bitset<200001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (ll i = 2; i <= 200000; i++) {
		if (!bs[i]) continue;
		for (ll j = i * i; j <= 200000; j+=i) {
			bs[j] = false;
		}
		p.push_back(i);
	}
}

void solve() {
    int n, m;
    cin >>n >> m;
    vector<vector<int>> a(n, vector<int> (m,0));
    for (int i = 0; i < n ; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    
    ll ans = 1e9;
    for (int i = 0; i < n; i++) {
    	int local = 0;
    	for (int j = 0; j < m; j++) {
    		auto it = lower_bound(p.begin(), p.end(), a[i][j]);
    		local += *it - a[i][j];
    	}
    	ans = min(ans, local);
    }
    
    for (int i = 0; i < m; i++) {
    	int local = 0;
    	for (int j = 0; j < n; j++) {
    		auto it = lower_bound(p.begin(), p.end(), a[j][i]);
    		local += *it - a[j][i];
    	}
    	ans = min(ans, local);
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
