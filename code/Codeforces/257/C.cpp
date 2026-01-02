// Problem: C. View Angle
// Contest: Codeforces - Codeforces Round 159 (Div. 2)
// URL: https://codeforces.com/contest/257/problem/C
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

void solve() {
    // get angles wrt to origin
    // sort :)
    // find lgest gap between two
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<ld> angles(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    	
    	angles[i] = atan2(a[i].second, a[i].first);
    	// dbg(angles[i]);
    }
    
    sort(angles.begin(), angles.end());
    angles.resize(unique(angles.begin(), angles.end()) - angles.begin());
    ld ans = 0;
    n = angles.size();
    
    for (int i = 0; i <= n; i++) {
    	ld x = angles[(i) % n];
    	ld y = angles[(i + 1) % n];
    	
    	ld d = y - x;
    	if (d < 0) d += 2 * PI;
    	
    	ans = max(d, ans);
    }
    ans = 180 * ans / PI;
    ans = 360 - ans;
    
    if (n == 1) ans = 0;
    
    cout << fixed << setprecision(10) << ans << ln;
    
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
