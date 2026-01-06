// Problem: 10218 - Let's Dance !!!
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1159
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

ld ncr[1001][1001];

ld recurse(int n, int r) {
	if (n == r) return ncr[n][r] = 1;
	if (r == 1) return ncr[n][r] = n;
	if (r == 0) return ncr[n][r] = 1;
	
	if (ncr[n][r] > -1 + eps) return ncr[n][r];
	
	return ncr[n][r] = recurse(n - 1, r) + recurse(n - 1, r - 1);
}

void solve() {
    int m, w, c;
    
    while (cin >> m) {
    	cin >> w >> c;
    	if (m == 0 and w == 0) break;
    
	    ld p = (ld)m/(ld)(w + m);
	    
	    ld ans = 0;
	    for (int i = 0; i <= c; i += 2) {
	    	ans += recurse(c, i) * pow((ld)p, i) * pow((ld)1 - p, (c - i));
	    	// dbg(ans);
	    }
	    
	    // dbg(p, m, w);
	    
	    cout << fixed << setprecision(7) << ans << ln;
	}
}

signed main() {
    fast_cin();
    for (auto& i : ncr) for (auto& j : i) j = -1;
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
