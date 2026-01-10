// Problem: B. Han Solo and Lazer Gun
// Contest: Codeforces - Codeforces Round 291 (Div. 2)
// URL: https://codeforces.com/contest/514/problem/B
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

set<vector<int>> lines;

void getLine(int x, int y, int x0, int y0) {
	vector<int> line;
	
	int A = x - x0;
	int B = -(y - y0);
	int C = x * (y - y0) - y * (x - x0);
	if (A != 0) {
		if (A < 0) {
			A *= -1;
			B *= -1;
			C *= -1;
		}
	}
	else if (B != 0) {
		if (B < 0) {
			A *= -1;
			B *= -1;
			C *= -1;
		}
	}
	else if (C != 0) {
		if (C < 0) {
			A *= -1;
			B *= -1;
			C *= -1;
		}
	}
	int hcf = gcd(abs(A), abs(B));
	hcf = gcd(hcf, abs(C));
	A /= hcf;
	B /= hcf;
	C /= hcf;
	// dbg(A, B, C)
	line = {A, B, C};
	lines.insert(line);
}

void solve() {
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	getLine(x, y, x0, y0);
    }
    
    cout << lines.size() << ln;
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
