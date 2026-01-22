// Problem: D. Slime
// Contest: Codeforces - Codeforces Round 508 (Div. 2)
// URL: https://codeforces.com/contest/1038/problem/D
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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto& i : a) {
    	cin >> i;
    	sum += abs(i);
    }
    
    int ans = -INF;
    vector<int> lmin(n + 1, INF), rmin(n+1, INF);
    for (int i = 0; i < n; i++) {
    	lmin[i + 1] = min(lmin[i], a[i]);
    }
    for (int i = n-1; i >= 0; i--) {
    	rmin[i] = min(rmin[i + 1], a[i]);
    }
    
    for (int i = 0; i < n; i++) {
    	int L = lmin[i];
    	int R = rmin[i+1];
    	int local = sum;
    	
    	// dbg(L, R);
    	// dbg(i);
    	
    	if (L != INF) {
    		local -= abs(L);
    		local -= L;
    	}
    	
    	if (R != INF) {
    		local -= abs(R);
    		local -= R;
    	}
    	
    	local -= abs(a[i]);
    	local += a[i];
    	
    	ans = max(ans, local);
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
