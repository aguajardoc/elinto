// Problem: C. Barcode
// Contest: Codeforces - Codeforces Round 139 (Div. 2)
// URL: https://codeforces.com/contest/225/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
vector<int> cols;
int n, m, x, y;
vector<vector<vector<int>>> dp;

int recurse(ll idx, ll cons, int color) {
	if (idx == m) {
		if (cons < x) return 1e9;
		return 0;
	}
	if (dp[idx][cons][color] != -1) return dp[idx][cons][color];
	
	int res = 1e9;
	#define go_on recurse(idx + 1, cons + 1, color)
	#define change recurse(idx + 1, 1, 1 - color)
	int to_black = cols[idx];
	int to_white = n - to_black;
	int colors[] = {to_black, to_white};
	if (color) swap(colors[0], colors[1]);
	
	if (cons == 0 or (cons >= x and cons < y)) {
		// choose any color
		res = min(res, go_on + colors[0]);
		res = min(res, change + colors[1]);
	}
	if (cons and cons < x) {
		// go on
		res = min(res, go_on + colors[0]);
	}
	if (cons == y) {
		// leave
		res = min(res, change + colors[1]);
	}
	
	return dp[idx][cons][color] = res;
}

void print(vector<vector<vector<int>>>& dp) {
	for (auto& i : dp) {
		for (auto& j : i) {
			for (auto& k : j) {
				cerr << k << " ";
			}
			cerr << ln;
		}
		cerr << ln << ln;
	}
	cerr << ln;
}

void solve() {
	cin >> n;
	cin >> m;
	cin >> x >> y;
	cols.assign(m, 0);
	dp.assign(m, vector<vector<int>>(m, vector<int> (2, -1)));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m ; j++) {
    		if (s[j] == '#') cols[j]++;
    	}
    }
    
	cout << recurse(0, 0, 0) << ln;
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
