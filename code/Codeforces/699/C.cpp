// Problem: C. Vacations
// Contest: Codeforces - Codeforces Round 363 (Div. 2)
// URL: https://codeforces.com/contest/699/problem/C
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
vector<vector<int>> dp;
int n;
vector<int> a;

int recurse(int idx, int act) {
	if (idx == n) {
		return 0;
	}
	if (dp[act][idx] != -1) return dp[act][idx];
	
	int days = 1e9;
	if (a[idx] == 0) {
		days = min(days, recurse(idx + 1, 0) + 1);
	}
	if (a[idx] == 1) {
		days = min(days, recurse(idx + 1, 0) + 1);
		if (act != 2 )days = min(days, recurse(idx + 1, 2));
	}
	if (a[idx] == 2) {
		days = min(days, recurse(idx + 1, 0) + 1);
		if (act != 1) days = min(days, recurse(idx + 1, 1));		
	}
	if (a[idx] == 3) {
		days = min(days, recurse(idx + 1, 0) + 1);
		if (act != 1) days = min(days, recurse(idx + 1, 1));		
		if (act != 2 )days = min(days, recurse(idx + 1, 2));		
	}
	
	return dp[act][idx] = days;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    dp.assign(3, vector<int> (n, -1));
    for (auto& i : a) cin >>i;
    cout << recurse(0,0) << ln;
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
