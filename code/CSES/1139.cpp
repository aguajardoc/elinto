// Problem: Distinct Colors
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1139
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
const int MAXN = 200001;

int tin[MAXN], tout[MAXN], visited[MAXN], color[MAXN], nc[MAXN], ans[MAXN];
map<int, int> tlast;
int timer = 0;
int n;
vector<int> AL[MAXN];

void dfs(int u) {
	visited[u] = 1;
	nc[timer] = color[u];
	tin[u] = timer++;
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		
		dfs(v);
	}
	
	tout[u] = timer - 1;
}

const int TREE_SIZE = 1 << 18;
int st[2 * TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] = x;
	i >>= 1;
	while(i) {
		st[i] = st[2 * i] + st[2* i + 1];
		i >>= 1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res += st[l++];
		if (!(r&1)) res += st[r--];
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> color[i];
    }
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >>u >> v;
    	u--, v--;
    	
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    dfs(0);
    
    vector<vector<int>> queries;
    
    for (int i = 0; i < n; i++) {
    	queries.pb({tout[i], tin[i], i});
    }
    
    sort(queries.begin(), queries.end());
    for (auto& i : st) i = 0;
    
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
    	int R = queries[i][0];
    	int L = queries[i][1];
    	
    	while (idx <= R) {
    		int c = nc[idx];
    		if (tlast.count(c)) {
    			update(tlast[c], 0);
    		}
    		tlast[c] = idx;
    		update(idx, 1);
    		
    		idx++;
    	}
    	
    	ans[queries[i][2]] = query(L, R);
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << ln;
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
