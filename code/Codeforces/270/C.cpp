// Problem: C. Magical Boxes
// Contest: Codeforces - Codeforces Round 165 (Div. 2)
// URL: https://codeforces.com/contest/270/problem/C
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

int n;
map<int, int> ct;

bool f(int x) {
	int cap = 1;
	
	for (int i = x; i >= max(0ll, x - 20); i--, cap *= 4) {
		if (ct[i] > cap) return false;
	}
	return true;
}

void solve() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	ct[x] = y;
    }
    int ans = 1e10;
    int l = ct.rbegin()->first + 1, r = 1e10;
    while (l <= r) {
    	// dbg(l, r);
    	int m = (l + r) / 2;
    	
    	bool poss = f(m);
    	
    	if (poss) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else {
    		l = m + 1;
    	}
    }
    
    cout << ans << ln;
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
