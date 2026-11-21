// Problem: C. Reimu Hakurei and the Youkai
// Contest: Codeforces - Codeforces Round 1136 (Div. 2)
// URL: https://codeforces.com/contest/2288/problem/C
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
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    map<int, int> ct;
    int to_use = 0;
    for (int i = 0; i < n - 1; i++) {
    	if (a[i] <= x) to_use++;
    	else ct[a[i]]++;
    }
    
    int killed = 0;
    int ans = 0;
    while (true) {
    	// dbg(killed, ans);
    	// dbg(to_use);
    	while (to_use > 0) {
    		killed++;
    		to_use--;
    		
    		// Get everything from [killed + 1, killed + x]
    		auto it = ct.lower_bound(x*killed + 1);
    		// dbg(it->first);
	    	// dbg(x*killed+1);
	    	// dbg(x*killed+x);
    		vector<int> dead;
    		while (it != ct.end() and it->first <= x*killed + x) {
    			to_use += it->second;
    			dead.pb(it->first);
    			it++;
    		}
    		for (auto& i : dead) ct.erase(i);
    	}
    	
    	auto it = ct.lower_bound(x*killed + 1);
    	if (it == ct.end()) break;
    	
    	int change = (it->first - x*killed)/x + min(1ll, (it->first-x*killed)%x);
    	killed += change - 1;
    	ans += change - 1;
    	
    	// dbg(killed);
    	it = ct.lower_bound(x*killed + 1);
    	// dbg(it->first);
    	
    	vector<int> dead;
		while (it != ct.end() and it->first <= x*killed + x) {
			to_use += it->second;
			dead.pb(it->first);
			it++;
		}
		for (auto& i : dead) ct.erase(i);
    }
    
    cout << ans << ln;
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
