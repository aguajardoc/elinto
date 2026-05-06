// Problem: I. Little Girl and Maximum Sum
// Contest: Codeforces - TC Tec 2026 Contest 1 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690676/problem/I
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), psum(n + 1, 0);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> queries;
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--;
    	psum[l]++;
    	psum[r]--;
    	
    	queries.pb({l, r});
    }
    
    vector<int> occ(n, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	cur += psum[i];
    	occ[i] = cur;
    }
    
    vector<pair<int, int>> occto;
    
    for (int i = 0; i < n; i++) {
    	occto.pb({occ[i], i});
    }
    
    sort(occto.rbegin(), occto.rend());
    
    sort(a.rbegin(), a.rend());
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
    	b[occto[i].second] = a[i];
    }
    
    int ans = 0;
    vector<int> pgood(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
    	pgood[i+1] = pgood[i] + b[i];
    }
    
    
    for (auto& [l, r] : queries) {
    	ans += pgood[r] - pgood[l];
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
