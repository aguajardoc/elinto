// Problem: G. Card deck
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2025
// URL: https://codeforces.com/gym/106189/problem/G
// Memory Limit: 64 MB
// Time Limit: 500 ms
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
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    vector<int> pilect(n, 0), cum(n+1, 0);
    for (int i = 0; i < n; i++) {
    	pilect[i%k]++;
    }
    for (int i = 1; i <= n; i++) {
    	cum[i] = cum[i-1] + pilect[i-1];
    }
    
    
    for (int i = 1; i <= n; i++) {
    	int P = (i-1) % k, E = cum[(i-1)%k] + n/k - (i-1)/k + (P < n % k);
    	int it = 1;
    	
    	// dbg(i, P, E);
    	
    	while (E != i) {
    		P = (E-1) % k, E = cum[(E-1)%k] + n/k - (E-1)/k + (P < n % k);
    		it++; 		
    		// dbg(i, P, E);
    	}
    	
    	// dbg(it);
    	if (ans == 0) ans = it;
    	else ans = lcm(ans, it);
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
