// Problem: C. Find Maximum
// Contest: Codeforces - Codeforces Round 205 (Div. 2)
// URL: https://codeforces.com/contest/353/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    // last one determines stuff
    // if all ones, include up to it
    // if not, check if all turned on ones are better than all up to before it
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto & i : a) cin >> i;
    string s;
    cin >> s;
    int l1 = -1;
    
    vector<int> res(n + 1, 0), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] + a[i];
    	res[i + 1] = res[i] + (s[i] == '1') * a[i];
    	if (s[i] == '1') l1 = i;
    }
    
    ll ans = res.back();
    for (int i = 0; i <= l1; i++) {
    	if (s[i] == '0') continue;
    	// all of 0 to i - 1
    	ll takeall = pref[i] - pref[0];
    	// normal from i + 1 to n
    	ll based = res[n] - res[i+1];
    	
    	// dbg(based, takeall, i);
    	ans = max(ans, based + takeall);
    }
    
    cout << ans << ln;
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
