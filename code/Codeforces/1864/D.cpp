// Problem: D. Matrix Cascade
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/D
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
    // youre forced to do it on the first cell you see no? then repeat?
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> touched(n, 0);
    int ans = 0;
    vector<int> L(n, 0), R(n, 0);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		int val = a[i][j] -'0';
    		val += touched[j];
    		val %= 2;
    		
    		if (val == 1) {
    			ans++;
    			if (j)L[j - 1]++;
    			if (j < n - 1) R[j+1]++;
    			touched[j]++;
    		}
    	}
    	
    	int cur = 0;
    	for (int j = 0; j < n; j++) {
    		touched[j] += L[j] + R[j];
    	}
    	
    	// for (auto& i : L) {
    		// cout << i << " ";
    	// }
    	// cout << ln;
    	// for (auto& i : R) {
    		// cout << i << " ";
    	// }
    	// cout << ln;
    	// for (auto& i : touched) {
    		// cout << i << " ";
    	// }
    	// cout << ln << ln;
    	
    	
    	L.erase(L.begin());
    	L.pb(0);
    	R.pop_back();
    	R.insert(R.begin(), 0);
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
