// Problem: E - Simultaneous Update of Server Network
// Contest: AtCoder - AtCoder Weekday Contest 0157 Beta
// URL: https://atcoder.jp/contests/awc0157/tasks/awc0157_e
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

const int N = 200001;
// adj_t is the transpose of adj
std::vector<int> adj[N], adj_t[N];
std::vector<int> order;
std::vector<int> vis(N), id(N);

// calculates the order in which nodes are processed
void dfs1(int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) { dfs1(u); }
	}
	order.push_back(v);
}

/*
 * traverse one SCC at a time and
 * assign component ID to all nodes in one SCC
 */
void dfs2(int x, int comp) {
	vis[x] = true;

	for (int u : adj_t[x]) {
		if (!vis[u]) { dfs2(u, comp); }
	}
	id[x] = comp;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> rem(n+1);
    for (int i = 1; i <= n; i++) cin >> rem[i];
    for (int i = 1; i <= n; i++) rem[i] = -rem[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; rem[i] += x;
        rem[i] = max(0ll, rem[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj_t[v].pb(u);
    }
    
    vis.assign(N, false);
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }
    
    vis.assign(N, false);
    reverse(order.begin(), order.end());
    int comps = 0;
    for (auto& v : order) {
        if (!vis[v]) {
            comps++;
            dfs2(v, comps);
        }
    }
    
    int ans = 0;
    vector<int> mxid(n + 1, 0), perid(n + 1, 0);
    bool poss = true;
    for (int i = 1; i <= n; i++) {
        perid[id[i]]++;
        mxid[id[i]] = max(mxid[id[i]], rem[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (rem[i] and perid[id[i]] == 1) poss = false;
    }
    
    for (auto& i : mxid) {
        ans += i;
    }
    
    if (!poss) cout << -1 << ln;
    else cout << ans << ln;
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
