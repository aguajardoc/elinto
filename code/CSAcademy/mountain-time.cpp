// Problem: Mountain Time
// Contest: CS Academy
// URL: https://csacademy.com/contest/archive/task/mountain-time
// Memory Limit: 512 MB
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

vector<int> parent, z, mx, mn, ans, flat;
vector<vector<int>> pending;
int gmax, set_count;

int find_set(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void make_set(int v, int val) {
	set_count++;
	parent[v] = v;
	z[v] = 1;
	mx[v] = val;
	mn[v] = val;
	if (val == gmax) {
		ans[v] = gmax;
	}
	else {
		pending[v].pb(v);	
	}
}

void join(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) return;
	set_count--;
	
	if (z[a] < z[b]) swap(a, b);
	
	parent[b] = a;
	z[a] += z[b];
	
	// min: 4, 5
	// max: 9, 6
	
	// if max increases, all pending must be proc
	
	if (mx[a] > mx[b]) {
		// all pending in b get set to min of both
		while (!pending[b].empty()) {
			ans[pending[b].back()] = flat[pending[b].back()] - min(mn[a], mn[b]);
			pending[b].pop_back();
		}
	}
	else if (mx[b] > mx[a]) {
		while (!pending[a].empty()) {
			ans[pending[a].back()] = flat[pending[a].back()] - min(mn[a], mn[b]);
			pending[a].pop_back();
		}
		for (auto& i : pending[b]) {
			pending[a].pb(i);
		}
	}
	else {
		for (auto& i : pending[b]) {
			pending[a].pb(i);
		}
	}
	
	mx[a] = max(mx[a], mx[b]);
	mn[a] = min(mn[a], mn[b]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int k = n * m;
    parent.assign(k, 0);
    iota(parent.begin(), parent.end(), 0);
    z.assign(k, 0);
    mx.assign(k, -1);
    mn.assign(k, INF);
    ans.assign(k, 0);
    flat.assign(k, 0);
    pending.assign(k, vector<int>());
    
    vector<vector<int>> mat(n, vector<int> (m, 0));
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> mat[i][j];
    		flat[i*m+j] = mat[i][j];
    		order.pb({mat[i][j], i*m + j});
    		gmax = max(gmax, mat[i][j]);
    	}
    }
    
    sort(order.rbegin(), order.rend());
    
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    for (int v = 0; v < k; v++) {
        int val = order[v].first;
        int u = order[v].second;
        make_set(u, val);
        
        int x = u / m;
        int y = u % m;
    		
		for (auto& [dx, dy] : dir) {
			int nx = x + dx;
			int ny = y + dy;
			
			if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
			int conv = nx*m + ny;
			if (!z[conv]) continue;
			
			join(u, conv);
		}
    }
    
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++) {
    		cout << ans[i*m+j] << " ";
    	}
    	cout << ln;
    }
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
