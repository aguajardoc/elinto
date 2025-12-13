// Problem: B. Simple Game
// Contest: Codeforces - Codeforces Round 316 (Div. 2)
// URL: https://codeforces.com/contest/570/problem/B
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
    	cout << 1 << ln;
    	return;
    }
    if (m == 1) {
    	cout << 2 << ln;
    	return;
    }
    if (m == n) {
    	cout << n -1 << ln;
    	return;
    }
    
	int lwins = m;
	int rwins = n - m + 1;
	// dbg(lwins, rwins);
	if (lwins >= rwins) {
		cout << m - 1 << ln;
		return;
	}
	else {
		cout << m + 1 << ln;
	}
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
