// Problem: D1. Tree Orientation (Easy Version)
// Contest: Codeforces - Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/D1
// Memory Limit: 1024 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	mat[i] = s;
    }
    
    vector<vector<int>> AL(n), AL2(n);
    bool poss = true;
    int edges = 0;
    for (int u = 0; u < n; u++) {
    	for (int v = 0; v < n; v++) {
    		if (u == v or mat[u][v] == '0') continue;
    		
    		bool corr = true;
    		for (int w = 0; w < n; w++) {
    			if (w == u or w == v) continue;
    			
    			if (mat[u][w] == '1' and mat[w][v] == '1') {
    				corr = false;
    				break;
    			}
    		}
    		
    		if (corr) {
    			AL[u].pb(v);
    			AL2[u].pb(v);
    			AL2[v].pb(u);
    			edges++;
    		}
    	}
    }
    
    if (edges != n - 1) poss = false;
    
    vector<string> tm(n, string(n, '0'));
    for (int i = 0; i < n; i++) {
    	queue<int> q;
    	vector<int> visited(n, 0);
    	q.push(i);
    	visited[i] = 1;
    	tm[i][i] = '1';
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		
    		for (auto& v : AL[u]) {
    			if (visited[v]) {
    				poss = false;
    				continue;
    			}
    			
    			tm[i][v] = '1';
    			visited[v] = 1;
    			q.push(v);
    		}
    	}
    }
    
    if (tm != mat) poss = false;
    
    queue<int> q;
	vector<int> visited(n, 0);
	q.push(0);
	visited[0] = 1;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (auto& v : AL2[u]) {
			if (visited[v]) {
				continue;
			}
			
			visited[v] = 1;
			q.push(v);
		}
	}
    
    if (count(visited.begin(), visited.end(), 0)) poss = false;
    
    if (!poss) {
    	cout << "No" << ln;
    }
    else {
    	cout << "Yes" << ln;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < AL[i].size(); j++) {
    			cout << i + 1 << " " << AL[i][j] + 1 << ln;
    		}
    	}
    }
    
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
