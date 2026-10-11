// Problem: K. Kiere Volar
// Contest: Codeforces - 2026 XVIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106722/problem/K
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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

vector<int> a,d;


struct SegtreeGCD {
    const int TREE_SIZE = 1 << 20;
    vector<int> st;
    
    SegtreeGCD() {
        st.assign(2* TREE_SIZE, 0);
    }
    
    void update(int i, int x) {
        i += TREE_SIZE;
        st[i] = x;
        i >>= 1;
        
        while(i) {
            st[i] = gcd(st[2*i], st[2*i+1]);
            i >>= 1;
        }
    }
    
    int query(int l, int r) {
        int res = 0;
        l += TREE_SIZE;
        r += TREE_SIZE;
        
        while (l <= r) {
            if (l&1) res = gcd(res, st[l++]);
            if (!(r&1)) res = gcd(res, st[r--]);
            
            l >>= 1;
            r >>= 1;
        }
        
        return res;
    }
};


struct Node {
    int v, lazy;
    Node() {
        v = 0, lazy = 0;
    }
};

struct SegtreeSum {
    vector<Node> st;
    int n;
    
    SegtreeSum (int n) {
        this->n = n;
        st.assign(4*n, Node());
    }  
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        int m = (l + r) / 2;
        st[2*p].v += (m  - l + 1) * st[p].lazy;
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
        
        push(p,l,r);
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p + 1, m + 1, r, i, j, v);
        
        st[p].v = st[2*p].v + st[2*p+1].v;
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p].v;
        push(p, l, r);
        
        int m = (l + r) / 2;
        return (
            query(2*p, l, m, i, j) + 
            query(2*p+1, m + 1, r, i, j)
        );
    }
    
    void update(int l, int r, int v) {
        update(1, 0, n - 1, l, r, v);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l , r);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    a.resize(n + 1); d.resize(n + 1);
    SegtreeSum st_s(n+2);
    SegtreeGCD st_g;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i-1];
        st_s.update(i, i, a[i]);
        st_g.update(i, abs(d[i]));
    }
    
    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, x; cin >> l >> r >> x;
            st_s.update(l, r, x);
            st_g.update(l, abs(st_s.query(l, l) - st_s.query(l-1, l-1)));
            st_g.update(r+1, abs(st_s.query(r+1, r+1) - st_s.query(r, r)));
        }
        else {
            int l, r; cin >> l >> r;
            int ans = st_s.query(l, l);
            ans = gcd(ans, st_g.query(l + 1, r));
            
            cout << ans << ln;
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
