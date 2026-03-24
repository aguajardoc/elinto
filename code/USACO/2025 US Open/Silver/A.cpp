// Problem: Problem 1. Sequence Construction
// Contest: USACO - USACO 2025 US Open Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=1518
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

void solve() {
    int m, k;
    cin >> m >> k;
    
    int cur = 0;
    vector<int> ans;
    for (int i = 7; i >= 0; i--) {
    	if (k & (1ll << i)) {
    		int ones = (1ll << i);
    		int num = (1ll << ones) - 1;
    		ans.pb(num);
    		// dbg(num);
    		cur += num;
    	}
    }
    
    if (cur > m) {
    	cout << -1 << ln;
    	return;
    }
    
    int diff = m - cur;
    if (diff == 0) {
	    cout << ans.size() << ln;
	    for (auto& i : ans) {
	    	cout << i << " " ;
	    }
	    cout << ln;
	    return;
    }
    
    // WHEN DIFF HAS AN EVEN POPCOUNT
    if (__builtin_popcountll(diff) % 2 == 0) {
	    for (int i = 0; i < 32; i++) {
	    	if (diff & (1ll << i)) {
	    		ans.pb(1ll << i);
	    		diff -= (1ll << i);
	    	}
	    }
    }
    else {
    	if (diff == 1) {
    		if (k % 2) {
    			ans.pop_back();
    			ans.pb(2);
    		}
    		else {
    			cout << -1 << ln;
    			return;
    		}
    	}
    	else {
    		int lg = __lg(diff)-1;
    		ans.pb(1ll << lg);
    		ans.pb(1ll << lg);
    		diff -= (1ll << lg);
    		diff -= (1ll << lg);
    		
    		if (diff) {
	    		for (int i = __lg(diff); i >= 0; i--) {
	    			if (diff & (1ll << i)) {
			    		ans.pb(1ll << i);
			    		diff -= (1ll << i);
			    	}
	    		}
    		}
    	}
    }
    
    cout << ans.size() << ln;
    for (auto& i : ans) {
    	cout << i << " " ;
    }
    cout << ln;
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
