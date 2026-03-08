// Problem: A. Giga-Kilo-Gigabyte
// Contest: Codeforces - Semana i 2018
// URL: https://codeforces.com/gym/101917/problem/A
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int N = 500000;
int dp[N];

void solve() {
    int n;
	cin >> n;
	n /= 3;
	
	cout << dp[n] << ln;
}

signed main() {
    fast_cin();
    
    fill_n(&dp[0], N, 0);
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= 8; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= MOD;
			}
		}
	}
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
