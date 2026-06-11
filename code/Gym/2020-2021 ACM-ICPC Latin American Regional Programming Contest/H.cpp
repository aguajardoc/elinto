// Problem: H. Halting Wolf
// Contest: Codeforces - 2020-2021 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103185/problem/H
// Memory Limit: 1024 MB
// Time Limit: 250 ms
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

// Usage: Dinic d(N) -> d.max_flow(source, sink)

// const long long INF = 2e18;

struct Dinic {
	struct Edge {
		int v; long long flow, cap;
	};
	
	int n;
	vector<Edge> EL;
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
		EL.push_back({v, 0, cap});
		
		AL[v].push_back(EL.size());
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
				long long pushed = dfs(s, t, INF);
				
				if (!pushed) break;
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};

void solve() {
    int n;
    cin >> n;
    Dinic d(n + 1);
    int source = 0, sink = n;
    
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        if (k == "*") {
            int L;
            cin >> L;
            L--;
            if (L == 0) L = n;
            d.add_edge(i, L, INF);
        }
        else {
            int K = stoi(k);
            for (int j = 0; j < K; j++) {
                int L;
                cin >> L;
                L--;
                if (L == 0) L = n;
                
                d.add_edge(i, L, 1);
            }
        }
    }
    
    int ans = d.max_flow(source, sink) + 1;
    
    if (ans > 10001) {
        cout << '*' << ln;
    }
    else cout << ans << ln;
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
