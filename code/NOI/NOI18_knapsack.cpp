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
    int n, s;
    cin >> s >> n;
    vector<pair<int, int>> VW;
    
    for (int i = 0; i < n; i++) {
    	int v, w, k;
    	cin >> v >> w >> k;
    	
    	int c = 1;
    	while(k > c) {
    		k -= c;
    		if (w * c <= s) {
    			VW.pb({w*c, v*c});
    		}
    		c<<=1;
    	}
    	if (k) {
    		if (w * k <= s) {
    			VW.pb({w*k, v*k});
    		}
    	}
    }
    
    sort(VW.rbegin(), VW.rend());
    vector<int> occ(2001, 0);
    vector<pair<int, int>> NVW;
    
    for (int i = 0; i < VW.size(); i++) {
    	int W = VW[i].first;
    	if (occ[W] <= s/W) {
    		occ[W]++;
    		NVW.pb(VW[i]);
    	}
    }
    
    int dp[2001];
    fill_n(&dp[0], 2001, 0);
    
    for (int i = 0; i < NVW.size(); i++) {
    	for (int j = s; j >= NVW[i].first; j--) {
			dp[j] = max(dp[j],
						dp[j - NVW[i].first] + NVW[i].second
			);
    	}
    }
    
    cout << dp[s] << ln;
    
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
