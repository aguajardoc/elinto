// Problem: 10192 - Vacation
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1133
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
string s, t;
vector<vector<int>> dp;

int recurse(int idxs, int idxt) {
	if (idxs == s.length() or idxt == t.length()) {
		return 0;
	}
	
	if (dp[idxs][idxt] != -1) return dp[idxs][idxt];
	
	int res = 0;
	// see if pickable
	int nt = idxt;
	while (nt < t.length() and t[nt] != s[idxs]) nt++;
	
	if (nt < t.length()) {
		res = max(res, recurse(idxs + 1, nt + 1) + 1);
	}
	res = max(res, recurse(idxs + 1, idxt));
	
	return dp[idxs][idxt] = res;
}

double eps = 1e-9;

void solve() {
	int d = 1;
    while (getline(cin, s)) {
    	if (s == "#") break;
    	
    	getline(cin, t);
    	dp.assign(s.length() + 1, vector<int>(t.length() + 1, -1));
    	int ans = recurse(0, 0);
    	
    	cout << "Case #" << d++ << ": you can visit at most " << ans << " cities.\n";
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
        // if (i != T) cout <<"\n";
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
