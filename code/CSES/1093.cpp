// Problem: Two Sets II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1093
// Memory Limit: 512 MB
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

int dp[502][63000];
int n;
int target;

int recurse(int idx, int sum) {
	if (idx == n) {
		return (sum == target);
	}
	
	if (dp[idx][sum] != -1) return dp[idx][sum];
	
	int res = 0;
	res += recurse(idx + 1, sum + idx);
	res %= MOD;
	res += recurse(idx + 1, sum);
	res %= MOD;
	
	return dp[idx][sum] = res;
}

void solve() {
    cin >> n;
    target = (n * (n + 1));
    fill_n(&dp[0][0], 502*63000, -1);
    if (target % 4) {
    	cout << 0 << ln;
    	return;
    }
    target >>= 2;
    
    cout << recurse(1, 0);
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
