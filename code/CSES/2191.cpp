// Problem: Polygon Area
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2191
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

typedef complex<int> point;
#define x real()
#define y imag()

void solve() {
    int n; cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        int X, Y; cin >> X >> Y;
        a[i] = point(X, Y);
    }
    a.pb(a.front());
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += a[i].x * a[i+1].y;
        ans -= a[i].y * a[i+1].x;
    }
    
    cout << abs(ans) << ln;
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
