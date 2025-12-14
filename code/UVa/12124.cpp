// Problem: 12124 - Assemble
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3276
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
ll n, m;
map<string, vector<pair<ll, ll>>> items;

bool f(ll x, ll budget) {
	ll spent = 0;
	for (auto& i : items) {
		auto it = lower_bound(i.second.begin(), i.second.end(), make_pair(x, (ll)-1));
		if (it == i.second.end()) return false;
		spent += it->second;
	}
	// dbg(spent, budget, x);
	return (spent <= budget);
}

void solve() {
    cin >> n >> m;
    items.clear();
    for (int i = 0; i < n; i++) {
    	string type, name;
    	ll price, quality;
    	cin >> type >> name >> price >> quality;
    	items[type].push_back({quality, price});
    }
    
    for (auto& i : items) {
    	sort(i.second.begin(), i.second.end());
    	vector<pair<ll, ll>> newItem;
    	for (auto& j : i.second) {
			while (!newItem.empty() and newItem.back().second >= j.second) {
				newItem.pop_back();
			}
			newItem.push_back(j);
    	}
    	
    	items[i.first] = newItem;
    }
    
    ll l = 0, r = 1e12;
    ll ans = 0;
    while (l <= r) {
    	ll mid = (l + r) / 2;
    	
    	if (f(mid, m)) {
    		l = mid + 1;
    		ans = max(ans, mid);
    	}
    	else r = mid - 1;
    }
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
