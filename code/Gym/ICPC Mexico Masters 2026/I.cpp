// Problem: I. In the Team Photo
// Contest: Codeforces - ICPC Masters Mexico 2026
// URL: https://codeforces.com/gym/106646/problem/I
// Memory Limit: 256 MB
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

struct Node {
    int val, lazy;  
    Node() {
        val = 0, lazy = 0;
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
        
        st[2*p].val += st[p].lazy;
        st[2*p+1].val += st[p].lazy;
        
        st[2*p].lazy += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].val += v;
            st[p].lazy += v;
            return;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);
        
        st[p].val = min(st[2*p].val, st[2*p+1].val);
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return INF;
        if (l >= i and r <= j) {
            return st[p].val;
        }
        push(p, l, r);
        
        int m = (l + r) / 2;
        return (min(
            query(2*p, l, m, i, j),
            query(2*p + 1, m + 1, r, i, j)
        ));
    }
    
    void update(int i, int j, int v) {
        update(1, 0 , n - 1, i, j , v);
    }
    
    int query(int i, int j) {
        return query(1, 0, n - 1, i , j);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), vals = {(int)1e7};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.pb(a[i]);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& i : a) {
        i = lower_bound(vals.begin(), vals.end(), i) - vals.begin();
    }
    
    int m = vals.size();
    vector<int> last(m, 0), last2(m, 0);
    Segtree st(n + 1);
    for (int i = 1; i <= n; i++) {
        int p1 = last[a[i]];
        int p2 = last2[a[i]];
        
        st.update(p1 + 1, i, 1);
        
        if (p1) st.update(p2 + 1, p1, -1);
        
        last2[a[i]] = last[a[i]];
        last[a[i]] = i;
        
        if (!st.query(1, i)) {
            cout << "NO" << ln;
            return;
        }
    }
    
    cout << "YES" << ln;
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