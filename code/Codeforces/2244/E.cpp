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

struct Query {
    int l, r, k, idx;

    bool operator<(const auto& oth) const {
        return r < oth.r;
    }
};

struct Segtree {
    vector<int> st;
    int TREE_SIZE = 1;
    int n;

    Segtree(int _n) {
        n = _n;
        while (TREE_SIZE < n) TREE_SIZE <<= 1;

        st.assign(2 * TREE_SIZE, 0);
    }

    void update(int i, int x) {
        i += TREE_SIZE;
        st[i] = x;
        i >>= 1;

        while (i) {
            st[i] = st[2*i] + st[2*i+1];
            i >>= 1;
        }
    }

    int query(int l, int r) {
        l += TREE_SIZE;
        r += TREE_SIZE;
        int res = 0;

        while(l <= r) {
            if (l & 1) res += st[l++];
            if (!(r&1)) res += st[r--];

            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<Query> qs(q);
    vector<int> ans(q, 0);

    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        l--, r--;
        qs[i] = {l, r, k, i};
    }

    sort(qs.begin(), qs.end());

    // get swaps for 0101010
    // get swaps for 1010101
    vector<int> swaps0(n, 0), swaps1(n, 0);
    int idx0 = 1, idx1 = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                swaps1[i] = idx1;
                idx0++;
            }
            else {
                swaps0[i] = idx0;
                idx1++;
            }
        }
        else {
            if (s[i] != '0') {
                swaps1[i] = idx1;
                idx0++;
            }
            else {
                swaps0[i] = idx0;
                idx1++;
            }
        }
    }

    // for (auto& i : swaps0) {
    //     cout << i << " ";
    // }
    // cout << ln;
    // for (auto& i : swaps1) {
    //     cout << i << " ";
    // } 
    // cout << ln << ln;

    // build two segtrees and update as queries go by
    Segtree st0(n+10), st1(n+10);
    vector<int> last0(n+10, -1), last1(n+10, -1);
    int cur = 0;
    for (int i = 0; i < q; i++) {
        while (cur <= qs[i].r) {
            // get val
            int v0 = swaps0[cur];
            int v1 = swaps1[cur];
            // dbg(cur, v0, v1);
            // remove prev if exists
            if (v0 and last0[v0] != -1) st0.update(last0[v0], 0);
            if (v1 and last1[v1] != -1) st1.update(last1[v1], 0);
            // update current
            if (v0) {
                st0.update(cur, 1);
                last0[v0] = cur;
            }
            if (v1) {
                st1.update(cur, 1);
                last1[v1] = cur;
            }

            cur++;
        }

        int res = min(
            st0.query(qs[i].l, qs[i].r),
            st1.query(qs[i].l, qs[i].r)
        );

        // dbg(qs[i].idx, res);
        // for (int j = 0; j < n; j++) {
        //     cout << st0.query(j, j) << " ";
        // }
        // cout << ln;
        // for (int j = 0; j < n; j++) {
        //     cout << st1.query(j, j) << " ";
        // }
        // cout << ln;

        if (res <= qs[i].k) ans[qs[i].idx] = 1;
    }

    for (auto& i : ans) {
        cout << (i ? "YES":"NO") << ln;
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ E.cpp && ./a.out <input.in>output.out