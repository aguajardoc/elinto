// Problem: B. Counting Rectangles is Fun
// Contest: Codeforces - Codeforces Round 219 (Div. 1)
// URL: https://codeforces.com/contest/372/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

bool mat[41][41];
int pref[41][41];
int rect[41][41][41][41];
int prefr[41][41][41][41];

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	// Input mat
	for(auto&i:mat)for(auto&j:i)j=0;
	for(auto&i:pref)for(auto&j:i)j=0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j-1] == '1') mat[i][j] = 1;
		}
	}
	
	for(auto&i:prefr)for(auto&j:i)for(auto&k:j)for(auto&l:k)l=0;
	for(auto&i:rect)for(auto&j:i)for(auto&k:j)for(auto&l:k)l=0;
	
	// Get num of 1s
	for (int i = 1; i <= 40; i++) {
		for (int j = 1; j <= 40; j++) {
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
		}
	}
	
	// Precalc rectangle ct
	for (int i = 1; i <= 40; i++)
	for (int k = i; k <= 40; k++)
	for (int j = 1; j <= 40; j++)
	for (int l = j; l <= 40; l++) {
		// top, left, bottom, right
		int ones = pref[k][l] - pref[k][j - 1] - pref[i - 1][l] + pref[i - 1][j - 1];
		if (!ones) rect[i][j][k][l] = 1;
	}
	
	// Prefix sum
	for (int i = 1; i <= 40; i++)
	for (int j = 1; j <= 40; j++)
	for (int k = 1; k <= 40; k++)
	for (int l = 1; l <= 40; l++) {
		prefr[i][j][k][l] = 
		prefr[i-1][j][k][l] + 
		prefr[i][j-1][k][l] + 
		prefr[i][j][k-1][l] + 
		prefr[i][j][k][l-1] - 
		prefr[i-1][j-1][k][l] - 
		prefr[i-1][j][k-1][l] - 
		prefr[i-1][j][k][l-1] - 
		prefr[i][j-1][k-1][l] - 
		prefr[i][j-1][k][l-1] -
		prefr[i][j][k-1][l-1] + 
		prefr[i-1][j-1][k-1][l] + 
		prefr[i-1][j-1][k][l-1] +
		prefr[i-1][j][k-1][l-1] +
		prefr[i][j-1][k-1][l-1] -
		prefr[i-1][j-1][k-1][l-1] +
		rect[i][j][k][l];
	}
	
	// Process queries
	while (q--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int ans = 
		prefr[x2][y2][x2][y2] -
		prefr[x1-1][y2][x2][y2] -
		prefr[x2][y1-1][x2][y2] -
		prefr[x2][y2][x1-1][y2] -
		prefr[x2][y2][x2][y1-1] +
		prefr[x1-1][y1-1][x2][y2] +
		prefr[x1-1][y2][x1-1][y2] +
		prefr[x1-1][y2][x2][y1-1] +
		prefr[x2][y1-1][x1-1][y2] +
		prefr[x2][y1-1][x2][y1-1] +
		prefr[x2][y2][x1-1][y1-1] -
		prefr[x1-1][y1-1][x1-1][y2] -
		prefr[x1-1][y1-1][x2][y1-1] -
		prefr[x1-1][y2][x1-1][y1-1] -
		prefr[x2][y1-1][x1-1][y1-1] +
		prefr[x1-1][y1-1][x1-1][y1-1];
		
		cout << ans << ln;
	}
    
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
