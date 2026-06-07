// Problem: D. Dynamic Collection
// Contest: Codeforces - 2023 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/696886/problem/D
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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

struct Query {
    int type, k, b;
};

int get_idx(int& x, vector<int>& vals) {
    return (lower_bound(vals.begin(), vals.end(), x) - vals.begin());
}

struct Segtree {
    vector<int> st;
    int n;
    int TREE_SIZE = 1;
    
     Segtree(int _n) {
         while (TREE_SIZE < _n) TREE_SIZE <<= 1;
         n = TREE_SIZE;
         st.assign(2*TREE_SIZE, 0);
     }
     
     void update(int i, int x) {
         i += TREE_SIZE;
         st[i] += x;
         i >>= 1;
         
         while(i) {
             st[i] = st[2*i] + st[2*i+1];
             i >>= 1;
         }
     }
     
     int query(int l, int r) {
         l += TREE_SIZE;
         r += TREE_SIZE;
         int res = 0;
         
         while(l <= r) {
             if (l&1) res += st[l++];
             if (!(r&1)) res += st[r--];
             
             l >>= 1;
             r >>= 1;
         }
         
         return res;
     }
     
     int walk(int p, int l, int r, int k) {
         // dbg(p, l, r);
         if (l == r) return l;
         
         int m = (l + r) / 2;
         // dbg(st[p], st[2*p]);
         int ele = st[2*p];
         
         // dbg(ele, k);
         
         if (ele >= k) {
             // go
             return walk(2 * p, l, m, k);
         }
         else {
             // ans is on left side
             // dbg(p, l, r);
             // dbg(k);
             // dbg(st[2*p]);
             return walk(2*p+1, m+1, r, k-ele);
         }
     }
     
     int walk(int k) {
         return walk(1, 0, n - 1, k);
     }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vals;
    vector<int> items(n);
    vector<Query> queries(q);
    for (auto& i : items) {
        cin >> i;
        vals.pb(i);
    }
    
    for (int i = 0;i < q; i++) {
        int type, k, a, b;
        cin >> type;
        if (type == 1) {
            cin >> k;
            queries[i].type = type;
            queries[i].k = k;
            vals.pb(k);
        }
        else {
            cin >> a >> b;
            queries[i].type = type;
            queries[i].k = a;
            queries[i].b = b;
            vals.pb(a);
            vals.pb(b);
        }
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (auto& i : items) {
        i = get_idx(i, vals);
    }
    
    for (auto& i : queries) {
        if (i.type == 1) {
            i.k = get_idx(i.k, vals);
        }
        else {
            i.k = get_idx(i.k, vals);
            i.b = get_idx(i.b, vals);
        }
    }
    
    // for (auto& i : vals) {
        // cout << i << " ";
    // }
    // cout << ln;
    
    int m = vals.size() + 100;
    Segtree st(m + 1);
    
    for (auto& i : items) {
        st.update(i, 1); // add all items
    }

    
    
    for (auto& i : queries) {
        if (i.type == 1) {
            // 1.
            if (st.query(i.k, i.k)) {
                continue;
            }
            
            // dbg(i.k);
            
            // 2.
            if (!st.query(i.k, m)) {
                st.update(i.k, 1);
                continue;
            }
            
            // dbg(st.query(0, 4));
            
            // 3.
            int x = st.walk(st.query(0, i.k) + 1);
            st.update(x, -1);
            st.update(i.k, 1);
            
            // dbg(i.k, x);
            // dbg(st.query(x, x));
        }
        else {
            // dbg(i.a, i.b);
            cout << st.query(i.k, i.b) << ln;
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
