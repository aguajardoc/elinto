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

struct Node {
	int leaves, nl;
	bool isLeaf;
};

vector<Node> nodes;
vector<vector<int>> AL;
vector<int> ans;

pair<int, int> dfs(int u, int leaves, int nl) {
	
	for (auto& v : AL[u]) {
		pair<int, int> x = dfs(v, leaves, nl + 1);
		nodes[u].leaves += x.first;
		nodes[u].nl += x.second;
	}
	
	if (AL[u].empty()) {
		nodes[u].isLeaf = true;
		return {nodes[u].leaves + 1, nodes[u].nl};
	}
	else {
		return {nodes[u].leaves, ++nodes[u].nl};
	}
}

void ndfs(int u, int par) {
	
	// if is leaf, take from parent
	if (par == -1) {
		if (nodes[u].isLeaf) {
			ans[u]++;
			ans[u] %= MOD;
		}
		else {
			ans[u] += nodes[u].leaves;
			ans[u] %= MOD;
			ans[u] += 3ll * nodes[u].nl;
			ans[u] %= MOD;
		}
	}
	else if (nodes[u].isLeaf) {
		ans[u] += ans[par] + 1;
		ans[u] %= MOD;
	}
	else {
		ans[u] += ans[par]; 
		ans[u] %= MOD;
		ans[u] += nodes[u].leaves;
		ans[u] %= MOD;
		ans[u] += 3ll * nodes[u].nl;
		ans[u] %= MOD;
	}
	
	for (auto& v: AL[u]) {
		ndfs(v, u);
	}
}

void solve() {
    int n;
    cin >> n;
    nodes.assign(n, {0, 0, false});
    ans.assign(n, 0);
    
    AL.assign(n, vector<int>());
    
    for (int i = 0; i < n; i++) {
    	int l, r;
    	cin >> l >> r;
    	if (l == 0) continue;
    	
    	AL[i].pb(l-1);
    	AL[i].pb(r-1);
    }
    
    dfs(0, 0, 0);
    ndfs(0, -1);
    
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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
