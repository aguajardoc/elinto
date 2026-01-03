// Problem: C. Mafia
// Contest: Codeforces - Codeforces Round 202 (Div. 2)
// URL: https://codeforces.com/contest/349/problem/C
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
vector<int> a;

bool f(int x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int d = x - a[i];
		if (d < 0) return false;
		sum += d;
	}
	
	return sum >= x;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    int ans = 1e14;
    int l = 1, r = 1e14;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	bool fm = f(m);
    	
    	if (fm) {
    		r = m - 1;
    		ans = min(ans, m);
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
