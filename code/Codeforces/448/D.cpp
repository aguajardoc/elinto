// Problem: D. Multiplication Table
// Contest: Codeforces - Codeforces Round 256 (Div. 2)
// URL: https://codeforces.com/contest/448/problem/D
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int n, m;

int f(int x) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int k = x / i;
		k = min(k, m);
		
		res += k;
	}
	
	return res;
}

void solve() {
    int k;
    cin >> n >> m >> k;
    
    
    int l = 1, r = 1e12;
    int ans = 1e12;
    
    while (l <= r) {
    	int mid = (l + r) / 2;
    	int fm = f(mid);
    	
    	if (fm >= k) {
    		ans = min(mid, ans);
    		r = mid - 1;
    	}
    	else {
    		l = mid + 1;
    	}
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
