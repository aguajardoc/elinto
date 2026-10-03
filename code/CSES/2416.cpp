// Problem: Increasing Array Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2416
// Memory Limit: 512 MB
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Node {
    int val, lazy;
    Node() {
        val = 0, lazy = 0;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree (int _n) {
        n = _n;
        int t = 1; while (t < n) t <<= 1;
        st.assign(2 * t, Node());
    }
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        
        int m = (l + r) >> 1;
        st[2*p].val += (m - l + 1) * st[p].lazy;
        st[2*p+1].val += (r - m) * st[p].lazy;
        
        st[2*p].lazy += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].val += (r - l + 1) * v;
            st[p].lazy += v;
            return;
        }
        
        push(p, l, r);
        
        int m = (l + r) >> 1;
        update(2*p, l, m, i, j, v);
        update(2*p + 1, m + 1, r, i, j, v);
        
        st[p].val = st[2*p].val + st[2*p+1].val;
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p].val;
        }
        
        push(p, l, r);
        
        int m = (l + r) >> 1;
        return (
            query(2*p, l, m, i, j) + 
            query(2*p + 1, m + 1, r, i , j)
        );
    }
    
    void update(int i, int j, int v) {
        update(1, 0, n - 1, i, j, v);
    }
    
    int query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }
};

int find(Segtree& st, int i, int n) {
    int ans = INF;
    int l = i, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        
        int fm = st.query(l, m);
        if (fm) {
            ans = min(ans, m);
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    
    return ans;
}

struct Query {
    int l, r, idx;
    bool operator<(const auto& oth) const {
        return make_pair(l, r) < make_pair(oth.l, oth.r);
    }
};

void dfs(Segtree& st, int u, vector<int>& active, vector<int>& AL, vector<int>& a) {
    if (active[u]) return;
    active[u] = 1;
    int nxt;
    if (AL[u] != -1) {
        nxt = AL[u];
        dfs(st, AL[u], active, AL, a);
    }
    else nxt = a.size();
        
    // Update from here to before by diff
    int old = st.query(u, u) + a[u];
    int nv = a[u];
    
    // dbg(old, nv);
    
    st.update(u, nxt - 1, nv - old);
}

void print(Segtree& st, int n) {
    for (int i = 0; i < n; i++) {
        cout << st.query(i, i) << " ";
    }
    cout << ln;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n); for (auto& i : a) cin >> i;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = {a[i], i};
    }
    sort(b.rbegin(), b.rend());
    vector<int> AL(n, -1);
    stack<pair<int, int>> pre_st;
    
    for (int i = 0; i < n; i++) {
        while (!pre_st.empty() and pre_st.top().first < a[i]) {
            AL[pre_st.top().second] = i;
            pre_st.pop();
        }
        pre_st.push({a[i], i});
    }
    
    Segtree st(n);
    
    // Precond
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        st.update(i, i, mx - a[i]);
        // print(st, n);
    }
    
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r; 
        queries[i].idx = i;
        queries[i].l--;
        queries[i].r--;
    }
    sort(queries.begin(), queries.end());
    
    vector<int> active(n, 0);
    
    dfs(st, 0, active, AL, a);
    
    vector<int> ans(q);
    int idx = 0;
    // Iterate over n and process the queries at that start
    for (int i = 0; i < n; i++) {
        // Is this one active?
        if (!active[i]) {
            // no? use dfs to change
            dfs(st, i, active, AL, a);
        }
        
        // dbg(i);
        // print(st, n);
        
        // dbg(idx, queries[idx].l);
        while (idx < q and queries[idx].l == i) {
            // dbg(idx);
            ans[queries[idx].idx] = st.query(queries[idx].l, queries[idx].r);
            idx++;
        }
    }
    
    for (auto& i : ans) {
        cout << i << ln;
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
