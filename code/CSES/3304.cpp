// Problem: Visible Buildings Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3304
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

const int TREE_SIZE = 1 << 18;
int st[2*TREE_SIZE];

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
    
    while (l <= r) {
        if (l&1) res += st[l++];
        if (!(r&1)) res += st[r--];
        
        l >>= 1; r >>= 1;
    }
    
    return res;
}

struct Range {
    int l, r, idx;
    bool operator<(const auto& oth) const {
        return l < oth.l;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> where;
    map<int, int> curi;
    
    vector<int> a(n), ans(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]].pb(i);
        curi[a[i]] = -1;
    }
    
    vector<Range> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }
    sort(queries.rbegin(), queries.rend());
    
    stack<pair<int, int>> st;
    int idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and st.top().first <= a[i]) {
            update(st.top().second, 0);
            st.pop();
        }
        st.push({a[i], i});
        update(i, 1);
        
        while (idx < q and queries[idx].l == i) {
            ans[queries[idx].idx] = query(queries[idx].l, queries[idx].r);
            idx++;
        }
    }
    
    
    for (auto& i : ans) cout << i << ln;
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
