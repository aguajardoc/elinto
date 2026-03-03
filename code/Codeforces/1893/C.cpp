// Problem: C. Freedom of Choice
// Contest: Codeforces - Codeforces Round 908 (Div. 1)
// URL: https://codeforces.com/contest/1893/problem/C
// Memory Limit: 512 MB
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

void solve() {
    int m;
    cin >> m;
    
    int sli = 0, sri = 0;
    vector<vector<int>> a(m);
    vector<map<int, int>> c(m);
    vector<int> L(m), R(m);
    vector<int> sc(m);
    set<int> values;
    for (int i = 0; i < m; i++) {
    	int n, l, r;
    	cin >> n >> l >> r;
    	sli += l;
    	sri += r;
    	
    	L[i] = l;
    	R[i] = r;
    	
    	for (int j = 0; j < n; j++) {
    		int x;
    		cin >> x;
    		a[i].pb(x);
    		values.insert(x);
    	}
    	for (int j = 0; j < n; j++) {
    		int x;
    		cin >> x;
    		c[i][a[i][j]] = x;
    		sc[i] += x;
    	}
    }
    
    // 0 check
    int mapped = 0;
    for (auto& i : values) {
    	if (i >= sli and i <= sri) mapped++;
    }
    
    if (mapped < sri - sli + 1) {
    	cout << 0 << ln;
    	return;
    }
    
    // Get min incur and extra cushion
    map<int, int> minIncur, extraCushion;
    for (int i = sli; i <= sri; i++) {
    	extraCushion[i] = sri - sli;
    }
    for (int i = 0; i < m; i++) {
    	// dbg(i);
    	for (int j = 0; j < a[i].size(); j++) {
    		int rest = sc[i] - c[i][a[i][j]];
    		int mc = max(0ll, L[i] - rest);
    		int ec = max(0ll, min(rest - L[i], R[i] - L[i]));
    		
    		// dbg(a[i][j]);
    		// dbg(mc, ec);
    		// cout << ln;
    		
    		minIncur[a[i][j]] += mc;
    		
    		int diff = R[i] - L[i] - ec;
    		
    		extraCushion[a[i][j]] -= diff;
    	}
    	// cout << ln << ln;
    }
    
	// For all of the rest that dont show up, EC is R[i] - L[i]
	// 100% of the time, that is true!
	
	// for (auto& i : minIncur) {
		// dbg(i.first);
		// dbg(i.second);
	// }
	int ans = INF;
	for (int i = sli; i <= sri; i++) {
		int local = minIncur[i] + max(0ll, i - sli - extraCushion[i]);
		ans = min(ans, local);
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
