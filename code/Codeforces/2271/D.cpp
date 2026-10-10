// Problem: D. Target Infection
// Contest: Codeforces - DeepInfra Round 1 (Codeforces Round 1126, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2271/problem/D
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

struct Range {
    int l, r;
    bool operator <(const auto& oth) const {
        return l < oth.l;
    }
};

int count_ones(int start, int elem, vector<int>& pg, vector<int>& sg, int i, vector<int>& g) {
    int start_pos = pg[i] + start;
    int end_pos = start_pos + elem - 1;
    
    // dbg(start_pos, end_pos);
    int start_idx = i;
    int end_idx = upper_bound(pg.begin(), pg.end(), end_pos) - pg.begin() - 1;
    // dbg(start_idx, end_idx);
    
    if (start_idx == end_idx) {
        if (i % 2) return elem;
        return 0;
    }
    
    int start_elem = pg[start_idx+1] - pg[start_idx];
    int end_elem = pg[end_idx+1] - pg[end_idx];
    
    // dbg(start_elem, end_elem);
    
    int end_ends_at = pg[end_idx+1];
    int end_starts_at = pg[end_idx];
    // dbg(end_ends_at);
    
    // Get those exactly at start
    int start_ones = 0;
    if (start_idx % 2) start_ones = start_elem - start;
    
    int end_ones = 0;
    if (end_idx % 2) end_ones = end_pos - end_starts_at + 1;
    
    // dbg(start_ones, end_ones);
    int mid_ones = 0;
    int mid_l = start_idx + 1;
    int mid_r = end_idx - 1;
    if (mid_l <= mid_r) {
        mid_ones = sg[mid_r+1] - sg[mid_l];
    }
    
    // dbg(mid_ones);
    
    int ones = start_ones + mid_ones + end_ones;
    
    return ones;
}

int find_ans(int i, int n, vector<int>& g, int p, int k, int elem, vector<int>& pg, vector<int>& sg) {
    int l = 0, r = g[i] - 1; // offset
    // dbg(i, l, r);
    int ans = INF;
    while (l <= r) {
        int m = (l + r) / 2;
        
        int fm = count_ones(m, elem, pg, sg, i, g);
        // dbg(i, m, fm);
        // cout << ln;
        if (p and fm <= k) {
            if (fm == k) ans = min(ans, m);
            r = m - 1;
        }
        else if (!p and fm >= k) {
            if (fm == k) ans = min(ans, m);
            r = m  - 1;
        }
        else {
            l = m + 1;
        }
    }
    
    if (ans == INF) ans = -INF;
    return ans;
}

// int find_ans(int i, int n, vector<int>& g) {
    // if (i % 2 == 0) {
        // // Within this segment
        // // The answer can only get larger, monot
        // return find_inc(i, n, g);
    // }
    // // It can only get smaller, also monot
    // return find_dec(i, n, g);
// }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<Range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].l--;
        a[i].r--;
    }
    int cur = 0;
    vector<int> g;
    for (int i = 0; i < n; i++) {
        g.pb(a[i].l - cur);
        
        g.pb(a[i].r - a[i].l + 1);
        cur = a[i].r + 1;
    }
    
    g.pb(INF);
    
    int y = g.size();
    vector<int> pg(y + 1, 0), sg(y + 1, 0);
    for (int i = 0; i < y; i++) {
        pg[i+1] = pg[i] + g[i];
        sg[i+1] = sg[i] + g[i] * (i%2);
    }
    // for (auto& i : g) cout << i << " ";
    // cout << ln;
    // for (auto& i : pg) cout << i << " ";
    // cout << ln;
    // for (auto& i : sg) cout << i << " ";
    // cout << ln;
    // cout << ln;
    
    // for (int i = 0; i < y; i++) {
        // int res = find_ans(i, n, g, i % 2, k, m, pg, sg);
        // dbg(i);
        // int res2 = count_ones(0, m, pg, sg, i);
        // dbg(res2);
//         
        // cout << ln;
    // }
    
    int ans = -1;
    int sum = 1;
    for (int i = 0; i < y and ans <= -1; i++) {
        int res = find_ans(i, y, g, i%2, k, m, pg, sg);;
        // dbg(res, sum);
        if (res != -INF and res + sum <= 1e18) {
            // dbg("ANWUEDFBUIYHXD");
            cout << res + sum << ln;
            return;
        }
        sum += g[i];
    }
    
    cout << -1 << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
