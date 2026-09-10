// Problem: E. Network Editing
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/E
// Memory Limit: 1024 MB
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

// const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

// Usage: Dinic d(N) -> d.max_flow(source, sink)

struct Edge2 {
    int u, v;
};

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    
    return cost;
}

void input(vector<Edge2>& EL, int m) {
    for (int i = 0; i < m; i++) {
        cin >> EL[i].u >> EL[i].v;
        if (EL[i].v < EL[i].u) swap(EL[i].u, EL[i].v);
    }
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<Edge2> EL1(m1), EL2(m2);
    input(EL1, m1);
    input(EL2, m2);
    
    if (m1 != m2) {
        cout << -1 << ln;
        return;
    }
    
    int source = m1 + m2;
    int sink = source + 1;
    vector<Edge> mcf;
    
    for (int i = 0; i < m1; i++) {
        mcf.pb({source, i, 1, 0});
        mcf.pb({i + m1, sink, 1, 0});
    }
    
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m2; j++) {
            int matches = 0;
            if (EL1[i].u == EL2[j].u or
                EL1[i].u == EL2[j].v
            ) matches++;
            
            if (EL1[i].v == EL2[j].u or
                EL1[i].v == EL2[j].v
            ) matches++;
            
            int cost = 2 - matches;
            mcf.pb({i, m1 + j, 1, cost});
        }
    }
    
    int ans = min_cost_flow(sink + 1, mcf, 505, source, sink);
    
    cout << ans << ln;
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
