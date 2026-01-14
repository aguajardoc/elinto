// Problem: D. Caesar's Legions
// Contest: Codeforces - Codeforces Beta Round 89 (Div. 2)
// URL: https://codeforces.com/contest/118/problem/D
// Memory Limit: 256 MB
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
const int MOD = 100000000;
const double eps = 1e-9;

int dp[101][101][2][11];
int n1, n2, k1, k2;

int recurse(int men, int horse, bool type, int consec) {
	if (type == 0 and consec > k1) return 0;
	if (type == 1 and consec > k2) return 0;
	if (men > n1) return 0;
	if (horse > n2) return 0;
	if (horse + men == n1 + n2) {
		return 1;
	}
	
	if (dp[men][horse][type][consec] != -1) return dp[men][horse][type][consec];
	
	int res = 0;
	if (type == 0) {
		res += recurse(men + 1, horse, 0, consec + 1);
		res %= MOD;
		res += recurse(men, horse + 1, 1, 1);
		res %= MOD;
	}
	else {
		res += recurse(men + 1, horse, 0, 1);
		res %= MOD;
		res += recurse(men, horse + 1, 1, consec + 1);
		res %= MOD;
	}
	
	return dp[men][horse][type][consec] = res;
}

void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    cout << recurse(0,0,0,0) << ln;
}

signed main() {
    fast_cin();
    fill_n(&dp[0][0][0][0], 101*101*2*11, -1);
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
