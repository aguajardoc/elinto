// Problem: B. Guess That Car!
// Contest: Codeforces - Codeforces Round 127 (Div. 1)
// URL: https://codeforces.com/contest/201/problem/B
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
int n, m;
int c[1001][1001];

int get(int x, int y) {
	int res = 0;
	int dx = 4 * (x) + 2;
	for (int i = 1; i <= n; i++) {
		auto& row = c[i-1];
		dx -= 4;
		int dy = 4 * (y) + 2;
		for (int j = 1; j <= m; j++) {
			
			dy -= 4;
			int d = dx * dx + dy * dy;
			res += d * row[j-1];
			// dbg(i, j);
			// dbg(x, y);
			// dbg(dx, dy);
			// dbg(d, res);
		}
	}
	
	return res;
}

void solve() {
    cin >> n >> m;
    for (int i  = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> c[i][j];
    	}
    }
    
    // in every row, the ans is ternary
    // O(n*m(n log_3 m)) mmm no
    // the rows themselves are ternary?
    // O(n*m(log_3 n * log_3 m))
    // bullshit only one matters for the first TS
    // O(n*m log_3 n)
    // mmm apparently no it doesnt
    int ans = INF;
    pair<int, int> coords = {-1, -1};
    
    int l = 0, r = n;
    while (l <= r) {
    	int delta = (r - l) / 3;
    	int m1 = l + delta;
    	int m2 = r - delta;
    	
    	int x = get(m1, 0);
    	int y = get(m2, 0);
    	
    	if (x < ans) {
    		coords = {m1, INF};
    		ans = x;
    	}
    	else if (x == ans) {
			coords = min(coords, {m1, INF});
		}
    	
    	if (y < ans) {
    		coords = {m2, INF};
    		ans = y;
    	}
		else if (y == ans) {
			coords = min(coords, {m2, INF});
		}
    	// dbg(x, y);
    	
    	if (x <= y) {
    		r = m2 - 1;
    	}
    	else {
    		l = m1 + 1;
    	}
    }
    
    l = 0, r = m;
    while (l <= r) {
    	int delta = (r - l) / 3;
    	int m1 = l + delta;
    	int m2 = r - delta;
    	
    	int x = get(coords.first, m1);
    	int y = get(coords.first, m2);
    	
    	if (x < ans) {
    		coords.second = m1;
    		ans = x;
    	}
    	else if (x == ans) {
			coords = min(coords, {coords.first, m1});
		}
    	
    	if (y < ans) {
    		coords.second = m2;
    		ans = y;
    	}
		else if (y == ans) {
			coords = min(coords, {coords.first, m2});
		}
    	// dbg(x, y);
    	
    	if (x <= y) {
    		r = m2 - 1;
    	}
    	else {
    		l = m1 + 1;
    	}
    }
    
	// for (int i = 0; i <= n; i++) {
		// for (int j = 0; j <= m; j++) {
			// dbg(i, j);
			// int res = get(i, j);
			// dbg(res);
		// }
	// }
    
    cout << ans << ln;
    cout << coords.first << " " << coords.second << ln;
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