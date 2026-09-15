// Problem: Nested Ranges Check
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2168
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
    int s, mn, lazy;
    
    Node() {
        s = 0, mn = 0, lazy = 0;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int _n) {
        n = _n;
        
        st.assign(4*n, Node());
    }
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        
        st[2*p].s += st[p].lazy;
        st[2*p].mn += st[p].lazy;
        st[2*p].lazy += st[p].lazy;

        st[2*p+1].s += st[p].lazy;
        st[2*p+1].mn += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].s++; st[p].mn++;
            st[p].lazy++;
            return;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        update(2*p, l, m, i, j);
        update(2*p + 1, m + 1, r, i, j);
        
        st[p].s = st[2*p].s + st[2*p+1].s;
        st[p].mn = min(st[2*p].mn, st[2*p+1].mn);
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p].s;
        push(p, l, r);
        
        int m = (l + r) / 2;
        int R1 = query(2*p, l, m, i, j);
        int R2 = query(2*p+1, m + 1, r, i, j);
        return R1 + R2;
    }
    
    int qmin(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return INF;
        if (l >= i and r <= j) return st[p].mn;
        push(p, l, r);
        
        int m = (l + r) / 2;
        int R1 = qmin(2*p, l, m, i, j);
        int R2 = qmin(2*p+1, m + 1, r, i, j);
        return min(R1, R2);
    }
    
    void update(int l, int r) {
        update(1, 0, n - 1, l, r);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    
    int qmin(int l, int r) {
        return qmin(1, 0, n - 1, l, r);
    }
};

struct Range {
    int L, R, idx;
    bool operator <(const auto& oth) const {
        if (R != oth.R) return R < oth.R;
        return (R - L) < (oth.R - oth.L);
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<int> vals;
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].L >> ranges[i].R;
        ranges[i].idx = i;
        vals.pb(ranges[i].L);
        vals.pb(ranges[i].R);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& x : ranges) {
        x.L = lower_bound(vals.begin(), vals.end(), x.L) - vals.begin();
        x.R = lower_bound(vals.begin(), vals.end(), x.R) - vals.begin();
    }
    
    vector<int> a1(n), a2(n);
    Segtree st(vals.size() + 1);
    Segtree st2(vals.size() + 1);
    
    sort(ranges.begin(), ranges.end());
    for (auto& x : ranges) {
        a1[x.idx] = st.query(x.L, x.R);
        st.update(x.L, x.L);
    }
    
    sort(ranges.rbegin(), ranges.rend());
    for (auto& x : ranges) {
        a2[x.idx] = st2.qmin(x.L, x.R);
        st2.update(x.L, x.R);
    }
    
    for (auto& i : a1) {
        cout << (i>0) << " ";
    }
    cout << ln;
    for (auto& i : a2) {
        cout << (i>0) << " ";
    }
    cout << ln;
    
    
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
