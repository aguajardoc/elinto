// Problem: C. Simons and Posting Blogs
// Contest: Codeforces - Codeforces Round 1083 (Div. 2)
// URL: https://codeforces.com/contest/2205/problem/C
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

void solve() {
    int n;
    cin >> n;
    // take all blogs
    vector<vector<int>> a(n);
    // reverse all blogs O(n)
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        set<int> seen;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            a[i].pb(x);
        }
        
        reverse(a[i].begin(), a[i].end());
        vector<int> b;
        for (int j = 0; j < m; j++) {
            if (seen.insert(a[i][j]).second) {
                b.pb(a[i][j]);
            }
        }
        a[i] = b;
    }
    
    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        sort(a.rbegin(), a.rend());
    
        // take the smallest O(1)
        set<int> banned;
        for (auto& j : a.back()) {
            ans.pb(j);
            banned.insert(j);
        }
        // ban all O(n)
        for (int j = 0; j < (int)a.size(); j++) {
            vector<int> nv;
            for (int k = 0; k < a[j].size(); k++) {
                if (!banned.count(a[j][k])) {
                    nv.pb(a[j][k]);
                }
            }
            a[j] = nv;
        }
        
        a.pop_back();
        
        // create new vectors
        // resort?
    }
    
    
    for (auto& i : ans) {
        cout << i << " " ;
    }
    cout << ln;
    
    
    
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
