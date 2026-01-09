// Problem: F. Consecutive Subsequence
// Contest: Codeforces - Codeforces Round 479 (Div. 3)
// URL: https://codeforces.com/problemset/problem/977/F
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
    map<int, set<int>> idx;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	idx[a[i]].insert(i);
    }
    
    
    vector<int> dp(n, 1);
    
    for (int i = n - 1; i >= 0; i--) {
    	auto it = idx[a[i] + 1].upper_bound(i);
    	if (it != idx[a[i] + 1].end()) {
    		dp[i] = 1 + dp[*it];
    	}
    }
    
    int res = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
    	if (dp[i] > res) {
    		res = dp[i];
    		start = i;
    	}
    }
    
    vector<int> ans;
    
    while (true) {
    	ans.pb(start);
    	if (dp[start] == 1) break;
    	start = *idx[a[start] + 1].upper_bound(start);
    } 
    
    cout << res << ln;
    for (auto& i : ans) {
    	cout << i + 1 << " ";
    }
    cout << ln;
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
