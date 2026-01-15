// Problem: C. Hiring Staff
// Contest: Codeforces - Codeforces Round 133 (Div. 2)
// URL: https://codeforces.com/contest/216/problem/C
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
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 2 and m == 2 and k == 1) {
    	cout << 4 << ln;
    	cout << "1 2 3 4\n";
    	return;
    }
    if (k == 1) {
    	if (n == m) {
    		cout << 3 << ln << 1 << " " << n << " " << 2 * n - 1 << ln;
    	}
    	else if (n == m + 1) {
    		cout << 3 << ln << 1 << " " << n << " " << n + m << ln;
    	}
    	else {
    		cout << 2 << ln << 1 << " " << n << ln;
    	}
    }
    else {
    	
		cout << 2 * k + (n == m) << ln;
		for (int i = 0; i < k; i++) cout << 1 << " ";
		cout << n << " ";
		for (int i = 0; i < k - 1; i++) cout << n + 1 << " ";
		if (n == m) cout << 2 * m << ln;
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
