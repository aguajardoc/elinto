// Problem: 1080. Map Coloring
// Contest: Timus Online Judge - Winter Mathematical Festival Varna '2001 Informatics Tournament
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1080
// Memory Limit: 64 MB
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

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> AL(n);
    for (int i = 0; i < n; i++) {
    	while (true) {
    		int x; cin >> x;
    		if (!x) break;
    		x--;
    		AL[i].pb(x);
    		AL[x].pb(i);
    	}
    }
    
    vector<int> color(n, -1);
    bool poss = true;
    
    for (int i = 0; i < n; i++) {
    	if (color[i] != -1) continue;
    	
    	queue<int> q;
    	q.push(i);
    	color[i] = 0;
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		
    		for (auto& v : AL[u]) {
    			if (color[v] != -1) {
    				if (color[v] == color[u]) poss = false;
    				continue;
    			}
    			
    			color[v] = 1 - color[u];
    			q.push(v);
    		}
    	}
    }
    
    if (!poss) {
    	cout << -1 << ln;
    	return;
    }
    
    for (int i = 0; i < n; i++) {
    	cout << color[i];
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
