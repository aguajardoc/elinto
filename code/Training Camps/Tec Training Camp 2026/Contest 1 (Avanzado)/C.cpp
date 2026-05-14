// Problem: C. Best Pair
// Contest: Codeforces - TC Tec 2026 Contest 1 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690676/problem/C
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    // [i] -> map of what the best i can be with a count
    vector<int> a;
    unordered_map<int, int> ct;
    vector<int> counts;
    unordered_map<int, vector<int>> count_to_num;
    vector<pair<int, int>> banned(m);
    
    for (int i = 0; i < n; i++) {
    	int x; cin >> x; ct[x]++;
    	a.pb(x);
    }
    
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    
    for (auto& i : ct) {
    	counts.pb(i.second);
    	count_to_num[i.second].pb(i.first);
    }
    
    sort(counts.rbegin(), counts.rend());
    counts.resize(unique(counts.begin(), counts.end()) - counts.begin());
    for (auto& i : count_to_num) {
    	sort(i.second.rbegin(), i.second.rend());
    }
    
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	if (u > v) swap(u, v);
    	
    	banned[i] = {u, v};
    }
    
    sort(banned.begin(), banned.end());
    
    // iterate over all pairs of counts
    ll ans = 0;
    for (int i = 0; i < counts.size(); i++) {
    	int x = counts[i];
    	for (int j = i; j < counts.size(); j++) {
    		int y = counts[j];
    		
    		// check for best
    		for (auto& k : count_to_num[x]) {
    			
    			for (auto& l : count_to_num[y]) {
    				if (k == l) continue;
    				
    				if (!binary_search(
	    				banned.begin(), banned.end(),
	    			make_pair(min(k, l), max(k, l)))) {
	    				
	    				ans = max(ans, 
		    				(0ll + x + y) * (k + l)
		    			);
	    				break;
	    			}
    			}
    		}
    	}
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
