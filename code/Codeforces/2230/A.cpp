// Problem: A. Optimal Purchase
// Contest: Codeforces - Educational Codeforces Round 190 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2230/problem/A
// Memory Limit: 512 MB
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
    int n, a, b;
    cin >> n >> a >> b;
    
	int ans = 0;
	
	while (n) {
		if (n % 3 == 1) {
			n--;
			if (a < b) {
				ans += a;
			}
			else ans += b;
		}
		else if (n % 3 == 2) {
			n-=2;
			if (2*a < b) {
				ans += 2*a;
			}
			else ans += b;
		}
		else {
			if (3*a < b) {
				ans += a*n;
			}
			else ans += b*(n/3);
			
			n = 0;
		}
	}
	
	cout << ans << ln;
    
    
    
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
