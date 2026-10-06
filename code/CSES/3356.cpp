// Problem: Distinct Values Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3356
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
// #define int ll
#define ld long double
#define pb push_back

const int INF = INT32_MAX;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int TREE_SIZE = 1 << 18;
int st[2*TREE_SIZE];

void update(int i, int x) {
    i += TREE_SIZE;
    st[i] = x;
    i >>= 1;
    
    while(i) {
        st[i] = min(st[2*i], st[2*i+1]);
        i >>= 1;
    }
}

int query(int l, int r) {
    l += TREE_SIZE;
    r += TREE_SIZE;
    int res = INF;
    
    while(l <= r) {
        if (l&1) res = min(res, st[l++]);
        if (!(r&1)) res = min(res, st[r--]);
        
        l >>= 1;
        r >>= 1;
    }
    
    return res;
}

void solve() {
    fill_n(&st[0], 2*TREE_SIZE, INF);
    int n, q; cin >> n >> q;
    map<int, set<int>> ct;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ct[a[i]].insert(i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        auto it = ct[a[i]].upper_bound(i);
        if (it == ct[a[i]].end()) continue;
        
        update(i, *it);
    }
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            k--;
            
            // Recompute everything
            // Erase current
            ct[a[k]].erase(k);
            // Check if there was a previous
            if (!ct[a[k]].empty()) {
                auto it_old = ct[a[k]].upper_bound(k);
                
                if (it_old != ct[a[k]].begin()) {
                    auto it_old_prev = it_old;
                    it_old_prev--;
                    // Check if there
                    if (it_old == ct[a[k]].end()) {
                        update(*it_old_prev, INF);
                    }
                    else {
                        update(*it_old_prev, *it_old);
                    }
                }
            }
            else {
                ct.erase(a[k]);
            }
            
            // Add new
            a[k] = u;
            ct[a[k]].insert(k);
            // Check if previous is affected
            auto it_new = ct[a[k]].lower_bound(k);
            if (it_new != ct[a[k]].begin()) {
                auto it_new_prev = it_new;
                it_new_prev--;
                
                update(*it_new_prev, k);
            }
            // Check if this adds a new one to my right
            it_new++;
            if (it_new != ct[a[k]].end()) {
                update(k, *it_new);
            }
            else update(k, INF);
            
        }
        else {
            int a, b; cin >> a >> b;
            a--, b--;
            cout << (query(a, b) <= b ? "NO":"YES") << ln;
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
