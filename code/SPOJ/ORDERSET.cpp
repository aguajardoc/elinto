// Problem: Order statistic set
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ORDERSET/
// Memory Limit: 1536 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int TREE_SIZE = 1 << 18;
int st[2*TREE_SIZE];
int n;
unordered_map<int, int> mapping;

void update(int i, int x) {
    i += TREE_SIZE;
    st[i] = x;
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


void insert(int x) {
    update(x, 1);
}

void delete_x(int x) {
    update(x, 0);
}

int kth(int k) {
    int l = 0, r = n;
    int ans = INF;
    while (l <= r) {
        int m = (l + r) / 2;
        
        if (query(0, m) >= k) {
            ans = min(ans, m);
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    
    if (ans == INF) return -1;
    return mapping[ans];
}

int count(int x) {
    return query(0, max(0, x - 1));
}

struct Query {
    char type;
    int param;
};

void solve() {
    int q; cin >> q;
    vector<Query> qs(q);
    vector<int> vals = {-INF};
    for (int i = 0; i < q; i++) {
        cin >> qs[i].type >> qs[i].param;
        vals.pb(qs[i].param);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& i : qs) {
        if (i.type == 'K') continue;
        int x = i.param;
        i.param = lower_bound(vals.begin(), vals.end(), i.param) - vals.begin();
        mapping[i.param] = x;
    }
    
    n = vals.size();
    
    for (auto& i : qs) {
        if (i.type == 'I') insert(i.param);
        if (i.type == 'D') delete_x(i.param);
        if (i.type == 'C') cout << count(i.param) << ln;
        if (i.type == 'K') {
            int res = kth(i.param);
            if (res == -1) cout << "invalid" << ln;
            else cout << res << ln;
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
