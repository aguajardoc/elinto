// Problem: G. Grandmapocalipse
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/105979/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	bool operator <(const auto& other) {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
	
	bool operator ==(const auto& other) {
		return (x == other.x and y == other.y);
	}
};

struct PointZ {
	int x, y, z;
};

int parse_int() {
	string s;
	cin >> s;
	string integer;
	for (auto& i : s) {
		if (i != '.') integer += i;
	}
	return (stoll(integer));
}

int n, h;
vector<PointZ> islands;
Point golden_cookie;

int area(Point A, Point B, Point C) {
	__int128 a = ((__int128)A.x * ((__int128)B.y - (__int128)C.y) + 
			(__int128)B.x * ((__int128)C.y - (__int128)A.y) + 
			(__int128)C.x * ((__int128)A.y - (__int128)B.y)
	); // technically over 2 but meh
	
	return (a == 0 ? 0:(a > 0 ? 1:-1));
}

vector<Point> convex_hull(vector<Point>& filtered_islands) {
	int N = filtered_islands.size();
	if (N <= 2) return filtered_islands;
	
	vector<Point> hull;
	
	// Build upper hull
	for (int i = 0; i < N; i++) {
		int M = hull.size();
		while (M > 1 and area(hull[M-2], hull[M-1], filtered_islands[i]) >= 0) {
			hull.pop_back();
			M = hull.size();
		}
		hull.pb(filtered_islands[i]);
	}
	
	reverse(filtered_islands.begin(), filtered_islands.end());
	int h = hull.size();
	// Build lower hull
	for (int i = 0; i < N; i++) {
		int M = hull.size();
		while (M > h and area(hull[M-2], hull[M-1], filtered_islands[i]) >= 0) {
			hull.pop_back();
			M = hull.size();
		}
		hull.pb(filtered_islands[i]);
	}
	
	hull.pop_back();
	
	return hull;
}

bool square_validity(vector<Point> hull, vector<Point> filtered_islands) {
	int A1 = area(hull[0], hull[2], golden_cookie);
	int A2 = area(hull[1], hull[3], golden_cookie);
	
	if (A1 or A2) return true;
	
	for (auto& i : filtered_islands) {
		A1 = area(hull[0], hull[2], i);
		A2 = area(hull[1], hull[3], i);
		
		if (A1 and A2) return true;
	}
	
	return false;
}

bool cookie_in_hull(vector<Point> hull) {
	int h = hull.size();
	
	int sign = 0;

	for (int i = 0; i < h; i++) {
		Point L = hull[i];
		Point R = hull[(i+1)%h];
		
		int v = area(L, R, golden_cookie);
		if (!v) return false; // collinear
		
		int ns = (v > 0) ? 1 : -1;
		
		if (i == 0) sign = ns;
		else {
			if (sign != ns) return false;
		}
	}
	return true;
}

bool f(int x) {
	// Filter points based on time
	vector<Point> filtered_islands;
	for (int i = 0; i < n; i++) {
		if (islands[i].z <= x) {
			filtered_islands.push_back({islands[i].x, islands[i].y});
		}
	}
	
	// Filter points based on coordinate
	sort(filtered_islands.begin(), filtered_islands.end());
	filtered_islands.resize(unique(filtered_islands.begin(), filtered_islands.end()) - filtered_islands.begin());
	
	// Get hull
	vector<Point> hull = convex_hull(filtered_islands);
	
	// Initial size check
	int h = hull.size();
	if (h <= 2) return false;
	
	bool possible = cookie_in_hull(hull);
	
	if (!possible) return false;
	
	// Check validity when h == 4
	if (h == 4) return square_validity(hull, filtered_islands);
	
	return true;
}

void solve() {
    cin >> n;
    h = parse_int();
    
    islands.resize(n);
    for (int i = 0; i < n; i++) {
    	islands[i] = {parse_int(), parse_int(), parse_int()};
    	islands[i].z = max(0ll, -(islands[i].z - h));
    }
    golden_cookie.x = parse_int();
    golden_cookie.y = parse_int();
    
    // Binary search over time
    int l = 0, r = 1e12;
    int ans = INF;
    while (r >= l) {
    	int m = (l + r) / 2;
    	
    	bool fm = f(m);
    	
    	if (fm) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else {
    		l = m + 1;
    	}
    }
    
    if (ans == INF) {
    	cout << -1 << ln;
    }
    else {
    	ld res = ans;
    	res /= 100;
    	cout << fixed << setprecision(10) << res << ln;
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
