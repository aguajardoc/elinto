// Problem: D. Dividing Island
// Contest: Codeforces - Codeforces Beta Round 59 (Div. 2)
// URL: https://codeforces.com/contest/63/problem/D
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
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    vector<string> mat(max(b, d), string(a + c, '.'));
    vector<int> col(n);
    for (auto& i : col) cin >> i;
    
    int x = 0, y = 0;
    int dir = 1;
    if (b < d) {
    	if (b % 2) y = 0;
    	else {
    		y = (a + c) - 1;
    		dir = -1;
    	}
    }
    else {
    	if (d % 2) {
    		y = (a + c) - 1;
    		dir = -1;
    	}
    	else y = 0;
    }
    
    int idx = 0;
    while (x < max(b, d)) {
    	// Use spot
    	mat[x][y] = (idx + 'a');
    	
    	// Check if color is exhausted
    	if (idx < n and !--col[idx]) idx++;
    	
    	// Move
    	// If we are at an edge, we need to move down and change dir
    	if (x < min(b, d)) {
    		if ((y == 0 and dir == -1) or (y == (a + c - 1) and dir == 1)) {
    			x++;
    			dir *= -1;	
    		}
    		else y += dir;
    	}
    	else {
    		// Confined
    		if (b > d) {
    			// Range from 0 to a - 1
    			if ((y == 0 and dir == -1) or (y == a - 1 and dir == 1)) {
    				x++;
    				dir *= -1;
    			}
    			else y += dir;
    		}
    		else {
    			// Range from a to a + c - 1
    			if ((y == a and dir == -1) or (y == (a + c - 1) and dir == 1)) {
    				x++;
    				dir *= -1;
    			}
    			else y += dir;
    		}
    	}
    }
    
    cout << "YES" << ln;
    for (auto& i : mat) {
    	cout << i << ln;
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
