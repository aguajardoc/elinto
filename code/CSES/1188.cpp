// Problem: Bit Inversions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1188
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

const ll INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Node {
    int S, PL, PR, sub;
    Node() {
        S = -INF, PL = -INF, PR = -INF, sub = -INF;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int n) {
        this->n = n;
        st.assign(4*n, Node());
    }
    
    Node merge(Node& L, Node& R) {
        Node M;
        M.sub = max({L.sub, R.sub, L.PR + R.PL});
        M.S = L.S + R.S;
        M.PL = max(L.PL, L.S + R.PL);
        M.PR = max(R.PR, R.S + L.PR);
        
        return M;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].S = v;
            st[p].PL = v;
            st[p].PR = v;
            st[p].sub = v;
            return;
        }
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);
        
        st[p] = merge(st[2*p], st[2*p+1]);
    }
    
    Node query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return Node();
        if (l >= i and r <= j) return st[p];
        
        int m = (l + r) / 2;
        Node L = query(2*p, l, m, i, j);
        Node R = query(2*p+1, m + 1, r, i, j);
        
        return merge(L, R);
    }
    
    void update(int i, int x) {
        update(1, 0, n - 1, i, i, x);
    }
    
    int query() {
        return query(1, 0, n - 1, 0, n - 1).sub;
    }
    
    int query(int x) {
        return query(1, 0, n - 1, x, x).sub;
    }
};

void solve() {
    string s; cin >> s;
    int n = s.length();
    Segtree st0(n + 1);
    Segtree st1(n + 1);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            st0.update(i, 1);
            st1.update(i, -INF);
        }
        else {
            st1.update(i, 1);
            st0.update(i, -INF);
        }
    }
    
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        x--;
        int cur = (s[x] - '0');
        s[x] = (1 - cur) + '0';
        
        if (cur == 0) {
            st0.update(x, -INF);
            st1.update(x, 1);
        }
        else {
            st0.update(x, 1);
            st1.update(x, -INF);
        }
        
        cout << max(st0.query(), st1.query()) << " ";
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
