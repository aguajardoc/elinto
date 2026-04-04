// Problem: The 67th Iteration of "Counting is Fun"
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2218/problem/G
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 676767677;
const double eps = 1e-9;

vector<int> fac = {1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> when(m);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	when[a[i]].pb(i);
    }
    
    int ans = 1;
    int tot = when[0].size();
    for (int i = 1; i < m; i++) {
    	for (auto& j : when[i]) {
    		int mn = min(a[max(0ll, j-1)], a[min(n-1,j+1)]);
    		if (mn == i-1) ans = (ans * tot) % MOD;
    		else if (mn >= a[j]) ans = 0;
    		else ans = (ans * (int)when[i-1].size()) % MOD;
    	}
    	
    	tot += (int)when[i].size();
    }
    
    cout << ans % MOD << ln;
    
    
}

signed main() {
    fast_cin();
    
    // for (int i =2 ; i <= 3e5; i++) {
    	// fac.pb(fac.back() * i);
    	// fac.back() %= MOD;
    // }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
