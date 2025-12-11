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
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 998244353

double eps = 1e-9;
vector<pair<ll, ll>> nodes;
vector<vector<ll>> AL;
set<pair<ll, ll>> visited;
map<ll, ll> nodetoval;
ll ans = 0;

void dfs(ll u, ll& len, ll oneago, ll twoago) {
	twoago = oneago;
	oneago = nodetoval[u];
	
	bool called = false;
	for (auto& v : AL[u]) {
		// dbg(twoago, oneago, nodetoval[v]);
		if (twoago == -1 or twoago - oneago == nodetoval[v]) {
						called = true;
			if (!visited.insert(make_pair(u, v)).second) continue;
			// dbg(u, v);

			len++;
			dfs(v, len, oneago, twoago);
			len--;
		}
	}
	// dbg(len , u, called);
	
	if (!called) {
		ll loca = (len * (len - 1ll)) / 2ll;
		loca %= MOD;
		// dbg(loca);
		ans += loca;
		ans %= MOD;
	}
}

void solve() {
    ll n, m;
    cin >> n >> m;
    AL.assign(n, vector<ll>());
    visited.clear();
    nodes.assign(n, make_pair(0, 0));
    nodetoval.clear();
    ans = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		nodes[i] = {x, i};
		nodetoval[i] = x;
	}
	
	sort(nodes.rbegin(), nodes.rend());
	for (ll i = 0; i < m ; i++) {
		ll u, v;
		cin >> u >> v;
		u--, v--;
		AL[v].push_back(u);
	}
	
	for (ll i  = 0; i < n ; i++) {
		ll node = nodes[i].second;
		ll len = 1;
		// dbg(node);
		dfs(node, len, -1, -1);
	}
	
	cout << ans << ln;
}

int main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
