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

typedef long long ftype;
typedef complex<ftype> point;

struct LiChaoTree {
    ftype f(point a, ftype x) {
        return a.real() * x + a.imag();
    }

    int n;
    vector<point> line;

    // Constructor: n is the maximum X coordinate, inf is the dummy high value
    LiChaoTree(int max_x) {
        n = max_x;
        int sz = 1;
        while (sz < n) sz <<= 1;
        line.assign(2 * sz, {0, INF}); 
    }

    void add_line(point nw, int v = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        int m = l + (r - l) / 2;
        
        bool lef = f(nw, l) < f(line[v], l);
        bool mid = f(nw, m) < f(line[v], m);
        
        if (mid) {
            swap(line[v], nw);
        }
        if (r - l == 1) return; 
        else if (lef != mid) {
            add_line(nw, 2 * v, l, m);
        } 
        else {
            add_line(nw, 2 * v + 1, m, r);
        }
    }

    ftype get(int x, int v = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        int m = l + (r - l) / 2;
        
        if (r - l == 1) return f(line[v], x);
        else if (x < m) {
            return min(f(line[v], x), get(x, 2 * v, l, m));
        } 
        else {
            return min(f(line[v], x), get(x, 2 * v + 1, m, r));
        }
    }
};

int dp[100001];

void solve() {
    int n;
    cin >> n;
    vector<int> h(n+1), w(n+1);
    int W = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        W += w[i];
    }
    
    fill_n(&dp[0], 100001, 0);
    LiChaoTree lt(1000067);
    dp[1] = -w[1];
    
    point l0 = {-2ll * h[1], dp[1] + h[1] * h[1]};
    lt.add_line(l0);
    
    for (int i = 2; i <= n; i++) {
        ll F = lt.get(h[i]);
        
        dp[i] = F + h[i] * h[i] - w[i];
        
        point nl = {-2ll * h[i], dp[i] + h[i] * h[i]};
        lt.add_line(nl);
    }
    
    cout << dp[n] + W << ln;
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
