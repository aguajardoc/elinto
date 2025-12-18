// Problem: 10976 - Fractions Again?!
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

void solve() {
    ll k;
    while(cin >> k) {
    	vector<pair<int, int>> ans;
    	for (ll y = k + 1; y <= 2*k; y++) {
    		ll x = (k * y) / (y - k);
    		
    		if (k == ((x * y) / (y + x))) {
    			ans.emplace_back(max(x, y), min(x, y));
    		} 
    	}
    	
    	sort(ans.rbegin(), ans.rend());
    	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    	
    	cout << ans.size() << ln;
    	for (auto& i : ans) {
    		int x = i.first;
    		int y = i.second;
    		cout << "1/" << k << " = " << "1/" << x <<" + 1/" << y << ln;
    	}
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
