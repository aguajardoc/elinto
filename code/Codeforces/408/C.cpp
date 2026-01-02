// Problem: C. Triangle
// Contest: Codeforces - Codeforces Round 239 (Div. 2)
// URL: https://codeforces.com/contest/408/problem/C
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

void solve() {
    int a, b;
    cin >> a >> b;
    
    int x1 = 0, y1 = 0;
    int x2 = a, y2 = 0;
    int x3 = 0, y3 = b;
    int c = a * a + b * b;
    
    for (int i = -min(a, b); i <= max(a, b); i++) {
    	y2 = i;
    	x2 = sqrt(a * a - i * i);
    	if (x2 * x2 != a * a - i * i) continue;
    	
    	ld ang = asin((ld)i / (ld)a);
    	
    	x3 = 0 * cos(ang) - b * sin(ang);
    	y3 = 0 * sin(ang) + b * cos(ang);
    	
		if (x1 == x2 or x1 == x3 or x2 == x3 or y1 == y2 or y1 == y3 or y2 == y3) {
			continue;
		}
    	
    	int fakec = ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    	if (c == fakec) {
    		cout << "YES" << ln;
    		cout << x1 << " " << y1 << ln;
    		cout << x2 << " " << y2 << ln;
    		cout << x3 << " " << y3 << ln;
    		return;
    	}
    }
    cout << "NO" << ln;
    
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
