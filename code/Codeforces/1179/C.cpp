// Problem: C. Serge and Dining Room
// Contest: Codeforces - Codeforces Round 569 (Div. 1)
// URL: https://codeforces.com/contest/1179/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    int v, lazy;
    Node() {
        v = 0, lazy = 0;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int _n) {
        n = _n;
        st.assign(4 * n, Node());
    }
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        
        int m = (l + r) / 2;
        st[2*p].v += st[p].lazy;
        st[2*p+1].v += st[p].lazy;
        
        st[2*p].lazy += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].v += v;
            st[p].lazy += v;
            return;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);
        
        st[p].v = max(st[2*p].v, st[2*p+1].v);
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return -INF;
        if (l >= i and r <= j) {
            return st[p].v;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        return (max(
            query(2*p, l, m, i, j),
            query(2*p+1, m + 1, r, i, j)
        ));
    }
    
    void update(int l, int r, int v) {
        update(1, 0, n - 1, l, r, v);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int get_res(Segtree& st) {
    int l = 0, r = 1e6 + 1;
    int ans = -INF;
    while (l <= r) {
        int m = (l + r) / 2;
        int fm = st.query(m, 1e6 + 1);
        
        // dbg(m, fm);
        
        if (fm > 0) {
            ans = max(ans, m);
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    
    if (ans <= 0) {
        return -1;
    }
    return ans;
}

void print(Segtree& st) {
    for (int i = 0; i <= 11; i++) {
        cout << st.query(i, i) << " ";
    }
    cout << ln;
}

void solve() {
    // For every ai, add 1 to pos ai
    // For every bi, subtract 1 to pos bi    
    // Every change is -1 to current and +1 to new
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    Segtree st(1e6 + 47);
    for (auto& i : a) {
        cin >> i;
        st.update(0, i, 1);
        
        // print(st);
    }
    
    for (auto& i : b) {
        cin >> i;
        st.update(0, i, -1);
        // print(st);
    }
    
    
    int q; cin >> q;
    while(q--) {
        int type, i, x;
        cin >> type >> i >> x;
        i--;
        
        if (type == 1) {
            st.update(0, a[i], -1);
            a[i] = x;
            st.update(0, a[i], 1);
        }
        else {
            st.update(0, b[i], 1);
            b[i] = x;
            st.update(0, b[i], -1);
        }
        
        // print(st);
        
        cout << get_res(st) << ln;
    }
    
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> ;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
