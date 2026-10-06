// Problem: Range Queries and Copies
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1737
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
    int v, lc, rc;
    Node() {
        v = 0, lc = -1, rc = -1;
    }
};

struct Segtree {
    vector<Node> st;
    vector<int> roots;
    int n;
    
    Segtree(int _n) {
        n = _n;
        st.reserve(3e5 * log2(n));
        st.pb(Node());
        roots.pb(0);
    }
    
    int update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return p;
        
        int cur = st.size();
        if (p != -1) {
            st.pb(st[p]);
        }
        else st.pb(Node());
        
        if (l >= i and r <= j) {
            st[cur].v = v;
            return cur;
        }
        
        int m = (l + r) / 2;
        int old_lc = (p == -1) ? -1 : st[p].lc;
        int old_rc = (p == -1) ? -1 : st[p].rc;
        
        if (i <= m)
            st[cur].lc = update(old_lc, l, m, i, j, v);
        else
            st[cur].rc = update(old_rc, m + 1, r, i, j, v);
        
        int ans = 0;
        if (st[cur].lc != -1) ans += st[st[cur].lc].v;
        if (st[cur].rc != -1) ans += st[st[cur].rc].v;
        
        st[cur].v = ans;
        
        return cur;
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p].v;
        
        int m = (l + r) / 2;
        
        int ans = 0;
        if (st[p].lc != -1) ans += query(st[p].lc, l, m, i, j);
        if (st[p].rc != -1) ans += query(st[p].rc, m + 1, r, i, j);
        
        return ans;
    }
    
    void update_same(int k, int i, int v) {
        roots[k] = update(roots[k], 0, n - 1, i, i, v);
    }
    
    void update_clone(int k, int i, int v) {
        int nr = update(roots[k], 0, n - 1, i, i, v);
        roots.pb(nr);
    }
    
    int query(int k, int i,int j) {
        return query(roots[k], 0, n - 1, i, j);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    Segtree st(n);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.update_same(0, i, x);
    }
    
    while (q--) {
        int type; cin >> type;
        
        if (type == 1) {
            int k, a, x; cin >> k >> a >> x; k--, a--;
            st.update_same(k, a, x);
        }
        else if (type == 2) {
            int k, a, b; cin >> k >> a >> b; k--, a--, b--;
            cout << st.query(k, a, b) << ln;
        }
        else {
            int k; cin >> k; k--;
            st.roots.pb(st.roots[k]);
        }
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
