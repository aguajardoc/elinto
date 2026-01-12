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

map<int, int> dp;
int k;

int recurse(int n) {
	if (n < k) return INF;
	
	if (n == k) return dp[n] = 0;
	
	if (dp.count(n)) return dp[n];
	
	int ans = INF;
	
	ans = min(ans, recurse(n/2) + 1);
	ans = min(ans, recurse(n/2 + min(n%2, 1ll)) + 1);
	
	return dp[n] = ans;
}

void solve() {
    int n;
    cin >> n >> k;
    dp.clear();
    recurse(n);
    
    if (!dp.count(k)) {
    	cout << -1 << ln;
    	return;
    }
    
    // for (auto& i : dp) {
    	// cout << i.first << " " << i.second << ln;
    // }
    cout << dp[n] << ln;
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
