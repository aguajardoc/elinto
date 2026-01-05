// Problem: C. Molly's Chemicals
// Contest: Codeforces - ICM Technex 2017 and Codeforces Round 400 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/776/problem/C
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pows;
    for (auto& i : a) cin >> i;
    if (k == 1) pows = {1};
    else if (k == -1) pows = {-1, 1};
    else {
    	int cur = 1;
    	while (abs(cur) <= 1e14) {
    		pows.pb(cur);
    		cur *= k;
    	} 
    }
    
    map<int, int> ct;
    int ans = 0;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] + a[i];
    	ct[pref[i + 1]]++;
    }
    ct[0]++;
    
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j < pows.size(); j++) {
    		int target = pows[j] + pref[i];
    		ans += ct[target];
    	}
    	ct[pref[i]]--;
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
