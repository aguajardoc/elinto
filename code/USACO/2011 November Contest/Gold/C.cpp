// Problem: Problem 3. Cow Steeplechase
// Contest: USACO - USACO 2011 November Contest, Gold Division
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=93
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

struct Dinic {
	struct Edge {
		int v, flow, cap;
	};
	
	int n;
	vector<Edge> EL;
	vector<vector<int>> AL;
	vector<int> dist, cur;
	
	Dinic(int _n) {
		n = _n;
		AL.assign(n, vector<int>());
		dist.assign(n, INF);
		cur.assign(n, 0);
	}
	
	void add_edge(int u, int v, int cap) {
		AL[u].pb(EL.size());
		EL.pb({v, 0, cap});
		
		AL[v].pb(EL.size());
		EL.pb({u, 0, 0});
	}
	
	bool bfs(int s, int t) {
		queue<int> q;
		q.push(s);
		
		dist.assign(n, INF);
		dist[s] = 0;
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (auto& idx : AL[u]) {
				Edge& e = EL[idx];
				if (e.flow == e.cap) continue;
				if (dist[e.v] != INF) continue;
				
				dist[e.v] = dist[u] + 1;
				q.push(e.v);
			}
		}
		
		return (dist[t] != INF);
	}
	
	int dfs(int u, int t, int flow) {
		if (u == t or !flow) return flow;
		
		for (int& i = cur[u]; i < AL[u].size(); i++) {
			int idx = AL[u][i];
			Edge& e = EL[idx];
			
			if (dist[e.v] != dist[u] + 1) continue;
			if (e.flow == e.cap) continue;
			
			int max_delta = e.cap - e.flow;
			int mid_delta = min(flow, max_delta);
			int real_delta = dfs(e.v, t, mid_delta);
			
			if (real_delta) {
				e.flow += real_delta;
				
				EL[idx^1].flow -= real_delta;
				
				return real_delta;
			}
		}
		
		return 0;
	}
	
	int max_flow(int s, int t) {
		int flow = 0;
		
		while(bfs(s, t)) {
			cur.assign(n, 0);
			while(true) {
				int pushed = dfs(s, t, INF);
				if (!pushed) break;
				flow += pushed;
			}
		}
		
		return flow;
	}
};

struct Line {
	int x1, y1, x2, y2;
};

pair<int, int> intersect(Line& a, Line& b) {
	pair<int, int> poss = {a.x1, b.y1};
	
	if (b.x1 <= a.x1 and b.x2 >= a.x1 and
		a.y1 <= b.y1 and a.y2 >= b.y2
	) return poss;
	
	return {-1, -1};
}

void solve() {
	int n;
	cin >> n;
	vector<Line> horizontal, vertical;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (x1 == x2) {
			horizontal.pb({x1, y1, x2, y2});
		}
		else {
			vertical.pb({x1, y1, x2, y2});
		}
	}
	
	Dinic d(n + 2);
	int source = n;
	int sink = source + 1;
	
	// Source to rows and cols to sink
	for (int i = 0; i < horizontal.size(); i++) {
		d.add_edge(source, i, 1);
	}
	for (int i = 0; i < vertical.size(); i++) {
		d.add_edge(i + (int)horizontal.size(), sink, 1);
	}
	
	for (int i = 0; i < horizontal.size(); i++) {
		for (int j = 0; j < vertical.size(); j++) {
			pair<int, int> POI = intersect(horizontal[i], vertical[j]);
			if (POI.first == -1) continue;
			
			d.add_edge(i, (int)horizontal.size() + j, INF);
		}
	}
	
	cout << n - d.max_flow(source, sink) << ln;
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
