// Problem: G1. Into Blocks (easy version)
// Contest: Codeforces - Codeforces Round 584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1209/problem/G1
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
    int L, R, ct;
    bool operator<(const auto& oth) {
        return L < oth.L;
    }
    
    bool operator==(const auto& oth) {
        return (L == oth.L and R == oth.R and ct == oth.ct);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    Range init = {-1, -1, 1};
    vector<Range> ranges(201000, init);
    
    for (int i = 0; i < n; i++) {
        if (ranges[a[i]].L == -1) ranges[a[i]].L = i;
        ranges[a[i]].R = i;
    }
    sort(ranges.rbegin(), ranges.rend());
    pair<int, int> sent = {-1, -1};
    while (!ranges.empty() and ranges.back() == init) {
        ranges.pop_back();
    }
    sort(ranges.begin(), ranges.end());
    
    vector<Range> filtered;
    Range current = init;
    for (int i = 0; i < ranges.size(); i++) {
        if (current == init) {
            current = ranges[i];
        }
        else {
            if (ranges[i].L <= current.R) {
                current.ct++;
                current.R = max(current.R, ranges[i].R);
            }
            else {
                filtered.pb(current);
                current = ranges[i];
            }
        }
    }
    filtered.pb(current);
    
    int ans = 0;
    for (auto& i : filtered) {
        if (i.ct == 1) continue;
        
        map<int, int> cts;
        int mx = 0;
        for (int j = i.L; j <= i.R; j++) {
            mx = max(mx, ++cts[a[j]]);
        }
        
        ans += (i.R - i.L + 1) - mx;
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
