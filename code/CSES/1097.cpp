// Problem: Removal Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1097
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

int dp[5001][5001];
vector<int> a;

int recurse(int l, int r) {
	if (l > r) {
		return 0;
	}
	
	if (dp[l][r] != INF) return dp[l][r];
	
	int res = -INF;
	res = max(res, a[l] + min(recurse(l + 2, r), recurse(l + 1, r - 1)));
	res = max(res, a[r] + min(recurse(l, r - 2), recurse(l + 1, r - 1)));
	
	return dp[l][r] = res;
}

void solve() {
    int n;
    cin >> n;
    fill_n(&dp[0][0], 5001*5001, INF);
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    cout << recurse(0, n - 1) << ln;
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
