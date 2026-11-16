// Problem: B. Polygons
// Contest: Codeforces - Codeforces Round 113 (Div. 2)
// URL: https://codeforces.com/contest/166/problem/B
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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }

template <class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }

    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }

    // angle to x=axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }

    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

int cross(Point<int> u, Point<int> v) {
	return u.x*v.y - u.y*v.x;
}

void build_hull(vector<Point<int>>& h, vector<Point<int>> a) {
	for (int i = 0; i < a.size(); i++) {
		while (h.size() >= 2 and h[h.size()-2].cross(h.back(), a[i]) <= 0) {
			h.pop_back();
		}
		
		h.pb(a[i]);
	}
}

bool in_polygon(Point<int> A, vector<Point<int>>& h) {
	int n = h.size();
	if (h[0].cross(h[1], A) <= 0 or 
		h[0].cross(h[n-1], A) >= 0
	) return false;
	
	int i = 0;
	int l = 1, r = n - 2;
	while (l <= r) {
		int m = (l + r) / 2;
		
		bool fm = h[0].cross(h[m], A) > 0;
		if (fm) {
			i = max(i, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	
	int verdict = h[i].cross(h[(i+1)%n], A);
	return (verdict > 0);
}

vector<Point<int>> convex_hull(vector<Point<int>> a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int n = a.size();
	if (n < 3) return a;
	
	vector<Point<int>> upper, lower;
	build_hull(lower, a);
	if (lower.size() == n) return lower;
	reverse(a.begin(), a.end());
	build_hull(upper, a);
	
	vector<Point<int>> h;
	upper.pop_back(), lower.pop_back();
	for (auto& i : lower) h.pb(i);
	for (auto& i : upper) h.pb(i);
	
	
	return h;
}

void solve() {
    int n; cin >> n;
    vector<Point<int>> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].x >> a[i].y;
    }
    
    vector<Point<int>> h = convex_hull(a);
    
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
    	Point A(0ll,0ll); cin >> A.x >> A.y;
    	
    	if (!in_polygon(A, h)) {
    		cout << "NO" << ln;
    		return;
    	}
    }
    
    cout << "YES" << ln;
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
