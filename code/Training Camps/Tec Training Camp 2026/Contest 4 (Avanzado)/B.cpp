// Problem: B. Industrial Nim
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/B
// Memory Limit: 64 MB
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

int ans = 0;

void change(int n) {
	for (int i = 0; i <= 60; i++) {
		if ((1ll << i) > n) break;
		
		int x = (n - (1ll << i)) + 1;
		
		int z = x / ((1ll << (i + 1)));
		int y = x % (1ll << (i + 1));
		
		int change = (1ll << i) * z;
		int extra = min(y, (1ll << i));
		
		int total = change + extra;
		total %= 2;
		
		if (total) ans ^= (1ll << i);
	}
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    	int x, m;
    	cin >> x >> m;
    	change(m + x - 1);
    	change(x - 1);
    }
    
    cout << (ans ? "tolik":"bolik") << ln;
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
