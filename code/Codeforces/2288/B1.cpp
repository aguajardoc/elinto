// Problem: B1. Yukari Yakumo and the Boundary Stones (Easy Version)
// Contest: Codeforces - Codeforces Round 1136 (Div. 2)
// URL: https://codeforces.com/contest/2288/problem/B1
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int m;
string s; 
vector<vector<vector<int>>> dp;

int recurse(int x, int y, int idx) {
	if (idx == m) {
		return x+y;
	}
	
	if (dp[x][y][idx] != -1) return dp[x][y][idx];
	
	int res = x + y;
	if (s[idx] == '-') {
		// Do it on a 1
		if (x) {
			res = max(res, recurse(x-1, y, idx + 1));
		}
		// Do it on a 2
		if (y) {
			res = max(res, recurse(x+1, y-1, idx + 1));
		}
	}
	else {
		// Do it on a 1
		if (x) {
			res = max(res, recurse(x-1, y+1, idx + 1));
		}
		// Do it on a 2
		if (y) {
			res = max(res, recurse(x, y+1, idx + 1));
		}
	}
	
	return dp[x][y][idx] = res;
}

void solve() {
    int x, y; cin >> x >> y >> m;
    cin >> s;
    int ans = x + y;
    dp.assign(x+m+1, vector<vector<int>> (y+m+1, vector<int>(m+1, -1)));
    cout << recurse(x, y, 0) << ln;
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
