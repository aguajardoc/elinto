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
    int n;
    cin >> n;
    
    vector<vector<int>> AL(n);
    
    for (int i = 0; i < n - 1; i++)  {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    
    vector<int> pct(n, 0), visited = pct;
    visited[0] = true;
    
    while (!q.empty()) {
    	int u = q.front();
    	
    	q.pop();
    	
    	for (auto& v : AL[u]) {
    		if (visited[v]) continue;
    		
    		dist[v] = dist[u] + 1;
    		visited[v] = true;
    		pct[u]++;
    		q.push(v);
    	}
    }
    
    
    vector<int> dpel(n + 1, 0);
    for (auto& i : dist) dpel[i]++;
    int mxd = *max_element(dpel.begin(), dpel.end());
    int mxc = 1+*max_element(pct.begin(), pct.end());
    
    // dbg(mxd, mxc);
    int ans = max(mxd, mxc);
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
