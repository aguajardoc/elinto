// Problem: E. Swap and Negate
// Contest: Codeforces - Codeforces Round 1131 (Div. 3)
// URL: https://codeforces.com/contest/2278/problem/E
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
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n; cin >> n; vector<int> a(n); for (auto& i : a) cin >> i;
    
    int ans = 0;
    vector<int> bado, bade, goodo, goode;
    for (int i = 0; i < n; i++) {
    	ans += a[i];
    	
    	if (a[i] < 0) {
    		if (i % 2) bado.pb(-a[i]);
    		else bade.pb(-a[i]);
    	}
    	else if (a[i] >= 0) {
    		if (i % 2) goodo.pb(a[i]);
    		else goode.pb(a[i]);
    	}
    }
    
    sort(bado.begin(), bado.end());
    sort(bade.begin(), bade.end());
    sort(goodo.rbegin(), goodo.rend());
    sort(goode.rbegin(), goode.rend());
    
    while (!bado.empty() and !bade.empty()) {
    	ans += 2 * bado.back() + 2 * bade.back();
    	bado.pop_back();
    	bade.pop_back();
    }
    
    while (!bado.empty() and !goode.empty()) {
    	if (goode.back() > bado.back()) break;
    	
    	ans += 2 * bado.back();
    	ans -= 2 * goode.back();
    	bado.pop_back();
    	goode.pop_back();
    }
    
    while (!bade.empty() and !goodo.empty()) {
    	if (goodo.back() > bade.back()) break;
    	
    	ans += 2 * bade.back();
    	ans -= 2 * goodo.back();
    	bade.pop_back();
    	goodo.pop_back();
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
