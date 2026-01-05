// Problem: C. Captain Marmot
// Contest: Codeforces - Codeforces Round 271 (Div. 2)
// URL: https://codeforces.com/contest/474/problem/C
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

void rotate(vector<int>& p) {
	int c = 0;
	int s = 1;
	
	int x = p[0] - p[2];
	int y = p[1] - p[3];
	
	p[0] = x * c - y * s;
	p[1] = x * s + y * c;
	
	p[0] += p[2];
	p[1] += p[3]; 
	
}

void rotate(vector<int>& p, int x) {
	for (int i = 0; i < x; i++) rotate(p);
}

bool square(vector<vector<int>> p) {
	vector<pair<int, int>> points;
	for (int i = 0; i < 4; i++) {
		points.pb({p[i][0], p[i][1]});
	}
	
	// Get dists
	vector<int> dists;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			int dist = (p[j][0] - p[i][0]) * (p[j][0] - p[i][0]);
			dist += (p[j][1] - p[i][1]) * (p[j][1] - p[i][1]);
			dists.pb(dist);
		}
	}
	
	// 4 smaller dists must be equal
	sort(dists.begin(), dists.end());
	
	// Non-zero distances only
	if (dists.back() == 0) return false;
	
	for (int i = 1; i < 4; i++) {
		if (dists[i] != dists[i - 1]) return false;
	}
	
	// 2 largest must be equal
	if (dists[4] != dists[5]) return false;
	
	// square of smallest * 2 == square of largest
	return (2 * dists.front() == dists.back());
}

void solve() {
    // Try all rotation combinations
    // Check if they form a square
    // Pick min!
	vector<vector<int>> points(4, vector<int> (4, 0));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> points[i][j];
		}
	}
	
	int ans = 1e9;
	
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	for (int k = 0; k < 4; k++)
	for (int l = 0; l < 4; l++) {
		vector<vector<int>> p = points;
		
		rotate(p[0], i);
		rotate(p[1], j);
		rotate(p[2], k);
		rotate(p[3], l);
		
		
		if (square(p)) {
			ans = min(ans, i + j + k + l);
		}
	}
	
	cout << (ans == 1e9 ? -1:ans) << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out