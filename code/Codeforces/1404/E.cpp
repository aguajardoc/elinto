// Problem: E. Bricks
// Contest: Codeforces - Codeforces Round 668 (Div. 1)
// URL: https://codeforces.com/contest/1404/problem/E
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
	vector<int> cur, dist;
	
	Dinic(int _n) {
		n = _n;
		AL.assign(n, vector<int>());
		cur.assign(n, 0);
		dist.assign(n, INF);
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
				if (dist[e.v] != INF or e.flow == e.cap) continue;
				
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
			if (e.cap == e.flow) continue;
			
			int max_delta = e.cap - e.flow;
			int mid_delta = min(max_delta, flow);
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

bool intersects(vector<int> a, vector<int> b) {
	int hx = a[0];
	int hy = a[1];
	int vy = b[0];
	int vx = b[1];
	
	if (hx == vx or hx == vx + 1) {
		if (hy == vy or hy + 1 == vy) return true;
	}
	
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<string> mat(n);
	for (auto& i : mat) cin >> i;
	
	vector<vector<pair<int, int>>> hor(n, vector<pair<int, int>>(m, make_pair(-1, -1))), vert = hor;
	int B = 0, H = 0, V = 0;
	for (int i = 0; i < n; i++) {
		B += count(mat[i].begin(), mat[i].end(), '#');
		for (int j = 1; j < m; j++) {
			if (mat[i][j-1] == '#' and
				mat[i][j]   == '#'
			) {
				if (hor[i][j-1].first == -1) {
					hor[i][j-1].first = H;
				}
				else hor[i][j-1].second = H;
				
				hor[i][j].first = H++;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (mat[j-1][i] == '#' and
				mat[j][i]   == '#'
			) {
				if (vert[j-1][i].first == -1) {
					vert[j-1][i].first = V;
				}
				else vert[j-1][i].second = V;
				
				vert[j][i].first = V++;
			}
		}
	}
	
	Dinic d(H + V + 2);
	int source = H + V;
	int sink = source + 1;
	
	// Source to hor
	for (int i = 0; i < H; i++) {
		d.add_edge(source, i, 1);
	}
	
	// Vert to sink
	for (int j = 0; j < V; j++) {
		d.add_edge(j + H, sink, 1);
	}
	
	// Interconnects
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int h1 = hor[i][j].first;
			int h2 = hor[i][j].second;
			int v1 = vert[i][j].first;
			int v2 = vert[i][j].second;
			
			if (h1 != -1 and v1 != -1) {
				d.add_edge(h1, H + v1, INF);
			}
			if (h1 != -1 and v2 != -1) {
				d.add_edge(h1, H + v2, INF);
			}
			if (h2 != -1 and v1 != -1) {
				d.add_edge(h2, H + v1, INF);
			}
			if (h2 != -1 and v2 != -1) {
				d.add_edge(h2, H + v2, INF);
			}
		}
	}
	
	int F = d.max_flow(source, sink);
	
	cout << B - (H + V - F) << ln;
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
