// Problem: B. Multitasking
// Contest: Codeforces - Codeforces Round 225 (Div. 2)
// URL: https://codeforces.com/contest/384/problem/B
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> arr[i][j];
    	}
    }
    
    vector<pair<int, int>> ans;
    if (k == 0) {
    	for (int i = 0; i < m; i++) {
    		for (int j = i + 1; j < m; j++) {
    			ans.pb({i + 1, j + 1});
    		}
    	}
    }
    else {
    	for (int i = m - 1; i >= 0; i--) {
    		for (int j = i - 1; j >= 0; j--) {
    			ans.pb({i + 1, j + 1});
    		}
    	}
    }
    
    cout << ans.size() << ln;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first << " " << ans[i].second << ln;
    }
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
