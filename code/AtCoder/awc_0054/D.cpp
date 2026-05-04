// Problem: D - Card Taking Game
// Contest: AtCoder - AtCoder Weekday Contest 0054 Beta
// URL: https://atcoder.jp/contests/awc0054/tasks/awc0054_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int dp[3001][3001];
vector<int> a;

int recurse(int L, int R) {
	if (L > R) {
		return 0;
	}
	
	if (dp[L][R] != -INF) return dp[L][R];
	
	int res = -INF;
	res = max(res, a[L] - recurse(L + 1, R));
	res = max(res, a[R] - recurse(L, R - 1));
	
	return dp[L][R] = res;
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    int s = 0;
    for (auto& i : a) cin >> i;
    for (auto& i : a) s += i;
    fill_n(&dp[0][0], 3001 * 3001, -INF);
    
    int P1 = (s + recurse(0, n - 1)) >> 1;
    int P2 = s - P1;
    cout << P1 << " " << P2 << ln;
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
