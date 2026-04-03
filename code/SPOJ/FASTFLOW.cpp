// Problem: Fast Maximum Flow
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/FASTFLOW/
// Memory Limit: 1536 MB
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

struct Dinic {
	struct Edge {
		int v, flow, cap;
	};
	
	int n;
	vector<Edge> EL;
	vector<vector<int>> AL;
	vector<int> dist, cur;
	
	Dinic (int _n) {
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
				if (dist[e.v] != INF) continue;
				if (e.flow == e.cap) continue;
				
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
		
		while (bfs(s, t)) {
			cur.assign(n, 0);
			
			while (true) {
				int pushed = dfs(s, t, INF);
				
				if (!pushed) break;
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    Dinic d(n);
    
    for (int i = 0; i < m; i++) {
    	int u, v, cap;
    	cin >> u >> v >> cap;
    	u--, v--;
    	d.add_edge(u, v, cap);
    	d.add_edge(v, u, cap);
    }
    
    cout << d.max_flow(0, n - 1) << ln;
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
