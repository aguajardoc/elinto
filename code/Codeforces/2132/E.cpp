// Problem: E. Arithmetics Competition
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/E
// Memory Limit: 256 MB
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

struct Node {
	int val, numa, numb, numtot;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    vector<Node> tot;
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    vector<int> prefa(n+1, 0), prefb(m+1,0);
    for (int i = 1; i <= n; i++) {
    	prefa[i] = prefa[i-1] + a[i-1];
    }
    
    for (int i = 1; i <= m; i++) {
    	prefb[i] = prefb[i-1] + b[i-1];
    }
    
    tot = {{0,0,0,0}};
    
    int l = 0, r = 0;
    while (l < n and r < m) {
    	int prev = tot.back().val;
    	if (a[l] > b[r]) {
    		tot.pb({prev + a[l], l + 1, r, l + r + 1});
    		l++;
    	}
    	else {
    		tot.pb({prev + b[r], l, r + 1, l + r + 1});
    		r++;
    	}
    }
    
    while (l < n) {
    	int prev = tot.back().val;
    	tot.pb({prev + a[l], l + 1, r, l + r + 1});
    	l++;
    }
    
    while (r < m) {
    	int prev = tot.back().val;
    	tot.pb({prev + b[r], l, r + 1, l + r + 1});
    	r++;
    }
    
    while(q--) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	if (z == 0) {
    		cout << 0 << ln;
    		continue;
    	}
    	
    	// Find first index where z == numtot
    	int ans = 0;
    	if (tot[z].numa <= x and tot[z].numb <= y) ans = tot[z].val;
    	
    	// Find first index where x == numa
    	int resa = 0;
    	int nx = min(x, z);
		resa += prefa[nx];
		resa += prefb[z - nx];
    	
    	
    	// Find first index where y == numb
    	int resb = 0;
    	int ny = min(y, z);
    	resb += prefb[ny];
    	resb += prefa[z - ny];
    	
    	
    	// dbg(ans, resa, resb);
    	
    	ans = max({ans, resa, resb});
    	
    	
    	cout << ans << ln;
    }
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
