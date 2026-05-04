// Problem: C - Project Selection
// Contest: AtCoder - AtCoder Weekday Contest 0051 Beta
// URL: https://atcoder.jp/contests/awc0051/tasks/awc0051_c
// Memory Limit: 1024 MB
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n), p(n);
    vector<pair<int, int>> conf(m);
    for (int i =0; i < n; i++) {
    	cin >> c[i] >> p[i];
    }
    
    for (int i = 0; i < m; i++) {
    	cin >> conf[i].first >> conf[i].second;
    	conf[i].first--;
    	conf[i].second--;
    }
    
    int ans = 0;
    
    for (int i = 0; i < (1ll << n); i++) {
    	int cost = 0;
    	bool conflict = false;
    	
    	for (auto& [u, v] : conf) {
    		if ((i & (1ll << u)) and
    			(i & (1ll << v))
    		) conflict = true;
    	}
    	
    	if (conflict) continue;
    	
    	int profit = 0;
    	
    	for (int j = 0; j < n; j++) {
    		if (i & (1ll << j)) {
    			profit += p[j];
    			cost += c[j];
    		}
    	}
    	
    	if (cost > k) continue;
    	
    	ans = max(ans, profit);
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
