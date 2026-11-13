// Problem: Convex Hull
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2195
// Memory Limit: 512 MB
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
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}
	
	Point operator-(const auto& oth) const {
		return Point(x-oth.x, y-oth.y);
	}
	
	bool operator<(const auto& oth) const {
		return make_pair(x, y) < make_pair(oth.x, oth.y);
	}
	
	bool operator==(const auto& oth) const {
		return make_pair(x, y) == make_pair(oth.x, oth.y);
	}
};

int cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

void build_hull(vector<Point>& H, vector<Point>& a, int n) {
	for (int i = 0; i < n; i++) {
		while (H.size() >= 2 and cross(H[H.size()-1] - H[H.size()-2], a[i] - H[H.size()-1]) < 0) {
			H.pop_back();
		}
		H.push_back(a[i]);
	}
}

vector<Point> get_hull(vector<Point> a, int n) {
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	if (n <= 2) return a;
	vector<Point> U, L;
	
	build_hull(U,a,n);
	if (U.size() == n) return U;
	reverse(a.begin(), a.end());
	build_hull(L,a,n);
	
	U.pop_back(); L.pop_back();
	vector<Point> hull;
	for (auto& i : L) hull.pb(i);
	for (auto& i : U) hull.pb(i);
	
	return hull;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> a(n); for (auto& i : a) cin >> i.x >> i.y;
    
    vector<Point> hull = get_hull(a, n);
    cout << hull.size() << ln;
    for (auto& i : hull) cout << i.x << " " << i.y << ln;
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
