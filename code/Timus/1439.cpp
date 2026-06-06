// Problem: 1439. Battle with You-Know-Who
// Contest: Timus Online Judge - The Xth Urals Collegiate Programing Championship, March 24-25, 2006
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1439
// Memory Limit: 64 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Node {
    int lc = -1, rc = -1, v = 0;
    Node() {
        
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int _n) {
        n = _n;
        st.reserve(100000 * 31);
        st.pb(Node());
    }
    
    void extend(int p) {
        if (st[p].lc == -1) {
            st[p].lc = st.size();
            st.pb(Node());
        }
        if (st[p].rc == -1) {
            st[p].rc = st.size();
            st.pb(Node());
        }
    }
    
    void update(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].v++;
            return;
        }
        
        extend(p);
        // push(p, l, r);
        
        int m = (l + r) / 2;
        
        update(st[p].lc, l, m, i, j);
        update(st[p].rc, m + 1, r, i, j);
        
        st[p].v = st[st[p].lc].v + st[st[p].rc].v;
    }
    
    int query(int p, int l, int r, int i) {
        if (l == r) return l;
        
        int m = (l + r) / 2;
        
        int destroyed = (st[p].lc == -1 ? 0 : st[st[p].lc].v);
        int rem = (m - l + 1 - destroyed);
        
        extend(p);
        if (i <= rem) {
            return query(st[p].lc, l, m, i);
        }
        
        return query(st[p].rc, m + 1, r, i - rem);
    }
    
    void update(int i) {
        update(0, 0, n - 1, i, i);
    }
    
    int query(int i) {
        return query(0, 0, n - 1, i);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int MX = n + 1e5 + 67;
    Segtree st(MX + 1);
    
    while (m--) {
        char type; int room;
        cin >> type >> room;
        
        int real = st.query(room);
        
        if (type == 'L') {
            cout << real+1 << ln;
        }
        else {
            st.update(real);
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
