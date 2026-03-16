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
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> AL(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    int ans = 0;
    vector<int> visited(n, 0);
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
    	if (visited[i]) continue;
    	
    	queue<int> q;
    	visited[i] = true;
    	color[i] = 1;
    	int ct1 = 1;
    	int ct2 = 0;
    	q.push(i);
    	bool bp = true;
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		
    		for (auto& v : AL[u]) {
    			if (visited[v]) {
    				if (color[v] == color[u]) {
    					bp = false;
    				}
    				continue;
    			}
    			
    			if (color[u] == 1) {
    				color[v] = 2;
    				ct2++;
    			}
    			else if (color[u] == 2) {
    				color[v] = 1;
    				ct1++;
    			}
    			visited[v] = true;
    			q.push(v);
    		}
    	}
    	
    	if (bp) ans += max(ct1, ct2);
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
