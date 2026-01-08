// Problem: D. Pair Of Lines
// Contest: Codeforces - Educational Codeforces Round 41 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/961/D
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

vector<int> getLine(pair<int, int> p1, pair<int, int> p2) {
	int x1 = p1.first;
	int y1 = p1.second;
	int x2 = p2.first;
	int y2 = p2.second;
	
	// AY + BX + C = 0
	int A = (x2 - x1);
	int B = -(y2 - y1);
	int C = -y1 * (x2 - x1) + x1 * (y2 - y1);
	
	return {A, B, C};
}

vector<int> matchLine(vector<int> line, vector<pair<int, int>> p) {
	int n = p.size();
	vector<int> match(n, 0);
	int A = line[0];
	int B = line[1];
	int C = line[2];
	
	for (int i = 0; i < n; i++) {
		int x = p[i].first;
		int y = p[i].second;
		
		int val = A * y + B * x + C;
		
		if (!val) match[i] = 1;
	}
	
	return match;
}

void solve() {
    // Usage: rng();
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i].first >> p[i].second;
    }
    
    bool poss = false;
    if (n <= 2) poss = true;
    
    for (int it = 0; it < 15; it++) {
	    // Select a pair of points
	    int i = rng() % n;
	    int j = rng() % n;
	    if (i == j) continue;
	    
	    // Make line
	    vector<int> line1 = getLine(p[i], p[j]);
	    
	    // Check which fall in it
	    vector<int> fall1 = matchLine(line1, p);
	    
	    // If <= 1 remains, good
	    vector<pair<int, int>> remaining;
	    for (int k = 0; k < n; k++) {
	    	if (!fall1[k]) remaining.pb(p[k]);
	    }
	    
	    if (remaining.empty() or (int)remaining.size() == 1) {
	    	poss = true;
	    	break;
	    }
	    
	    // Else, make a line among any two remaining
	    vector<int> line2 = getLine(remaining.front(), remaining.back());
	    
	    // If it covers everything, good
	    vector<int> fall2 = matchLine(line2, remaining);
	    
	    bool f = true;
	    for (auto& k : fall2) {
	    	if (!k) f = false;
	    }
	    if (f) {
	    	poss = true;
	    	break;
	    }
	}
	
	
	cout << (poss ? "YES":"NO") << ln;
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
