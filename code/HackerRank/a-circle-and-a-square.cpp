// Problem: A Circle and a Square
// Contest: HackerRank - Mathematics - Geometry
// URL: https://www.hackerrank.com/challenges/a-circle-and-a-square/problem
// Memory Limit: 512 MB
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

bool inCircle(int x, int y, int xc, int yc, int r) {
	int L = (x - xc) * (x - xc) + (y - yc) * (y - yc);
	return (L <= r * r);
}

void print(vector<string>& a) {
	for (auto& i : a)  {
		cout << i << ln;
	}
	cout << ln;
}

void solve() {
    int m, n;
    cin >> m >> n;
    int yc, xc, r;
    cin >> yc >> xc >> r;
    int y1, x1, y3, x3;
    cin >> y1 >> x1 >> y3 >> x3;
    
    vector<string> a(n, string(m, '.'));
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (inCircle(i, j, xc, yc, r)) {
    			a[i][j] = '#';
    		}
    	}
    }
    
    ld Mx = (1.0*x1 + x3) / 2;
    ld My = (1.0*y1 + y3) / 2;
    
    ld ux = (x1 - Mx);
    ld uy = (y1 - My);
    
    ld vx = -uy;
    ld vy = ux;
    
    ld ax = ux + vx;
	ld ay = uy + vy;
	ld bx = ux - vx;
	ld by = uy - vy;
    
     for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		ld wax = ax * (Mx - i) + ay * (My - j);
    		ld wbx = bx * (Mx - i) + by * (My - j);
    		
    		ld uu = ux * ux + uy * uy;
    		
    		if (abs(wax) <= uu + eps and abs(wbx) <= uu) {
    			a[i][j] = '#';
    		}
    	}
    }
    
    print(a);
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
