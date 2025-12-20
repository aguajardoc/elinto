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

ll f(ll x, vector<int>& a, int n) {
	vector<int> r(n,0);
    r[0] = x; // now i can maximize?
    for (int i = 1; i < n; i++) {
    	r[i] = (a[i] - a[i - 1]) - r[i - 1];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
    	if (r[i] > 0 and r[i - 1] > 0) ans++;
    }
    
    return ans;
}

ll ternary(vector<int>& a, int n) {
	ll ans = 0;
	ll l = 0, r = a[1];
	while (l <= r) {
		ll delta = (r - l) / 3;
		ll m1 = l + delta;
		ll m2 = r - delta;
		
		ll fm1 = f(m1, a, n);
		ll fm2 = f(m2, a, n);
		// dbg(l, r, fm1, fm2);
		
		ans = max({ans, fm1, fm2});
		if (fm1 > fm2) {
			r = m2 - 1;
		}
		else {
			l = m1 + 1;
		}
	}
	
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    if (n == 1) {
    	cout << 0 << ln;
    	return;
    }
    // sum of any two adjacent radii must be equal to diff
    // maximize first and last?
    for (auto& i : a) i *= 2;
    // now radii can only be integers
    cout << ternary(a, n) << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
