// Problem: E. Perfect Polygon
// Contest: Codeforces - Semana i 2018
// URL: https://codeforces.com/gym/101917/problem/E
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
	ld x, y;
};

ld to_rad(int ang) {
	return (2.0 * PI * ang / 360.0);
}
void rotate(vector<Point>& a, ld ang, int mx, int my) {
	ld c = cos(ang);
	ld s = sin(ang);
	
	// Offset 
	for (auto& i : a) {
		i.x -= mx;
		i.y -= my;
	}
	
	// Transform
	for (auto& i : a) {
		ld x = i.x;
		ld y = i.y;
		
		i.x = x * c - y * s;
		i.y = x * s + y * c;
	}
	
	// Unoffset
	for (auto& i : a) {
		i.x += mx;
		i.y += my;
	}
}

void solve() {
    int A, W, H, N;
    cin >> A >> W >> H >> N;
  	vector<Point> a(N);  
    // Get center of polygon
    ld mx = 0, my = 0;
    for (int i = 0; i < N; i++) {
    	int x, y;
    	cin >> x >> y;
    	a[i].x = x;
    	a[i].y = y;
    	
    	mx += x;
    	my += y;
    }
    
    mx /= N;
    my /= N;
    // Rotate points in polygon
    rotate(a, to_rad(A), mx, my);
    
    // for (auto& i : a) {
    	// dbg(i.x, i.y);
    // }
    
    // Define transformations
    ld minX = 1e10;
    ld maxX = -1e10;
    ld minY = 1e10;
    ld maxY = -1e10;
    for (auto& [x, y] : a) {
    	minX = min(minX, x);
    	maxX = max(maxX, x);
    	minY = min(minY, y);
    	maxY = max(maxY, y);
    }
    
    ld ax = minX, bx = 1.0 * W / (maxX - minX);
    ld ay = minY, by = 1.0 * H / (maxY - minY);
    
    // dbg(ax, bx, ay, by);
    
    // Perform transformations
    for (auto& [x, y] : a) {
    	x = bx * (x - ax);
    	y = by * (y - ay);
    }
    
    for (auto& [x, y] : a) {
    	cout << fixed << setprecision(10) << x << " " << y << ln;
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
