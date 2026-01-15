// Problem: A. Knapsack
// Contest: Codeforces - Codeforces Round 683 (Div. 1, by Meet IT)
// URL: https://codeforces.com/problemset/problem/1446/A
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
	int n, w;
	cin >> n >> w;
	int goal = w/2 + w % 2;
    vector<pair<int, int>> a;
    bool rf = false;
    int idxa = -1;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (x <= goal) {
    		a.pb({x, i});
    	}
    	else if (x >= goal and x <= w) {
    		rf = true;
    		idxa = i + 1;
    	}
    }
    
    if (rf) {
    	cout << 1 << ln;
    	cout << idxa << ln;
    	return;
    }
    
    if (a.empty()) {
    	cout << -1 << ln;
    	return;
    }
    
    sort(a.rbegin(), a.rend());
    
    int cur = 0;
    vector<int> ans;
    int i = 0;
    while (i < a.size() and cur < goal) {
    	cur += a[i].first;
    	ans.pb(a[i].second + 1);
    	i++;
    }
    
    if (cur < goal) {
    	cout << -1 << ln;
    	return;
    }
    
    cout << ans.size() << ln;
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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
