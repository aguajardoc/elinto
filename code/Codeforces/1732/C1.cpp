// Problem: C1. Sheikh (Easy version)
// Contest: Codeforces - Codeforces Round 830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/C1
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    int cs = 0, cx = 0;
    vector<vector<int>> pref(n+1, vector<int>(32, 0));
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cs += a[i];
    	cx ^= a[i];
    	for (int j = 0; j < 31; j++) {
    		pref[i+1][j] = pref[i][j];
    		if (a[i] & (1ll << j)) {
    			pref[i+1][j]++;
    		}
    	}
    } 
    cin >> q >> q;
    
    int ans = cs - cx;
    int L = 1, R = n;
    
    for (int i = 0; i < n; i++) {
    	int l = i+1, r = n;
    	int br = INF;
    	while (l <= r) {
    		int m = (l + r) / 2;
    		
    		int fm = 0;
    		// dbg(i, m);
    		for (int j = 0; j < 31; j++) {
    			int ct = (pref[m][j] - pref[i][j]);
    			ct = ct / 2;
    			ct = ct * 2;
    			ct <<= j;
    			
    			// dbg(j, ct);
    			fm += ct;
    		}
    		
    		// dbg(i, m, fm, ans);
    		
    		if (fm == ans) {
    			br = min(br, m);
    			r = m - 1;
    		}
    		else {
    			l = m + 1;
    		}
    	}
    	
    	if (br != INF) {
    		int bl = i + 1;
    		// dbg(bl, br);
    		// dbg(L, R);
    		if (br - bl < R - L) {
    			L = bl;
    			R = br;
    		}
    	}
    }
    
    cout << L << " " << R << ln;
    
    
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
