// Problem: D. Dragon King's Palace
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/D
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

struct Circle {
	int x, y, r;
};

void solve() {
	Circle A, B;
	cin >> A.x >> A.y >> A.r;
	cin >> B.x >> B.y >> B.r;
	
	int k;
	cin >> k;
	
	if (k > 2 * (A.r + B.r)) {
		cout << "NO" << ln;
		return;
	}
	
	if (k <= 2 * max(A.r, B.r)) {
		cout << "YES" << ln;
		return;
	}
	
	int dsq = (A.x - B.x) * (A.x - B.x) + 
				(A.y - B.y) * (A.y - B.y);
	int rsq = (A.r + B.r) * (A.r + B.r);
	
	if (dsq > rsq) {
		cout << "NO" << ln;
		return;
	}
	
	
	int rhs = k * k - 2 * k * A.r - 2 * k * B.r + 2 * A.r * B.r + A.r * A.r + B.r * B.r;
	
	if (dsq >= rhs) {
		cout << "YES" << ln;
	}
	else cout << "NO" << ln;
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
