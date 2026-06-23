// Problem: C - Tallest at the Moment
// Contest: AtCoder - AtCoder Beginner Contest 463
// URL: https://atcoder.jp/contests/abc463/tasks/abc463_c
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

struct Change {
    int v, t;
    bool operator<(const auto& oth) {
        if (t != oth.t) return t < oth.t;
        else return v < oth.v;
    }
};

struct Query {
    int t, idx;
    bool operator<(const auto& oth) {
        return t < oth.t;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Change> a;
    
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int h, l;
        cin >> h >> l;
        ms.insert(h);
        
        a.pb({h, l});
    }
    
    sort(a.begin(), a.end());
    
    int q;
    cin >> q;
    vector<Query> qs;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        qs.pb({t, i});
    }
    
    sort(qs.begin(), qs.end());
    
    vector<int> ans(q, 0);
    int p = 0;
    for (auto& [t, idx] : qs) {
        while (p < n and a[p].t <= t) {
            // dbg(a[p].v);
            // dbg(a[p].t);
            // dbg(t);
            ms.erase(ms.find(a[p].v));
            p++;
        }
        
        // dbg(*ms.rbegin());
        
        ans[idx] = *ms.rbegin();
    }
    
    for (auto& i : ans) {
        cout << i << ln;
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
