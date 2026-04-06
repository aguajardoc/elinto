// Problem: E. Maximum Subsequence
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/E
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

set<int> mx(vector<int> p, int m) {
	int n = p.size();
	set<int> nums;
	
	for (int i = 0; i < (1ll << n); i++) {
		int sum = 0;
		
		for (int j = 0; j < n; j++) {
			if (i & (1ll << j)) {
				sum += p[j];
				sum %= m;
			}
		}
		
		nums.insert(sum);
	}
	
	return nums;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a1, a2;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (i%2) a1.pb(x);
    	else a2.pb(x);
    }
    
    set<int> L = mx(a1, m);
    set<int> R = mx(a2, m);
    
    int ans = 0;
    for (auto& i : L) {
    	ans = max(i, ans);
    	
    	int target_low = m - 1 - i;
    	int target_high = 2 * m - 1 - i;
    	
    	if (target_low > 0) {
    		auto it = R.upper_bound(target_low);
    		if (it != R.begin()) {
    			it--;
    			ans = max(ans, i + *it);
    		}
    	}
    	
    	if (target_high > 0) {
    		auto it = R.upper_bound(target_high);
    		if (it != R.begin()) {
    			it--;
    			ans = max(ans, (i + *it) % m);
    		}
    	}
    }
    
    for (auto& i : R) ans = max(i, ans);
    
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
