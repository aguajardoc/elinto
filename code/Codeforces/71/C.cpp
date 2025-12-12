// Problem: C. Round Table Knights
// Contest: Codeforces - Codeforces Beta Round 65 (Div. 2)
// URL: https://codeforces.com/contest/71/problem/C
// Memory Limit: 256 MB
// Time Limit: 500 ms
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
    int n;
    cin >> n;
    vector<int> moods(n);
    for (auto& i : moods) cin >> i;
    
    // for all divisors
    for (int i = 3; i <= n; i++) {
		if (n % i) continue;
	    // for all starting positions
		for (int j = 0; j < n/i; j++) {
			// dbg(i, j);
			bool poss = true;
			// for all coords
			for (int k = j; k != n + j; k += n / i) {
				// dbg(i, j, k, moods[k % n]);
				if (!moods[k % n]) poss = false;
			}
			if (poss) {
			cout << "YES" << ln;
			return;
		}
		}
	}
	
	cout << "NO" << ln;
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
