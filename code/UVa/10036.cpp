// Problem: 10036 - Divisibility
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=977
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

int n, k;
vector<vector<int>> dp;
// idx and mod
vector<int> a;

bool recurse(int idx, int sum) {
	// dbg(idx, sum);
	if (idx == n - 1) {
		return (sum % k == 0);
	}
	
	if (dp[idx][sum % k + k] != -1) return dp[idx][sum % k + k];
	
	bool res = false;
	res |= recurse(idx + 1, sum + a[idx + 1]);
	res |= recurse(idx + 1, sum - a[idx + 1]);
	
	return dp[idx][sum % k + k] = res;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    dp.assign(n, vector<int> (2 * k + 2, -1));
    
    for (auto& i : a) cin >> i;
    cout << (recurse(0, a[0]) ? "Divisible":"Not divisible") << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
