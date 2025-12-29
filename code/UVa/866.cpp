// Problem: 866 - Intersecting Line Segments
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=807
// Memory Limit: 32 MB
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

bool intersect(vector<int>& line1, vector<int>& line2, vector<int>& l1, vector<int>& l2) {
	// cramer time!
	int a[2] = {line1[0], line2[0]};
	int b[2] = {line1[1], line2[1]};
	int c[2] = {line1[2], line2[2]};
	
	
	int den = a[0] * b[1] - a[1] * b[0];
	if (den == 0) {
		// they could be the same line!
		// vertical implies x is same on both, y ranges intercept
		if (l1[0] == l1[2] and l2[0] == l2[2] and l2[0] == l1[0]) {
			// check if y's touch
			vector<int> starts = {min(l1[0], l1[2]), min(l2[0], l2[2])};
			vector<int> ends = {max(l1[0], l1[2]), max(l2[0], l2[2])};
			
			if (starts[1] >= starts[0] and starts[1] <= ends[0]) {
				return true;
			}
			if (ends[1] >= starts[0] and ends[1] <= ends[0]) {
				return true;
			}
			if (starts[0] >= starts[1] and starts[0] <= ends[1]) {
				return true;
			}
			if (ends[0] >= starts[1] and ends[0] <= ends[1]) {
				return true;
			}
		}
		if (l1[1] == l1[3] and l2[1] == l2[3] and l2[1] == l1[1]) {
			// check if y's touch
			vector<int> starts = {min(l1[1], l1[3]), min(l2[1], l2[3])};
			vector<int> ends = {max(l1[1], l1[3]), max(l2[1], l2[3])};
			
			if (starts[1] >= starts[0] and starts[1] <= ends[0]) {
				return true;
			}
			if (ends[1] >= starts[0] and ends[1] <= ends[0]) {
				return true;
			}
			if (starts[0] >= starts[1] and starts[0] <= ends[1]) {
				return true;
			}
			if (ends[0] >= starts[1] and ends[0] <= ends[1]) {
				return true;
			}
		}
		
		return false;
	}
	
	ld x = c[0] * b[1] - b[0] * c[1];
	ld y = a[0] * c[1] - a[1] * c[0];
	
	x /= (ld)den;
	y /= (ld)den;
	
	
	if (x >= min(l1[0], l1[2]) and x <= max(l1[0], l1[2]) and x >= min(l2[0], l2[2]) and x <= max(l2[0], l2[2])
		and y >= min(l1[1], l1[3]) and y <= max(l1[1], l1[3]) and y >= min(l2[1], l2[3]) and y <= max(l2[1], l2[3])) {
			return true;
	}
	return false;
}


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> lines(n), coords(n);
	for (int i = 0; i < n; i++) {
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		
		int b = (x1 - x0);
		int a = -(y1 - y0);
		int c = y0 * (x1 - x0) - x0 * (y1 - y0);
		// dbg(x0, y0, x1, y1);
		lines[i] = {a, b, c};
		coords[i] = {x0, y0, x1, y1};
	}
	
	vector<int> inter(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			
			if (intersect(lines[i], lines[j], coords[i], coords[j])) {
				inter[i]++;
				inter[j]++;
				
			}
			
		}
	}
	
	int ans = 0;
	for (auto& i : inter) {
		ans += i + 1;
	}
	
	cout << ans;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
        solve(  );
        cin.ignore();
        if (i != T) cout << "\n\n";
    }
    cout << ln;

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
