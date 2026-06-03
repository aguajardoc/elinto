// Problem: Range Updates and Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1735
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

// hierarchy
// 1 -> 2 implies just 2
// 2 -> 1 implies 2 first then 1
// 1 -> 1 implies both
// 2 -> 2 implies the second 2

struct Segtree{
    vector<int> st, lazy1, lazy2;
    int n;
    
    Segtree(int _n) {
        n = _n;
        int x = 1;
        while (x < n) x <<= 1;
        st.assign(2*x, 0);
        lazy1.assign(2*x, 0);
        lazy2.assign(2*x, 0);
    }
    
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        // first do set if exists
        if (lazy2[p]) {
            lazy1[2*p] = 0;
            lazy1[2*p+1] = 0;
            lazy2[2*p] = lazy2[p];
            lazy2[2*p+1] = lazy2[p];
            
            st[2*p] = (m - l + 1) * lazy2[p];
            st[2*p+1] = (r - m) * lazy2[p];
            
            lazy2[p] = 0;
        }
        
        lazy1[2*p] += lazy1[p];
        lazy1[2*p+1] += lazy1[p];
        
        st[2*p] += (m - l + 1) * lazy1[p];
        st[2*p+1] += (r - m) * lazy1[p];
        
        lazy1[p] = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v, int type) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            if (type == 1) {
                st[p] += (r - l + 1) * v;
                lazy1[p] += v;
            }
            else if (type == 2) {
                st[p] = (r - l + 1) * v;
                lazy1[p] = 0;
                lazy2[p] = v;
            }
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        
        update(2*p, l, m, i, j, v, type);
        update(2*p+1, m+1, r, i, j, v, type);
        
        st[p] = st[2*p] + st[2*p+1];
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p];
        }
        
        push(p, l, r);
        int m = (l + r) / 2;
        
        int res = query(2*p, l, m, i, j);
        res += query(2*p+1, m+1, r, i, j);
        
        return res;
    }
    
    void update(int i, int j, int v, int type) {
        update(1, 0, n - 1, i, j, v, type);
    }
    
    int query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Segtree st(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.update(i, i, x, 2);
    }
    
    for (int i = 0; i < m; i++) {
        int type; cin >> type;
        if (type != 3) {
            int a, b, x;
            cin >> a >> b >> x;
            a--, b--;
            
            st.update(a, b, x, type);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            
            cout << st.query(a, b) << ln;
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
