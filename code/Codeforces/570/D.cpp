// Problem: D. Tree Requests
// Contest: Codeforces - Codeforces Round 316 (Div. 2)
// URL: https://codeforces.com/contest/570/problem/D
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

struct Segtree {
  vector<int> st;
  int n;
  
  Segtree(int _n) {
      n = _n;
      int v = 1;
      while (v < n) v <<= 1;
      st.assign(2*v, 0);
  }
  
  void update(int p, int l, int r, int i, int j, char v) {
      if (l > j or r < i) return;
      if (l >= i and r <= j) {
          int k = (v - 'a');
          st[p] ^= (1ll << k);
          return;
      }
      
      int m = (l + r) / 2;
      
      update(2*p, l, m, i, j, v);
      update(2*p+1, m + 1, r, i, j, v);
      
      st[p] = st[2*p] ^ st[2*p+1];
  }
  
  int query(int p, int l, int r, int i, int j) {
      if (l > j or r < i) return 0;
      if (l >= i and r <= j) {
          return st[p];
      }

      int m = (l + r) / 2;
      
      return (
          query(2*p, l, m, i, j) ^
          query(2*p+1, m + 1, r, i, j)
      );
  }
  
  void update(int i, int j, char v) {
      update(1, 0, n - 1, i, j, v);
  }
  
  int query(int i, int j) {
      return query(1, 0, n - 1, i, j);
  }
};

vector<int> tin, tout;
vector<vector<int>> per_depth;
vector<vector<int>> AL;
int timer = 0;

void dfs(int u, int p, int depth = 0) {
    tin[u] = timer++;
    per_depth[depth].pb(u);
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        dfs(v, u, depth + 1);
    }
    
    tout[u] = timer - 1;
}

struct Query {
    int u, idx;
};

void solve() {
    int n, m;
    cin >> n >> m;
    tin.assign(n, 0);
    tout.assign(n, 0);
    per_depth.assign(n + 1, vector<int>());
    AL.assign(n, vector<int>());
    
    for (int v = 1; v < n; v++) {
        int u;
        cin >> u;
        u--;
        AL[u].pb(v);
    }
    
    dfs(0, -1);
    
    string s;
    cin >> s;
    
    vector<vector<Query>> queries(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, h;
        cin >> u >> h;
        u--, h--;
        queries[h].pb({u, i});
    }
    
    vector<int> ans(m, 0);
    Segtree st(n);
    
    for (int i = 0; i <= n; i++) {
        // Remove all previous
        if (i) {
            for (int j = 0; j < per_depth[i-1].size(); j++) {
                int idx = per_depth[i-1][j];
                int start = tin[idx];
                
                st.update(start, start, s[idx]);
            }
        }
        
        // Add all new ones
        for (int j = 0; j < per_depth[i].size(); j++) {
                int idx = per_depth[i][j];
                int start = tin[idx];
                
                st.update(start, start, s[idx]);
            }
        
        // Process queries on this depth
        for (auto& q : queries[i]) {
            int idx = q.u;
            int start = tin[idx];
            int ending = tout[idx];
            int res = st.query(start, ending);
            
            if (__builtin_popcountll(res) <= 1) {
                ans[q.idx] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << (ans[i] ? "Yes":"No") << ln;
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
