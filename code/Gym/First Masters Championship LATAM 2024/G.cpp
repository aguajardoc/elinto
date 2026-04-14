// Problem: G. Gridtopia
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/G
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

int n, m;

bool check(vector<vector<int>>& a) {
	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j]) return 0;
    	}
    }
    return 1;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    
    int ans = 0;
    while (!check(a)) {
    	ans++;
    	int x = 0, y = 0;
    	while (x <= n - 1 and y <= m - 1) {
    		a[x][y] &= 0;
    		
    		// check down
    		bool down = false;
    		for (int i = x + 1; i < n; i++) {
    			if (a[i][y]) down = true;
    		}
    		
    		if (down)x++;
    		else y++;
    	}
    }
    
    cout << ans << ln;
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
