// Problem: 562 - Dividing coins
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
int n, sum;
vector<vector<int>> dp;
vector<int> coins;
// state: [coinsA][coinsB][idx]

ll recurse(ll coinsA, ll idx) {
	if (idx == n) {
		int coinsB = sum - coinsA;
		return abs(coinsA - coinsB);
	}
	
	if (dp[coinsA][idx] != -1) return dp[coinsA][idx];
	
	int res = 1e9;
	res = min(res, recurse(coinsA + coins[idx], idx + 1));
	res = min(res, recurse(coinsA, idx + 1));
	
	return dp[coinsA][idx] = res;
}

void solve() {
    cin >> n;
    sum = 0;
    coins.assign(n, 0);
    for (auto& i : coins) {
    	cin >> i;
    	sum += i;
    }
    dp.assign(501 * n, vector<int> (n + 1, -1));
    cout << recurse(0, 0) << ln;
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
