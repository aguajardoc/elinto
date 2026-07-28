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
    int pl=-1, pr=-1;
    ll val, lazy;
};

struct Segtree {
    vector<Node> st;
    int n;

    Segtree(int _n) {
        st.pb(Node());
        st.reserve(1e7);
        n = _n;
    }

    void extend(int p) {
        if (st[p].pl == -1) {
            st[p].pl = st.size();
            st.pb(Node());
        }
        if (st[p].pr == -1) {
            st[p].pr = st.size();
            st.pb(Node());
        }
    }

    void push(int p, int l, int r) {
        extend(p);
        if (st[p].lazy==0) return;

        int m = (l + r) / 2;
        int pl = st[p].pl;
        int pr = st[p].pr;

        st[pl].val += (ll)(m - l + 1) * (st[p].lazy);
        st[pr].val += (ll)(r - m) * (st[p].lazy);

        st[pl].lazy += st[p].lazy;
        st[pr].lazy += st[p].lazy;
        st[p].lazy = 0;
    }

    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].val += (ll)(r - l + 1) * v;
            st[p].lazy += v;
            return;
        }
        push(p, l, r);

        int m = (l + r) / 2;
        int pl = st[p].pl;
        int pr = st[p].pr;

        update(pl, l, m, i, j, v);
        update(pr, m + 1, r, i, j, v);

        st[p].val = st[pl].val + st[pr].val;
    }

    ll query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p].val;
        }
        push(p, l, r);

        int m = (l + r) / 2;
        int pl = st[p].pl;
        int pr = st[p].pr;

        return (
            (ll)query(pl, l, m, i, j) + 
            (ll)query(pr, m + 1, r, i, j)
        );
    }

    void update(int i, int j, int v) {
        update(0, 0, n - 1, i, j, v);
    }

    ll query(int i, int j) {
        return query(0, 0, n - 1, i, j);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    Segtree st(1e9 + 67);

    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        r--;
        st.update(l, r, v);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r--;

        cout << st.query(l, r) << ln;
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ D.cpp && ./a.out <input.in>output.out