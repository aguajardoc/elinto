// Problem: F. Blackslex and Another RGB Walking
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

string type;

void solve() {
    if (type == "first") {
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
    	
    	
    	vector<int> color(n, INF);
    	queue<int> q;
    	q.push(0);
    	color[0] = 0;
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		
    		for (auto& v : AL[u]) {
    			if (color[v] != INF) continue;
    			
    			color[v] = (color[u] + 1) % 3;
    			q.push(v);
    		}
    	}
    	string rgb = "rgb";
    	for (auto& i : color) {
    		cout << rgb[i];
    	}
    	cout << ln;
    }
    else {
    	int q;
    	cin >> q;
    	while(q--) {
    		int colors;
    		string s;
    		cin >> colors >> s;
    		
    		set<char> seen;
    		for (auto& i : s) seen.insert(i);
    		
    		if (seen.size() == 1) {
    			cout << 1 << ln;
    		}
    		else {
    			bool r = seen.count('r');
    			bool g = seen.count('g');
    			bool b = seen.count('b');
    			
    			if (r and b) {
    				// find an r
    				cout << 1+find(s.begin(), s.end(), 'r') - s.begin() << ln;
    			}
    			else if (g and r) {
    				// find a g
    				cout << 1+find(s.begin(), s.end(), 'g') - s.begin() << ln;
    			}
    			else if (b and g) {
    				// find a b
    				cout << 1+find(s.begin(), s.end(), 'b') - s.begin() << ln;
    			}
    			else {
    				67/0;
    			}
    		}
    	}
    }
}

signed main() {
    fast_cin();
    cin >> type;
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
