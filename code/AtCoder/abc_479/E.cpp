// Problem: E - Cut and Add
// Contest: AtCoder - AtCoder Beginner Contest 479
// URL: https://atcoder.jp/contests/abc479/tasks/abc479_e
// Memory Limit: 1024 MB
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
const int N = 2e5 + 67;

struct Edge {
    int u, v;
};

int dist[N], tin[N], tout[N], subtree[N];
Edge EL[N];
vector<int> AL[N];
int timer = 0;

int dfs_subtree(int u, int p=-1) {
    tin[u] = timer++;
    subtree[u] = 1;
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        dist[v] = dist[u] + 1;
        subtree[u] += dfs_subtree(v, u);
    }
    
    tout[u] = timer - 1;
    return subtree[u];
}

struct Node {
    int v, lazy;
    Node() {
        v = 0, lazy = 0;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int n) {
        this->n = n;
        st.assign(4*n, Node());
    }  
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        
        int m = (l + r) / 2;
        st[2*p].v += (m - l + 1) * st[p].lazy;
        st[2*p+1].v += (r - m) * st[p].lazy;
        
        st[2*p].lazy += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].v += (r - l + 1) * v;
            st[p].lazy += v;
            return;
        }
        push(p, l, r);
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);
        
        st[p].v = st[2*p].v + st[2*p+1].v;
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p].v;
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        return (
            query(2*p, l, m, i, j) +
            query(2*p + 1, m + 1, r, i, j)
        );
    }
    
    void update(int i, int j, int v) {
        update(1, 0, n - 1, i, j, v);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void print(Segtree& st, int n) {
    for (int i = 0; i < n; i++) {
        cout << st.query(tin[i], tin[i]) << " ";
    }
    cout << ln;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        AL[u].pb(v);
        AL[v].pb(u);
        EL[i] = {u, v};
    }
    
    dist[0] = 0;
    dfs_subtree(0);
    Segtree st(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u = EL[i].u;
        int v = EL[i].v;
        int depth_u = dist[u];
        int depth_v = dist[v];
        
        if (depth_u > depth_v) {
            swap(u, v);
        }
        
        // v is lower always
        int root_subtree = subtree[0] - subtree[v];
        int v_subtree = subtree[v];
        
        // dbg(root_subtree);
        // dbg(v_subtree);
        
        if (root_subtree > v_subtree) {
            st.update(tin[0], tout[0], i + 1);
            st.update(tin[v], tout[v], -(i + 1));
        }
        else {
            st.update(tin[v], tout[v], i + 1);
        }
        
        // print(st, n);
    }
    
    print(st, n);
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
