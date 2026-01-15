// Problem: C. Alyona and Spreadsheet
// Contest: Codeforces - Codeforces Round 401 (Div. 2)
// URL: https://codeforces.com/contest/777/problem/C
// Memory Limit: 256 MB
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void build(vector<vector<int>>& pref, vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			int cost = (grid[j][i] < grid[j-1][i]);
			pref[j][i] = pref[j-1][i] + (cost);
		}
	}
}

bool getResult(vector<vector<int>>& pref, int l, int r) {
	if (l == r) return true;
	int n = pref.size();
	int m = pref[0].size();
	
	// Find a col that is increasing
	for (int i = 0; i < m; i++) {
		int now = pref[l][i];
		int then = pref[r][i];
		
		if (now == then) return true;
	}
	
	return false;
}

void precompute(vector<vector<int>>& pref, vector<vector<int>>& queries) {
	int n = pref.size();
	int m = pref[0].size();
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			queries[i][j] = getResult(pref, i, j);
		}
	}
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m, 0));
    for (int i=0; i< n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> grid[i][j];
    	}
    }
    
    // Query count depends on n
    // n can be up to 1e5, but with m = 1
    // We can check answer to query in O(m)
    // Meaning that up to m = 100 ish we are safe, maybe 1000
    // m = 100 ==> n = 1e3 (5e5 possible queries)
    // m = 250 ==> n = 400 (8e4 possible queries)
    // m = 500 ==> n = 2e2 (2e4 possible queries)
    // m = 1000 ==> n = 1e2 (5e3 possible queries)
    
    // If m <= 250, just do the queries, else precoumpte all queries
    vector<vector<int>> queries;
    vector<vector<int>> pref(n, vector<int> (m, 0));
    build(pref, grid);
    if (m > 250) {
    	queries.assign(n, vector<int> (n, 0));
    	precompute(pref, queries);
    }
    
    int q;
    cin >> q;
    while(q--)  {
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	bool res;
    	if (m <= 250) {
    		res = getResult(pref, l, r);
    	}
    	else {
    		res = queries[l][r];
    	}
    	
    	cout << (res ? "Yes":"No") << ln;
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
