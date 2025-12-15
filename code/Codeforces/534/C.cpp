// Problem: C. Polycarpus' Dice
// Contest: Codeforces - Codeforces Round 298 (Div. 2)
// URL: https://codeforces.com/contest/534/problem/C
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
    int n, A;
    cin >> n >> A;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	pref[i + 1] = pref[i] + x;
    }
    
    // compare A to the sum of all other dice
    for (int i = 0; i < n; i++) {
    	ll s = pref[i] - pref[0] + pref[n] - pref[i+1];
    	ll di = pref[i + 1] - pref[i];
    	
    	ll leftLow = 0, rightLow = A - s - 1;
    	ll leftHigh = 2 + A - n, rightHigh = di;
    	
    	ll res = 0;
    	if (leftLow <= rightLow) {
    		res = rightLow;
    	}
    	if (leftHigh <= rightHigh) {
    		res += di - leftHigh + 1;
    	}
    	if (leftHigh <= rightLow) {
    		res -= (rightLow - leftHigh + 1);
    	}
    	
    	// dbg(rightLow, leftHigh, rightHigh);
    	cout << res << " ";
    }
    cout << ln;
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
