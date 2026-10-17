// Problem: D - Concatenation of Prefixes
// Contest: AtCoder - AtCoder Beginner Contest 480
// URL: https://atcoder.jp/contests/abc480/tasks/abc480_d
// Memory Limit: 1024 MB
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

vector<int> a, p, pn, starts;
int n, q;

int get_res(int x) {
    if (x == 0) return 0;
    // Get which start this is
    auto it = upper_bound(starts.begin(), starts.end(), x);
    it--;
    
    int start = *it;
    int times = (it - starts.begin());
    // dbg(x, start, times)
    
    // Get pn contribution
    int up = pn[times];
    int down = (n - times) * p[times];
    
    int pnc = up - down;
    
    // Get p contrib
    int diff = x - start + 1;
    // dbg(diff);
    int mid = p[diff];
    
    return pnc + mid;
}

void solve() {
    cin >> n >> q;
    a.resize(n + 1);
    pn.resize(n + 1);
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i-1] + a[i];
        pn[i] = pn[i-1] + (n - i + 1) * a[i];
    }
    
    while (q--) {
        int l, r; cin >> l >> r;
        
        int resr = get_res(r);
        int resl = get_res(l-1);
        
        int res = resr - resl;
        
        cout << res << ln;
    }
}

signed main() {
    fast_cin();
    starts = {1, 2};
    for (int i = 2; i <= 1e5 + 67; i++) {
        starts.pb(starts.back() + i);
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
