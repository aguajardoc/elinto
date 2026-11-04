// Problem: C. Big XOR
// Contest: Codeforces - Educational Codeforces Round 196 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2283/problem/C
// Memory Limit: 512 MB
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
    int n; cin >> n;
    int k = (1ll << (__lg(n) + 1)) - 1;
    vector<int> doubled(n + 1, 0);
    
    for (int i = __lg(n) + 1; i >= 1; i--) {
    	int cur = 0;
    	int ndoubwithprev = -1;
    	for (int j = 1; j <= n; j++) {
    		int v = j;
    		if (doubled[v]) v <<= 1;
    		if (v & (1ll << i)) {
    			// dbg(v);
    			cur ^= 1;
    		}
    		if (ndoubwithprev == -1 and v == j and (v & (1ll << (i - 1)))) ndoubwithprev = j;
    	}
    	
    	if (cur == 0) {
    		// dbg(i, ndoubwithprev);
    		doubled[ndoubwithprev] = 1;
    	}
    	
    	// int bxor = 0;
		// for (int j = 1; j <= n; j++) {
			// bxor ^= (j << (doubled[j]));
			// cout << doubled[j] << " ";
		// }
		// cout << ln << ln;
		// dbg(bxor, k);
    }
    
    int bxor = 0;
    for (int i = 1; i <= n; i++) {
    	bxor ^= (i << (doubled[i]));
    	cout << doubled[i] << " ";
    }
    cout << ln;
    // dbg(bxor >= 2* k);
    
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
