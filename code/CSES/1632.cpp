// Problem: Movie Festival II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1632
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

struct Event {
    int s, e, type, idx;
    bool operator <(const auto& oth) const {
        return e < oth.e;
    }
};

struct Node {
    int mx, lazy;
    Node() {
        mx = 0, lazy = 0;
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
          
          st[2*p].mx += st[p].lazy;
          st[2*p+1].mx += st[p].lazy;
          
          st[2*p].lazy += st[p].lazy;
          st[2*p+1].lazy += st[p].lazy;
          
          st[p].lazy = 0;
      }
      
      void update(int p, int l, int r, int i, int j) {
          if (l > j or r < i) return;
          if (l >= i and r <= j) {
              st[p].mx++;
              st[p].lazy++;
              return;
          }
          
          push(p, l, r);
          
          int m = (l + r) / 2;
          update(2*p, l, m, i, j);
          update(2*p+1, m + 1, r, i, j);
          
          st[p].mx = max(st[2*p].mx, st[2*p+1].mx);
      }
      
      int query(int p, int l, int r, int i, int j) {
          if (l > j or r < i) return 0;
          if (l >= i and r <= j) {
              return st[p].mx;
          }
          
          push(p, l, r);
          
          int m = (l + r) / 2;
          
          return max(
              query(2*p, l, m, i, j),
              query(2*p+1, m + 1, r, i, j)
          );
      }
      
      void update(int i, int j) {
          update(1, 0, n - 1, i, j);
      }
      
      int query(int i, int j) {
          return query(1, 0, n - 1, i, j);
      }
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    int cur = 0;
    vector<Event> events;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        events.pb({s, e, 1, i});
        vals.pb(s); vals.pb(e);
    }
    
    sort(events.begin(), events.end());
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& x : events) {
        x.s = lower_bound(vals.begin(), vals.end(), x.s) - vals.begin();
        x.e = lower_bound(vals.begin(), vals.end(), x.e) - vals.begin();
    }
    
    int ans = 0;
    Segtree st(vals.size() + 67);
    for (int i = 0; i < events.size(); i++) {    
        if (st.query(events[i].s, events[i].e-1) == k) continue;
        st.update(events[i].s, events[i].e-1);
        ans++;
    }
    
    cout << ans << ln;
    
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
