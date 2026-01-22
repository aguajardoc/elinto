// Problem: D. Polyline
// Contest: Codeforces - Codeforces Round 340 (Div. 2)
// URL: https://codeforces.com/contest/617/problem/D
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

struct Point {
	int x, y;
};

void solve() {
    // If all on same x or same y, ans is 1
    // If one has same x as two, and same y as 3, ans is 2
    vector<Point> a(3);
    for (int i = 0; i < 3; i++) {
    	cin >> a[i].x >> a[i].y;
    }
    
    int ans = 3;
    if (a[0].x == a[1].x and a[0].x == a[2].x) ans = 1;
    else if (a[0].y == a[1].y and a[0].y == a[2].y) ans = 1;
    else {
    	for (int i = 0; i < 3; i++) {
    		Point L = a[(i+1)%3];
    		Point R = a[(i + 2)%3];
    		
    		// Two points on same line, and third at a diff coord
    		if (a[i].y == L.y) {
    			if (R.x <= a[i].x and R.x <= L.x) ans = 2;
    			if (R.x >= a[i].x and R.x >= L.x) ans = 2;
    		}
    		if (a[i].y == R.y) {
    			if (L.x <= a[i].x and L.x <= R.x) ans = 2;
    			if (L.x >= a[i].x and L.x >= R.x) ans = 2;
    		}
    		if (a[i].x == L.x) {
    			if (R.y <= a[i].y and R.y <= L.y) ans = 2;
    			if (R.y >= a[i].y and R.y >= L.y) ans = 2;
    		}
    		if (a[i].x == R.x) {
    			if (L.y <= a[i].y and L.y <= R.y) ans = 2;
    			if (L.y >= a[i].y and L.y >= R.y) ans = 2;
    		}
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
