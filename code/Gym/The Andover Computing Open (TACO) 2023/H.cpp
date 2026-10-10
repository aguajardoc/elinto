// Problem: H. 01 (Hard Version)
// Contest: Codeforces - The Andover Computing Open (TACO) 2023
// URL: https://codeforces.com/gym/104380/problem/H
// Memory Limit: 256 MB
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
    int bal, UM0, UM1;
    Node() {
        bal = 0, UM0 = 0, UM1 = 0;
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
        int NM = min(L.UM0, R.UM1);
        
        M.bal = L.bal + R.bal + NM;
        M.UM0 = L.UM0 - NM + R.UM0;
        M.UM1 = L.UM1 + R.UM1 - NM;
        
        return M;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].bal = 0;
            st[p].UM0 = (v == 0);
            st[p].UM1 = (v == 1);
            
            return;
        }
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p + 1, m + 1, r, i, j, v);
        
        st[p] = merge(st[2*p], st[2*p+1]);
    }
    
    Node query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return Node();
        if (l >= i and r <= j) return st[p];
        
        int m = (l + r) / 2;
        Node L = query(2*p, l, m, i, j);
        Node R = query(2*p + 1, m + 1, r, i, j);
        
        return merge(L, R);
    }
    
    void update(int i, int x) {
        update(1, 0, n - 1, i, i, x);
    }
    
    int query(int l, int r) {
        return (r - l + 1) - 2*query(1, 0, n - 1, l, r).bal;
    }
};

void solve() {
    string s; cin >> s; int n = s.length();
    Segtree st(n);
    
    for (int i = 0; i < n; i++) {
        st.update(i, s[i] - '0');
    }
    
    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        
        if (type == 1) {
            int x; cin >> x;
            x--;
            
            int cur = s[x] - '0';
            
            st.update(x, 1 - cur);
            s[x] = (1 - cur) + '0';
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << st.query(l, r) << ln;
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
