// Problem: C. Little Girl and Maximum Sum
// Contest: Codeforces - Codeforces Round 169 (Div. 2)
// URL: https://codeforces.com/contest/276/problem/C
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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> pmul(n + 1, 0);
    
    vector<pair<int, int>> queries;
    
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	queries.pb({l, r});
    	l--, r--;
    	pmul[l]++;
    	pmul[r+1]--;
    	
    	
    }
    
    vector<pair<int, int>> mults(n, {0, 0});
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	cur += pmul[i];
    	mults[i] = {cur, i};
    }
    
    sort(mults.rbegin(), mults.rend());
    sort(a.rbegin(), a.rend());
    vector<int> na(n);
    
    for (int i = 0; i < n; i++) {
    	na[mults[i].second] = a[i];
    }
    
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] + na[i];
    }
    
    int ans = 0;
    for (auto& [l, r] : queries) {
    	ans += pref[r] - pref[l-1];
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
