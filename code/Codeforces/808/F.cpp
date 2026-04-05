// Problem: F. Card Game
// Contest: Codeforces - Educational Codeforces Round 21
// URL: https://codeforces.com/contest/808/problem/F
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

struct Item {
	int p, c, l;
};

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
			while(true) {
				int pushed = dfs(s, t, INF);
				
				if (!pushed) break;
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};

vector<Item> a;
vector<int> p;
bitset<1000001> bs;
int k;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 1000000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000000; j+=i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}


bool f(int x) {
	vector<Item> evens, odds;
	Item ba;
	ba.p = 0;
	int SOP = 0;
	for (auto& i : a) {
		if (i.c == 1 and i.l <= x and i.p > ba.p) {
			ba = i;
		}
		else if (i.c != 1 and i.l <= x) {
			if (i.c % 2) odds.pb(i);
			else evens.pb(i);
			
			SOP += i.p;
		}
	}
	
	if (ba.p) {
		odds.pb(ba);
		SOP += ba.p;
	}
	
	int n = evens.size();
	int m = odds.size();
	Dinic d(n + m + 2);
	int source = n + m;
	int sink = source + 1;
	
	// Source to evens
	for (int i = 0; i < n; i++) {
		d.add_edge(source, i, evens[i].p);
	}
	
	// Evens to bad odds
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bs[evens[i].c + odds[j].c]) {
				d.add_edge(i, n + j, INF);
			}
		}
	}
	
	// Odds to sink
	for (int i = 0; i < m; i++) {
		d.add_edge(n + i, sink, odds[i].p);
	}
	
	return ((SOP - d.max_flow(source, sink)) >= k);
}

void solve() {
    int n;
    cin >> n >> k;
    
    a.assign(n, Item());
    for (int i = 0; i < n; i++) {
    	int p, c, l;
    	cin >> p >> c >> l;
    	a[i] = {p, c, l};
    }
    
    int l = 1, r = 101;
    int ans = INF;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	bool poss = f(m);
    	
    	if (poss) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else l = m + 1;
    }
    
    cout << (ans == INF ? -1:ans) << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
