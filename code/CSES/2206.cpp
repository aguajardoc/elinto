// Problem: Pizzeria Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2206
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

struct Segtree {
    vector<int> st;
    int n, TREE_SIZE = 1;
    
    Segtree (int _n) {
        n = _n;
        while (TREE_SIZE < n) TREE_SIZE <<= 1;
        st.assign(2*TREE_SIZE, 0);
    }
    
    void update(int i, int x) {
        i += TREE_SIZE;
        st[i] = x;
        i >>= 1;
        
        while (i) {
            st[i] = min(st[2*i], st[2*i+1]);
            i >>= 1;
        }
    }
    
    int query(int l, int r) {
        l += TREE_SIZE;
        r += TREE_SIZE;
        int res = INF;
        
        while (l <= r) {
            if (l&1) res = min(res, st[l++]);
            if (!(r&1)) res = min(res, st[r--]);
            
            l >>= 1;
            r >>= 1;
        }
        
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    Segtree LR(n), RL(n);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        LR.update(i, x + i);
        RL.update(i, x + (n - 1 - i));
    }
    
    for (int i = 0; i < q; i++) {
        int type, k, x;
        cin >> type;
        if (type == 1) {
            cin >> k >> x;
            k--;
            
            LR.update(k, x + k);
            RL.update(k, x + (n - 1 - k));
        }
        else {
            cin >> k;
            k--;
            
            int ans = min(
                LR.query(k, n - 1) - k,
                RL.query(0, k) - (n - 1 - k)
            );
            
            cout << ans << ln;
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
