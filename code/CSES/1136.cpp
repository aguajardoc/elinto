// Problem: Counting Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1136

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

struct Segtree {
    int n;
    vector<int> lazy;
    vector<int> res;
    
    Segtree() {}
    Segtree(int _n) : n(_n), lazy(4 * _n, 0), res(_n, 0) {}
    
    inline void push(int p) {
        if (!lazy[p]) return;
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }
    
    void update(int p, int l, int r, int i, int j) {
        if (l > j || r < i) return;
        if (l >= i && r <= j) {
            lazy[p]++;
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        update(2 * p, l, m, i, j);
        update(2 * p + 1, m + 1, r, i, j);
    }
    
    void pushAll(int p, int l, int r) {
        if (l == r) {
            res[l] = lazy[p];
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        pushAll(2 * p, l, m);
        pushAll(2 * p + 1, m + 1, r);
    }
    
    // Updates half-open interval [i, j)
    void update(int i, int j) {
        if (i >= j) return;
        update(1, 0, n - 1, i, j - 1);
    }
    
    void clean() {
        pushAll(1, 0, n - 1);
    }
    
    int query(int i) {
        return res[i];
    }
};

/**
 * Author: Benjamin Qi, Oleksandr Kulkov, Kaeser et al.
 * Source: https://github.com/kactl/kactl/blob/main/content/graph/HLD.h
 * Description: Heavy-Light Decomposition. Values can be on nodes or edges.
 * Time: O((N + Q) \log N)
 */
template <bool VALUES_ON_EDGES = false>
struct HLD {
    int N, tim = 0;
    vector<vector<int>> adj;
    vector<int> par, siz, depth, rt, pos;
    Segtree tree;

    HLD(vector<vector<int>> adj_)
        : N(adj_.size()), adj(move(adj_)), par(N, -1), siz(N, 1),
          depth(N), rt(N), pos(N), tree(N) {
        dfsSz(0);
        dfsHld(0);
    }

    void dfsSz(int v) {
        if (par[v] != -1) adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));
        for (auto& u : adj[v]) {
            par[u] = v;
            depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }

    void dfsHld(int v) {
        pos[v] = tim++;
        for (auto& u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }

    template <class B>
    void processPath(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALUES_ON_EDGES, pos[v] + 1);
    }

    void update_path(int u, int v) {
        processPath(u, v, [this](int l, int r) {
            tree.update(l, r);
        });
    }

    int query_node(int u) {
        return tree.query(pos[u]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    HLD<false> h(adj);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        h.update_path(a, b);
    }
    
    h.tree.clean();
    
    for (int i = 0; i < n; i++) {
        cout << h.query_node(i) << (i + 1 == n ? "" : " ");
    }
    cout << ln;
}

signed main() {
    fast_cin();
    solve();
    return 0;
}