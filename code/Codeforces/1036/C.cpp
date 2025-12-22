// Problem: C. Classy Numbers
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1036/problem/C
// Memory Limit: 256 MB
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

double eps = 1e-9;

void brute(int x) {
	int a = 0;
	for (int i = 1; i <= x; i++) {
		string s = to_string(i);
		int ct = 0;
		for (auto& j : s) if (j != '0') ct++;
		if (ct <= 3) a++;
	}
	cout << a << ln;
}

int recurse(int idx, int ct, int free, string& num, int& n, vector<vector<vector<int>>>& dp) {
	if (idx == n) {
		return 1;
	}
	if (dp[idx][ct][free] != -1) return dp[idx][ct][free];
	
	ll res = 0;
	if (ct < 3) {
		if (free) {
			res += recurse(idx + 1, ct + 1, 1, num, n,dp) * 9;
			res += recurse(idx + 1, ct, 1, num,n,dp);
		}
		else {
			int digit = num[idx] - '0';
			if (digit) {
				res += recurse(idx + 1, ct + 1, 0, num, n, dp);
				for (int i = 1; i < digit; i++)
					res += recurse(idx + 1, ct + 1, 1, num, n, dp);
				res += recurse(idx + 1, ct, 1, num, n, dp);				
			}	
			else {
				res += recurse(idx + 1, ct, 0, num, n, dp);
			}
		}
	}
	else {
		res += recurse(idx + 1, ct, free, num, n, dp);
	}
	
	return dp[idx][ct][free] = res;
	
}

void solve() {
	ll l, r;
	cin >> l >> r;
	vector<vector<vector<int>>> dp;
	
	l--;
	string ls = to_string(l);
	int nl = ls.length();
	dp.assign(nl, vector<vector<int>> (4, vector<int> (2, -1)));
	ll ansL = recurse(0, 0, 0, ls, nl, dp);
	
	string rs = to_string(r);
	int nr = rs.length();
	dp.assign(nr, vector<vector<int>> (4, vector<int> (2, -1)));
	ll ansR = recurse(0, 0, 0, rs, nr, dp);
	
	ll ans = ansR - ansL;
	cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
