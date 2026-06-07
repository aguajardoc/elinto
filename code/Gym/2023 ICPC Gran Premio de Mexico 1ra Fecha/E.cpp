// Problem: E. Employees Bonus
// Contest: Codeforces - 2023 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/696886/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct Segtree {
    vector<int> st;
    int TREE_SIZE = 1;
    int n;
    
    Segtree() {}
    
    Segtree(int _n) {
        while (TREE_SIZE < _n) TREE_SIZE <<= 1;
        st.assign(2*TREE_SIZE, 0);
        n = TREE_SIZE;
    }
    
    void update(int i, int x) {
        i += TREE_SIZE;
        st[i] += x;
        i >>= 1;
        
        while(i) {
            st[i] = st[2*i] + st[2*i+1];
            i >>= 1;
        }
    }
    
    int query_num(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p];
        
        int m = (l + r) / 2;
        
        return (
            query_num(2*p, l, m, i, j) + 
            query_num(2*p+1, m + 1, r, i, j)
        );
    }
    
    int query(int p, int l, int r, int k) {
        if (l == r) return l;
        
        int m = (l + r) / 2;
        int left = st[2*p];
        
        if (left < k) {
            return query(2*p+1, m + 1, r, k - left);
        }
        return query(2*p, l, m, k);
    }
    
    int query(int k) {
        return query(1, 0, n - 1, k);
    }
    
    int query_num(int i, int j) {
        return query_num(1, 0, n - 1, i, j);
    }
};

int bonus[100001], success[100001], in_subtree[100001];
vector<vector<int>> AL;
vector<vector<pair<int, int>>> bonus_u, bonus_rem;
Segtree st;


void check_tree() {
    for (int i = 0; i <= 10; i++) {
        cout << st.query_num(i, i) << " ";
    }
    cout << ln;
}

void dfs(int u, int p) {
    // Remove all remainders of parent
    for (auto& [b, i] : bonus_rem[p]) {
        st.update(i, -b);
    }
    
    // Add my bonuses
    for (auto& [b, i] : bonus_u[u]) {
        st.update(i, b);
    }
    
    // Debug
    // dbg(u);
    // check_tree();
    
    // Walk the tree
    int x = st.query(success[u]);
    if (st.query_num(0, x) < success[u]) bonus[u] = -1;
    else bonus[u] = x;
    
    // Go to children
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        dfs(v, u);
    }
    
    // Remove my bonuses
    for (auto& [b, i] : bonus_u[u]) {
        st.update(i, -b);
    }
    
    // Add all remainders of parent
    for (auto& [b, i] : bonus_rem[p]) {
        st.update(i, b);
    }
}

void dfs_subtree(int u, int p) {
    in_subtree[u]++;
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        dfs_subtree(v, u);
        in_subtree[u] += in_subtree[v];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> success[i];
    }
    
    fill_n(&bonus[0], 100001, -1);
    
    AL.assign(n + 1, vector<int>());
    bonus_u.assign(n + 1, vector<pair<int, int>>());
    bonus_rem.assign(n + 1, vector<pair<int, int>>());
    vector<int> root(n + 1, 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        AL[u].pb(v);
        root[v] = false;
    }
    
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (root[i]) r = i;
    }
    
    // find in subtree
    dfs_subtree(r, 0);
    
    for (int i = 0; i < q; i++) {
        int x, b;
        cin >> x >> b;
        
        int div = in_subtree[x];
        
        int full = b / div;
        int rem = b % div;
        
        // head adds all
        bonus_u[x].pb({full + rem, i + 1});
        // remainder is just remainder
        bonus_rem[x].pb({rem, i + 1});
    }
    
    st = Segtree(q + 1);
    dfs(r, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << bonus[i] << ln;
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
