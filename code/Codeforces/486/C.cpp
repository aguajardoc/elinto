// Problem: C. Palindrome Transformation
// Contest: Codeforces - Codeforces Round 277 (Div. 2)
// URL: https://codeforces.com/contest/486/problem/C
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

string E = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    p--;
    
    ll changeOps = 0;
    for (int i = 0; i < n / 2; i++) {
    	char a = s[i], b = s[n - i - 1];
    	ll left = 0, right = 0;
    	while (a != b) {
    		if (a == 'a') a = 'z';
    		else a--;
    		left++;
    	}
    	a = s[i], b = s[n - i - 1];
    	while (a != b) {
    		if (a == 'z') a = 'a';
    		else a++;
    		right++;
    	}
    	
    	changeOps += min(left, right);
    }
    if (!changeOps) {
    	cout << 0 << ln;
    	return;
    }
    
    ll movingOps = 0;
    if (p >= n / 2) p = n - 1 - p;
    ll leftMost = -1;
    ll rightMost = -1;
    for (ll i = 0; i < n/2; i++) {
    	if (s[i] != s[n - i - 1]) {
    		if (leftMost == -1) leftMost = i;
    		rightMost = i;
    	}
    }
    
    // go left then right
    // dbg(p);
    ll lops = 0;
    if (leftMost <= p) {
	    lops = (p - leftMost) + rightMost - leftMost;
	}
	else if (leftMost > p) {
		lops = rightMost - p;
	}
	    
    ll rops = 0;
    if (rightMost >= p) {
	    rops = (rightMost - p) + rightMost - leftMost;
	}
	else if (rightMost < p) {
		rops = p - leftMost;
	}
    
    movingOps = min(lops, rops);
    // dbg(changeOps, movingOps, leftMost, rightMost);

	ll ans = changeOps + movingOps;
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
