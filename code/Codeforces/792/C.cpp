// Problem: C. Divide by Three
// Contest: Codeforces - Educational Codeforces Round 18
// URL: https://codeforces.com/contest/792/problem/C
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

int dp[100001][3][2];
int choice[100001][3][2];
string s;
int n;
// idx/mod3/leadingzactive

int recurse(int idx, int sum, int lza) {
	if (idx == n) {
		if (sum % 3 == 0) return 0;
		return 1e9;
	}
	
	if (dp[idx][sum%3][lza] != -1) return dp[idx][sum%3][lza];
	int res = 1e9, keep = 1e9, rem = 1e9;
	
	if (s[idx] == '0' and lza) {
		// MUST be removed
		rem = recurse(idx + 1, sum, true) + 1;
	}
	else {
		// could or could not be removed
		keep = recurse(idx + 1, sum, false);
		rem = recurse(idx + 1, sum - (s[idx] - '0'), lza) + 1;
	}
	
	if (keep < res) {
		res = keep;
		choice[idx][sum%3][lza] = 1;
	}
	if (rem < res) {
		res = rem;
		choice[idx][sum%3][lza] = 0;
	}
	
	return dp[idx][sum%3][lza] = res;
}

void solve() {
    cin >> s;
    n = s.length();
    ll add = 0;
    bool hz = false;
    for (auto& i : s) {
    	add += (i - '0');
    	if (i == '0') hz = true;
    }
    
    if (add < 3) {
    	if (hz) cout << 0 << ln;
    	else cout << -1 << ln;
    	return;
    }
    
    for (auto&i : dp) for (auto&j:i)for(auto&k:j) k = -1;
    for (auto&i : choice) for (auto&j:i)for(auto&k:j) k = -1;
    recurse(0, add, true);
    
    // rebuild
    string ans;
    int lza = 1;
    int sum = add;
    
    for (int idx = 0; idx < n; idx++) {
    	if (choice[idx][sum%3][lza] == 1) {
    		// kept
    		ans += s[idx];
    		lza = 0;
    	}
    	else {
    		// not kept :(, update
    		sum -= (s[idx] - '0');
    	}
    }
    
    // strip 0s
    reverse(ans.begin(), ans.end());
    while (!ans.empty() and ans.back() == '0') {
    	ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty() and !hz) ans = "-1";
    if (ans.empty() and hz) ans = "0";    
    
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