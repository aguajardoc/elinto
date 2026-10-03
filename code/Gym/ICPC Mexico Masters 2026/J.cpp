// Problem: J. Building the Schedule
// Contest: Codeforces - ICPC Masters Mexico 2026
// URL: https://codeforces.com/gym/106646/problem/J
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

// const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

// Usage: Dinic d(N) -> d.max_flow(source, sink)

const long long INF = 2e18;
vector<pair<int, int>> conns;
int n,m;

struct Dinic {
	struct Edge {
		int v; long long flow, cap;
	};
	
	int n;
	vector<Edge> EL;
	map<pair<int, int>, int> EL_idx;
	vector<vector<int>> AL;
	vector<int> cur, dist;
	
	Dinic (int _n) {
		n = _n;
		AL.assign(n, vector<int>());
		cur.assign(n, 0);
		dist.assign(n, -1);
	}
	
	void add_edge(int u, int v, long long cap) {
		AL[u].push_back(EL.size());
		EL_idx[{u, v}] = EL.size();
		EL.push_back({v, 0, cap});
		
		AL[v].push_back(EL.size());
		EL_idx[{v, u}] = EL.size();
		EL.push_back({u, 0, 0});
	}
	
	bool bfs(int s, int t) {
		queue<int> q;
		q.push(s);
		
		dist.assign(n, -1);
		dist[s] = 0;
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (auto& idx : AL[u]) {
				Edge& e = EL[idx];
				if (dist[e.v] != -1) continue;
				if (e.cap == e.flow) continue;
				
				dist[e.v] = dist[u] + 1;
				q.push(e.v);
			}
		}
		
		return (dist[t] != -1);
	}
	
	long long dfs(int u, int t, long long flow) {
		if (u == t or !flow) return flow;
		
		for (int& i = cur[u]; i < AL[u].size(); i++) {
			int idx = AL[u][i];
			Edge& e = EL[idx];
			
			if (dist[e.v] != dist[u] + 1) continue;
			if (e.cap == e.flow) continue;
			
			long long max_delta = e.cap - e.flow;
			long long mid_delta = min(flow, max_delta);
			long long real_delta = dfs(e.v, t, mid_delta);
			
			if (real_delta) {
			    // Any real connection between
			    // any u in the range [2*m, 2*m + n - 1]
			    // and a v in range [0, m - 1] is goated
			    // simplifies to just v so add that edge
			    // maybe not lol
			    // if (e.v < m) {
			        // conns.pb({u - 2 * m + 1, e.v + 1});
			    // }
				e.flow += real_delta;
				EL[idx^1].flow -= real_delta;
				return real_delta;
			}
		}
		
		return 0;
	}
	
	long long max_flow(int s, int t) {
		long long flow = 0;
		
		while (bfs(s, t)) {
			cur.assign(n, 0);
			
			while (true) {
			    // dbg(1);
				long long pushed = dfs(s, t, INF);
				
				if (!pushed) break;
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};

void solve() {
    cin >> n >> m;
    int source = n + 2 * m;
    int sink = source + 1;
    int sof = 0;
    Dinic d(sink + 1);
    
    // Shifts connect from dummy to the shift
    // Then shift to sink with inf
    for (int i = 0; i < m; i++) {
        int l, u;
        cin >> l >> u;
        sof += l;
        d.add_edge(i, i + m, l);
        d.add_edge(i + m, sink, INF);
    }
    
    // People connect to dummies 
    // Source connects to people with ci
    vector<pair<int, int>> shifts;
    for (int i = 0; i < n; i++) {
        int c, q;
        cin >> c >> q;
        d.add_edge(source, i + 2 * m, c);
        for (int j = 0; j < q; j++) {
            int x; cin >> x; x--;
            shifts.pb({i, x});
            d.add_edge(i + 2 * m, x, 1);
        }
    }
    
    int flow = d.max_flow(source, sink);
    if (flow != sof) {
        cout << -1 << ln;
        return;
    }
    
    for (auto& [p, j] : shifts) {
        int x = d.EL[d.EL_idx[{p + 2 * m, j}]].flow;
        if (x) conns.pb({p + 1, j + 1});
    }
    
    cout << conns.size() << ln;
    for (auto& [x, y] : conns) {
        cout << x << " " << y << ln;
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
