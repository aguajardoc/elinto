// Problem: 737 - Gleaming the Cubes
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=678
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

void solve() {
    int n;
    while (cin >> n and n) {
    	vector<int> mins(3, 1e9);
    	vector<int> maxs(3, -1e9);
    	
    	for (int i = 0; i < n; i++) {
    		int x, y, z, k;
    		cin >> x >> y >> z >> k;
    		int ex = x + k;
    		int ey = y + k;
    		int ez = z + k;
    		
    		mins[0] = min(mins[0], ex);
    		mins[1] = min(mins[1], ey);
    		mins[2] = min(mins[2], ez);
    		
    		maxs[0] = max(maxs[0], x);
    		maxs[1] = max(maxs[1], y);
    		maxs[2] = max(maxs[2], z);
    	}
    	
    	ll ans = 1;
    	for (int i = 0; i < 3; i++) {
    		ans *= (mins[i] - maxs[i]);
    	}
    	ans = max(ans, 0ll);
    	cout << ans << ln;
    }
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
