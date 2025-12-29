// Problem: B. Restoring Painting
// Contest: Codeforces - Codeforces Round 353 (Div. 2)
// URL: https://codeforces.com/contest/675/problem/B
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
    int n;
    cin >> n;
    vector<int> a(4);
    for (auto& i : a) cin >> i;
    if (a[0] < a[3]) swap(a[0], a[3]);
    if (a[1] < a[2]) swap(a[1], a[2]);
	
	int c1 = a[1] - a[2];
	int c2 = a[0] - a[3];
	int c3 = a[0] + a[1] - a[2] - a[3];
	
	// dbg(c1, c2, c3);
	
	int r = max({c1, c2, c3});
	int r2 = n - r;
	r2 = max(0ll, r2);
	int ans = n * r2;
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
