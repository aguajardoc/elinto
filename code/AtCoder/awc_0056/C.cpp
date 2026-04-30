// Problem: C - Organizing Consecutive Bookshelves
// Contest: AtCoder - AtCoder Weekday Contest 0056 Beta
// URL: https://atcoder.jp/contests/awc0056/tasks/awc0056_c
// Memory Limit: 1024 MB
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	pref[i+1] = pref[i] + a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	int l = i, r = n;
    	
    	while (l <= r) {
    		int m = (l + r) / 2;
    		
    		int fm = pref[m] - pref[i-1];
    		
    		if (fm <= k) {
    			ans = max(ans, m - i + 1);
    			l = m + 1;
    		}
    		else {
    			r = m - 1;
    		}
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
