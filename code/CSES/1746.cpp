// Problem: Array Description
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1746
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
int n, m;
vector<int> a;
int dp[100001][110];

int recurse(int idx, int prev=105) {
	if (prev == m + 1 or prev == 0) return 0;
	if (idx == n) return 1;
	
	if (dp[idx][prev] != -1) return dp[idx][prev];
	
	int res = 0;
	if (a[idx]) {
		if (prev == 105) {
			res = recurse(idx + 1, a[idx]);
		}
		else if (abs(a[idx] - prev) <= 1) {
			res = recurse(idx + 1, a[idx]);
		}
	}
	else {
		if (prev == 105) {
			for (int i = 1; i <= m; i++) {
				res += recurse(idx + 1, i);
				res %= MOD;
			}
		}
		else {
			res += recurse(idx + 1, prev - 1);
			res %= MOD;
			res += recurse(idx + 1, prev);
			res %= MOD;
			res += recurse(idx + 1, prev + 1);
			res %= MOD;
		}
	}
	
	return dp[idx][prev] = res;
}

void solve() {
    cin >> n >> m;
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    
    fill_n(&dp[0][0], 100001 * 110, -1);
    
    cout << recurse(0, 105) << ln;
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
