// Problem: 1087. The Time to Take Stones
// Contest: Timus Online Judge - The 3rd high school children programming contest, USU, Yekaterinburg, Russia, March 4, 2001
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1087
// Memory Limit: 64 MB
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

vector<int> k;
int dp[10001];

int recurse(int n) {
	if (n == 0) {
		return 1; // we won
	}
	
	if (dp[n] != -1) return dp[n];
	
	for (auto& i : k) {
		if (n - i < 0) continue;
		if (!recurse(n - i)) {
			// if we can reach a losing state
			// we are winning
			return dp[n] = 1;
		}
	}
	
	// no losing state, we are losing
	return dp[n] = 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    k.assign(m, 0);
    fill_n(&dp[0], 10001, -1);
    for (auto& i : k) cin >> i;
    
    cout << (recurse(n) ? 1:2) << ln;
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
