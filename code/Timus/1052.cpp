// Problem: 1052. Rabbit Hunt
// Contest: Timus Online Judge - Ural State University collegiate programming contest (25.03.2000)
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1052
// Memory Limit: 64 MB
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

vector<int> getLine(Point a, Point b) {
	ll A = b.y - a.y;
	ll B = b.x - a.x;
	ll C = A * (a.x) - B * (a.y);
	
	return {A, B, C};
}

void solve() {
	// for every pair of rabbits, get line, count how many match it
	int n;
	cin >> n;
	vector<Point> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// line
			vector<int> line = getLine(a[i], a[j]);
			
			int res = 0;
			for (int k = 0; k < n; k++) {
				// match a[k] with line
				if (line[0] * a[k].x - line[1] * a[k].y == line[2]) {
					res++;
				}
			}
			
			ans = max(ans, res);
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
