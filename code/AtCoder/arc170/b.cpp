// Problem: B - Arithmetic Progression Subsequence
// Contest: AtCoder - AtCoder Regular Contest 170
// URL: https://atcoder.jp/contests/arc170/tasks/arc170_b
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

struct Range {
	int l, r;
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<vector<int>> pos(11);
    for (int i = 0; i < n; i++) {
    	pos[a[i]].pb(i);
    }
    
    vector<Range> valid;
    multiset<int> actives;
    for (int i = 0; i < n; i++) {
    	Range nr = {i, INF};
    	for (int j = -4; j <= 4; j++) {
    		int b = a[i] + j;
    		int c = b + j;
    		
    		if (c <= 0 or c > 10) continue;
    		
    		auto itb = upper_bound(pos[b].begin(), pos[b].end(), i);
    		if (itb == pos[b].end()) continue;
    		
    		int bidx = *itb;
    		auto itc = upper_bound(pos[c].begin(), pos[c].end(), bidx);
    		if (itc == pos[c].end()) continue;
    		
    		int cidx = *itc;
    		
    		nr.r = min(nr.r, cidx);
    	}
    	
    	if (nr.r != INF) {
    		valid.pb(nr);
    		
    		// dbg(i, nr.r);
    		actives.insert(nr.r);
    	}
    }
    
    int idx = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	if (actives.empty()) continue;
    	int res = n - *actives.begin();
    	// dbg(i);
    	// dbg(*actives.begin());
    	// dbg(res);
    	ans += res;
    	
    	while (idx < valid.size() and valid[idx].l == i) {
    		actives.erase(actives.find(valid[idx].r));
    		idx++;
    	}
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
