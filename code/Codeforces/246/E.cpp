// Problem: E. Blood Cousins Return
// Contest: Codeforces - Codeforces Round 151 (Div. 2)
// URL: https://codeforces.com/contest/246/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct Segtree {
    vector<int> st;
    int n;
    
    Segtree (int _n) {
        n = _n;
        int k = 1;
        while (k < n) k <<= 1;
        st.assign(2 * k, 0);
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p] = v;
            return;
        }
        int m = (l + r) / 2;
        
        update(2 * p, l, m, i, j, v);
        update(2 * p + 1, m + 1, r, i, j, v);
        
        st[p] = st[2*p] + st[2*p+1];
    }
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p];
        }
        int m = (l + r) / 2;
        
        return (
            query(2 * p, l, m, i, j) +
            query(2 * p + 1, m + 1, r, i, j)
        );
    }
    
    void update(int i, int j, int v) {
        update(1, 0, n - 1, i, j, v);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

struct Query {
    int v, h, d, idx, l, r;
};

const int MAXN = 200006;

int d[MAXN + 1], tin[MAXN + 1], tout[MAXN + 1], ans[MAXN + 1], nameidx[MAXN + 1], anti_tin[MAXN + 1];
string names_pre[MAXN + 1];
vector<int> AL[MAXN + 1], per_depth[MAXN + 1];
vector<Query> queries[MAXN + 1];
int timer = 0;

void dfs(int u, int p=-1, int depth=0) {
    d[u] = depth;
    per_depth[depth].pb(timer);
    anti_tin[timer] = u;
    tin[u] = timer++;
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        dfs(v, u, depth + 1);
    }
    
    tout[u] = timer - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> fatherless;
    vector<string> names;
    
    fill_n(&nameidx[0], MAXN, -1);
    fill_n(&anti_tin[0], MAXN, -1);
    fill_n(&d[0], MAXN, -1);
    fill_n(&tin[0], MAXN, -1);
    fill_n(&tout[0], MAXN, -1);
    fill_n(&ans[0], MAXN, 0);
    
    for (int i = 0; i < n; i++) {
        string s;
        int u;
        cin >> s >> u;
        u--;
        
        names.pb(s);
        names_pre[i] = s;
        
        if (u != -1) {
            AL[u].pb(i);
        }
        else fatherless.pb(i);
    }
    
    sort(names.begin(), names.end());
    names.resize(unique(names.begin(), names.end()) - names.begin());
    for (int i = 0; i < n; i++) {
        nameidx[i] = lower_bound(names.begin(), names.end(), names_pre[i]) - names.begin();
    }
    
    for (auto& i : fatherless) {
        dfs(i);
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        Query q;
        cin >> q.v >> q.h;
        q.v--;
        
        q.d = d[q.v] + q.h;
        q.l = tin[q.v];
        q.r = tout[q.v];
        q.idx = i;
        queries[q.d].pb(q);
        
        // dbg(q.v, q.h);
        // dbg(q.l, q.r);
        // dbg(q.d);
    }
    
    for (int i = 0; i <= MAXN; i++) {
        sort(queries[i].begin(), queries[i].end(), [](const auto& a, const auto& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });
    }
    
    Segtree st(MAXN + 67);
    for (int i = 0; i <= MAXN; i++) {
        // Remove previous depth
        if (i) {
            for (auto& r : per_depth[i-1]) {
                st.update(r, r, 0);
            }
        }
        
        // Process queries
        map<int, int> last;
        int idx = 0;
        for (auto& q : queries[i]) {
            while (idx < per_depth[i].size() and per_depth[i][idx] <= q.r) {
                int r = per_depth[i][idx];
                int nai = nameidx[anti_tin[r]];
            
                if (anti_tin[r] != -1 and nai != -1) {
                    string na = names[nai];
                    
                    // dbg(i, r);
                    // dbg(anti_tin[r]);
                    // dbg(na);
                    // cout << ln;
                    if (last.count(nai)) {
                        // dbg(last[nai]);
                        st.update(last[nai], last[nai], 0);
                    }
                    st.update(r, r, 1);
                    last[nai] = r;
                }
                idx++;
            }
            
            ans[q.idx] = st.query(q.l, q.r);
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << ln;
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
