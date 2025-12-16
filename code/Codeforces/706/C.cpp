// Problem: C. Hard problem
// Contest: Codeforces - Codeforces Round 367 (Div. 2)
// URL: https://codeforces.com/contest/706/problem/C
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
int n;
vector<map<string, int>> dp;
vector<string> a;
vector<int> e;

int recurse(int idx, string prev) {
	if (idx == n) {
		return 0;
	}
	if (dp[idx].count(prev)) return dp[idx][prev];
	
	int res = 1e15;
	// reverse if useful
	string normal = a[idx];
	string rev = normal; reverse(rev.begin(), rev.end());
	if (rev >= prev) {
		res = min(res, recurse(idx + 1, rev) + e[idx]);
	}
	// dont 
	if (normal >= prev) {
		res = min(res, recurse(idx + 1, normal));
	}
	
	return dp[idx][prev] = res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	e.push_back(x);
    }
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	a.push_back(s);
    }
    string init(1, 'a' - 1);
    dp.assign(n, map<string, int> ());
    int ans = recurse(0, init);
    if (ans >= 1e15) {
    	cout << -1 << ln;
    }
    else cout << ans << ln;
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
