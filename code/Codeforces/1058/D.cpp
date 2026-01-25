// Problem: D. Vasya and Triangle
// Contest: Codeforces - Codeforces Round 512 (Div. 2, based on Technocup 2019 Elimination Round 1)
// URL: https://codeforces.com/contest/1058/problem/D
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
    int n, m, k;
    cin >> n >> m >> k;
    
    int res = (2 * m * n);
    if (res % k) {
    	cout << "NO" << ln;
    	return;
    }
    
    int a, b;
    
    int x = gcd(n, k);
    
    // 1
    if ((2 * m * x) % k == 0) {
    	a = n / x, b = 2 * m * x / k;
    	
    	if (a <= n and b <= m) {
    		cout << "YES" << ln;
    		cout << 0 << " " << 0 << ln;
    		cout << a << " " << 0 << ln;
    		cout << 0 << " " << b << ln;
    		return;
    	}
    }
    if ((m * x) % k == 0) {
    	a = 2 * n / x, b = m * x / k;
    	
    	if (a <= n and b <= m) {
    		cout << "YES" << ln;
    		cout << 0 << " " << 0 << ln;
    		cout << a << " " << 0 << ln;
    		cout << 0 << " " << b << ln;
    		return;
    	}
    }
    // 2
    x = gcd(m, k);
    if ((2 * n * x) % k == 0) {
    	a = 2 * n * x / k, b = m / x;
    	
    	if (a <= n and b <= m) {
    		cout << "YES" << ln;
    		cout << 0 << " " << 0 << ln;
    		cout << a << " " << 0 << ln;
    		cout << 0 << " " << b << ln;
    		return;
    	}
    }
    if ((n * x) % k == 0) {
    	a = n * x / k, b = 2 * m / x;
    	
    	if (a <= n and b <= m) {
    		cout << "YES" << ln;
    		cout << 0 << " " << 0 << ln;
    		cout << a << " " << 0 << ln;
    		cout << 0 << " " << b << ln;
    		return;
    	}
    }
    
    cout << "NO" << ln;
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
