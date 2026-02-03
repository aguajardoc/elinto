// Problem: C. Count Triangles
// Contest: Codeforces - Codeforces Round 643 (Div. 2)
// URL: https://codeforces.com/contest/1355/problem/C
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

void solve() {
    int A,B,C,D;
    cin >> A>>B>>C>>D;
	
	int ans = 0;
	for (int x = A; x <= B; x++) {
		int yF = C - x + 1; // First valid, st z = C
		int yL = D - x + 1; // Last, st z = D
		int zMax = x + C - 1;
		if (yF > C) continue;
		
		int surplus = max(0ll, zMax - D);
		surplus = min(surplus, C - B);
		
		int range = min(D, zMax) - C + 1;
		
		int L = 1, R = range;
		int d = B - yF;
		if (d > 0) L += d;
		
		L = min(L, R);
		
		// Add 1 to range
		ans += R * (R + 1) / 2 - (L * (L - 1)) / 2;
		
		// Add surplus
		ans += range * surplus;
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
