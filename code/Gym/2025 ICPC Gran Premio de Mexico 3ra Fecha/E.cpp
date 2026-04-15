// Problem: E. El Juego del Calamar
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 3ra Fecha
// URL: https://codeforces.com/gym/106063/problem/E
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
// #define int ll
// #define int uint32_t
#define ld long double
#define pb push_back

const ll INF = INT32_MAX;
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
			while (true) {
				int pushed = dfs(s, t, 2e9);
				
				if (!pushed) break;
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    
    // Add edges by level
    int source = 2*n * k, sink = source + 1;
    
    vector<vector<int>> levels(n);
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < k; j++) {
    		int x;
    		cin >> x;
    		levels[i].pb(x);
    	}
    }
    
    // Do in backwards order
    // DO all, then remove each level 
    // and reattaching sink connections
    vector<vector<pair<int, int>>> conns(n+1);
    for (int i = 0; i < m; i++) {
    	int f, u, v;
    	cin >> f >> u >> v;
    	f--, u--, v--;
    	conns[f].pb({u, v});
    }
    
    // all
    Dinic d(2*n * k + 2);
    
    // source to level 0
    for (int i = 0; i < k; i++) {
    	d.add_edge(source, i, levels[0][i]);
    }
    
    // level n-1 to sink
    for (int i = 0; i < k; i++) {
    	d.add_edge((n - 1) * k + i, sink, INF);
    }
    
    // Create edge nodes
    for (int i = 0; i < n-1; i++) {
    	for (int j = 0; j < k; j++) {
    		int k1 = n*k + (i)*k + j;
    		int k2 = (i+1)*k + j;
    		d.add_edge(k1, k2, levels[i+1][j]);
    	}
    }
    
    // all others
    // do from u to edge node with inf
    for (int i = 0; i < n; i++) {
    	for (auto& [u, v] : conns[i]) {
    		int k1 = i * k + u;
    		int k2 = n*k + (i) * k + v;
    		d.add_edge(k1, k2, INF);
    	}
    }
    
    vector<int> ans;
    int res = 0;
    
    for (int i = n - 1; i > 0; i--) {
    	// get flow
    	res += d.max_flow(source, sink);
    	ans.pb(res);
    	
    	// attach previous level to sink
    	for (int j = 0; j < k; j++) {
    		d.add_edge((i - 1) * k + j, sink, INF);
    	}
    }
    res += d.max_flow(source, sink);
    ans.pb(res);
    
    reverse(ans.begin(), ans.end());
    for (auto& i : ans) {
    	cout << i << " ";
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
