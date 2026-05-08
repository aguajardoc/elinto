// Problem: J. Marbles
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/J
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> grundy(101, vector<int>(101, 0));
    
    for (int i = 0; i <= 100; i++) {
    	for (int j = 0; j <= 100; j++) {
    		if (i == j) continue;
    		set<int> mex;
    		for (int k = 1; k < j; k++) if (k != i) mex.insert(grundy[i][k]);
    		for (int k = 1; k < i; k++) if (k != j) mex.insert(grundy[k][j]);
    		for (int x = i - 1, y = j - 1; x > 0 and y > 0; x--, y--) mex.insert(grundy[x][y]);
    		
    		int rm = 0;
    		for (auto& i : mex) {
    			if (i != rm) break;
    			rm++; 
    		}
			
    		grundy[i][j] = rm;
    	}
    }´
    
    int ans = 0;
    int win = false;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	
    	if (x == y) win = true;
    	ans ^= grundy[x][y];
    }
    
    cout << ((win or ans) ? 'Y':'N') << ln;
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
