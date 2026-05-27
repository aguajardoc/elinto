// Problem: D. Table Cut
// Contest: Codeforces - Codeforces Round 1078 (Div. 2)
// URL: https://codeforces.com/contest/2194/problem/D
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
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m, 0));
    vector<vector<int>> pref(n+1, vector<int> (m+1, 0));
    int z = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> mat[i][j];
    		z += (mat[i][j]);
    	}
    }
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		pref[i+1][j] = pref[i][j] + mat[i][j];
    		// dbg(pref[i][j]);
    		// dbg(pref[i][j]);
    	}
    }
    
    int x = z / 2;
    int y = z - x;
    
    cout << x * y << ln;
    int X = 0, Y = 0;
    int cur = 0;
    string ans;
    
    while (X != n or Y != m) {
    	if (X != n and Y != m) {
    		int extra = pref[n][Y] - pref[X][Y];
    		
    		if (cur + extra <= x) {
    			ans += 'R';
    			cur += extra;
    			Y++;
    		}
    		else {
    			ans += 'D';
    			X++;
    		}
    	}
    	else {
    		if (X != n) {
    			ans += 'D';
    			X++;
    		}
    		else {
    			ans += 'R';
    			Y++;
    		}
    	}
    }
    
    // dbg(x, cur);
    
    cout << ans << ln;
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
