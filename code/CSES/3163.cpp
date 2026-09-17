// Problem: Range Interval Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3163
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

struct Query {
    int a, b, last, type, idx;
    bool operator<(const auto& oth) const {
        return last < oth.last;
    }
};

struct Segtree {
      vector<int> st;
      int n, t;
      
      Segtree(int _n) {
          n = _n;
          t = 1;
          while (t < n) t <<= 1;
          st.assign(2*t, 0);
      }
      
      void update(int i, int x) {
          i += t;
          st[i] = x;
          i >>= 1;
          
          while (i) {
              st[i] = st[2*i] + st[2*i+1];
              i >>= 1;
          }
      }
      
      int query(int l, int r) {
          l += t;
          r += t;
          int res = 0;
          
          while (l <= r) {
              if (l % 2 == 1) {
                  res += st[l];
                  l++;
              }
              if (r % 2 == 0) {
                  res += st[r];
                  r--;
              }
              
              l >>= 1;
              r >>= 1;
          }
          
          return res;
      }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<Query> queries;
    vector<int> vals = {0};
    vector<int> a(n), ans(q);
    for (auto& i : a) {
        cin >> i;
        vals.pb(i);
    }
    
    // Input everything, with [L - 1, R] as last points
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        vals.pb(c - 1); vals.pb(d);
        queries.pb({a, b, c - 1, -1, i});
        queries.pb({a, b, d, 1, i});
    }
    // Coord compression on c and d
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& i : a) {
        i = lower_bound(vals.begin(), vals.end(), i) - vals.begin();
    }
    for (auto& i : queries) {
        i.last = lower_bound(vals.begin(), vals.end(), i.last) - vals.begin();
    }
    
    // Sort by last
    sort(queries.begin(), queries.end());
    
    // Get indices affected at each value
    int m = vals.size();
    vector<vector<int>> buckets(m + 1);
    for (int i = 0; i < n; i++) {
        buckets[a[i]].pb(i);
    }
    
    // Update values in segtree up to i
    Segtree st(m + 1);
    int idx = 0;
    for (int i = 0; i <= m; i++) {
        for (auto& x : buckets[i]) {
            st.update(x, 1);
        }
        
        // Subtract result if type == -1, add if 1
        while (idx < queries.size() and queries[idx].last == i) {
            ans[queries[idx].idx] += queries[idx].type * st.query(queries[idx].a, queries[idx].b);
            idx++;
        }
    }
    
    for (auto& i : ans) {
        cout << i << ln;
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
