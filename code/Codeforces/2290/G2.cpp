// Problem: G2. Lakeside Trail (Hard Version)
// Contest: Codeforces - Codeforces Round 1134 (Div. 4)
// URL: https://codeforces.com/contest/2290/problem/G2
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

bool f(vector<int> a, int d, int k) {
	int n = a.size();
	int soil = 0;
	for (int i = 1; i < n - 1; i++) {
		int diff = a[i-1] - a[i];
		
		if (diff <= d) continue;
		
		a[i] += diff - d;
		soil += diff - d;
	}
	
	// cout << d << " " << soil << ln;
	// for (auto& i : a) {
		// cout << i << " ";
	// }
	// cout << ln << ln;
	
	for (int i = n - 2; i >= 0; i--) {
		int diff = a[i+1] - a[i];
		
		if (diff <= d) continue;
		
		a[i] += diff - d;
		soil += diff - d;
	}
	
	// cout << d << " " << soil << ln;
	// for (auto& i : a) {
		// cout << i << " ";
	// }
	// cout << ln << ln;
	
	return (soil <= k);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); int idx = 0, mx =0 ;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i] > mx) {
    		idx = i;
    		mx = a[i];
    	}
    }
    
    vector<int> b(n + 1);
    int ans = INF;
    for (int i = idx; i <= idx + n; i++) {
    	b[i - idx] = a[i%n];
    }
    
    int l = 0, r = INF;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	bool fm = f(b, m, k);
    	if (fm) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else l = m + 1;
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
