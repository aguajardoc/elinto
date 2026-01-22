// Problem: D. An overnight dance in discotheque
// Contest: Codeforces - Codeforces Round 418 (Div. 2)
// URL: https://codeforces.com/contest/814/problem/D
// Memory Limit: 256 MB
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

struct Circle {
	int x, y, val;
};

int bfs(int start, vector<int>& visited, vector<vector<int>>& AL, vector<Circle>& a) {
	int res = 0;
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = 1;
	
	while (!q.empty()) {
		auto [u, depth] = q.front();
		q.pop();
		
		if (depth % 2) res -= a[u].val;
		else res += a[u].val;
		
		for (auto& v : AL[u]) {
			if (visited[v]) continue;
			
			visited[v] = true;
			q.push({v, depth + 1});
		} 
	}
	
	// dbg(start, res);
	
	return res;
}

void solve() {
    int n;
    cin >> n;
  	vector<Circle> a(n);
  	for (int i = 0; i < n; i++) {
  		int x, y, r;
  		cin >> x >> y >> r;
  		a[i].x = x;
  		a[i].y = y;
  		a[i].val = r*r;
  	} 
  	
  	// Make relation tree
  	vector<pair<int, int>> FAL(n, {INF, INF});
  	vector<vector<int>> AL(n);
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			if (i == j) continue;
  			
  			// If j inside of i, add to AL
  			// radius of i has to exceed dist btw i and j
  			int dsq = (a[i].x - a[j].x) * (a[i].x - a[j].x) + 
  					  (a[i].y - a[j].y) * (a[i].y - a[j].y);
  			
  			
  			if (a[i].val > dsq and a[i].val > a[j].val) {
  				// AL[i].pb(j);
  				// dbg(i, j);
  				// dbg(dsq, a[i].val);
  				FAL[j] = min(FAL[j], {a[i].val, i});
  			}
  		}
  	}
  	
  	vector<int> roots;
  	
  	for (int j = 0; j < n; j++) {
  		int i = FAL[j].second;
  		if (i != INF) {
  			AL[i].pb(j);
  			// dbg(i, j);
  		}
  		else {
  			roots.pb(j);
  			// dbg(j);
  		}
  	}
  	
  	int ans = 0;
  	vector<int> visited(n, 0);
  	vector<int> secroots;
  	
  	// Add all roots to answer, rem their conns to children
  	for (auto& i : roots) {
  		ans += a[i].val;
  		
  		for (auto& j : AL[i]) {
  			secroots.pb(j);
  		}
  		
  		AL[i].clear();
  		visited[i] = 1;
  	}
  	
  	// dbg(ans);
  	
  	// BFS over rest
  	for (auto& i : secroots) {
  		if (visited[i]) continue;
  		
  		ans += bfs(i, visited, AL, a);
  	}
  	
  	ld actualans = PI * ans;
  	
  	cout << fixed << setprecision(10) << actualans << ln;
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
