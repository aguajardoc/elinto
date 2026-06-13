// Problem: Brand New Tatar TV Show
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2236/problem/D
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> ct(n + 1, 0);
    for (auto& i : a) {
        cin >> i;
        ct[i]++;
    }
    
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    
    int m = a.size();
    vector<vector<int>> chains;
    chains.pb({a[0]});
    for (int i = 1; i < m; i++) {
        if (a[i] - a[i-1] > k) {
            // end previous chain, start new
            chains.pb({a[i]});
        }
        else {
            chains.back().pb(a[i]);
        }
    }
    
    for (auto& i : chains) {
        // if chain has at least one element
        if (ct[i.back()] % 2 == 0) {
            cout << "YES" << ln;
            return;
        }
        
        // if it has more than one element
        if (i.size() > 1) {
            // valid anyways
            cout << "YES" << ln;
            return;
        }
    }
    
    cout << "NO" << ln;
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
