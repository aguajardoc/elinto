// Problem: C. Arrange the Numbers in a Circle
// Contest: Codeforces - Educational Codeforces Round 190 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2230/problem/C
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
    int n;
    cin >> n;
    
    int fp1 = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i] != 1 and fp1 == -1) fp1 = i;
    }
    
    // only ones
    if (fp1 == -1) {
    	cout << 0 << ln;
    	return;
    }
    
    // sum is bad
    int s = 0;
    for (auto&i : a) s += i;
    if (s < 3) {
    	cout << 0 << ln;
    	return;
    }
    
    // if all non ones, all
    if (fp1 == 0) {
    	cout << s << ln;
    	return;
    }
    
    // if one ci better than 1
    if (fp1 == n - 1) {
    	cout << a.back() + min(n - 1, a.back()/2) << ln;
    	return;
    }
    
    // else
    int rem = fp1;
    int ans = 0;
    for (int i = fp1; i < n; i++) {
    	ans += a[i];
    	
    	int add = (a[i] - 2) / 2;
    	if (rem <= add) {
    		ans += rem;
    		rem = 0;
    	}
    	else {
    		ans += add;
    		rem -= add;
    	}
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
