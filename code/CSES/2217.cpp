// Problem: Collecting Numbers II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2217
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> aloc(n), trans(n, 0), arr(n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        arr[i] = x;
        aloc[x] = i;
    }
    for (int i = 1; i < n; i++) {
        if (aloc[i-1] > aloc[i]) {
            trans[i-1] = 1;
            ans++;
        }
    }
    
    while (m--) {
        int a, b; cin >> a >> b; a--, b--;
        
        vector<int> nt;
        if (arr[a]-1 >= 0) nt.pb(arr[a]-1);
        if (arr[a] != n-1) nt.pb(arr[a]);
        if (arr[b]-1 >= 0) nt.pb(arr[b]-1);
        if (arr[b] != n-1) nt.pb(arr[b]);
        sort(nt.begin(), nt.end()); 
        nt.resize(unique(nt.begin(), nt.end()) - nt.begin());
        
        swap(aloc[arr[a]], aloc[arr[b]]);
        swap(arr[a], arr[b]);
        
        for (auto& t : nt) {
            int diff;
            if (aloc[t] > aloc[t+1]) {
                if (trans[t]) diff = 0;
                else diff = 1;
                
                trans[t] = 1;
            }
            else {
                if (trans[t]) diff = -1;
                else diff = 0;
                trans[t] = 0;
            }
            
            ans += diff;
        }
        
        cout << ans << ln;
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
