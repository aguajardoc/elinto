// Problem: B. Forcefield
// Contest: Codeforces - 2015-2016 Petrozavodsk Winter Training Camp, Nizhny Novgorod SU Contest
// URL: https://codeforces.com/gym/100960/problem/B
// Memory Limit: 256 MB
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
    int n, x;
    cin >> n >> x;
    
    multiset<int> luke, tube;
    for (int i = 0; i < n; i++) {
        int pos, t;
        cin >> pos >> t;
        if (t) {
            luke.insert(pos);
        }
        else {
            tube.insert(pos);
        }
    }
    
    
    int cur = x;
    int dir = 0;
    int ans = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        
        if (!dir) {
            // check if any before me go toward tube
            auto it = tube.lower_bound(cur);
            if (it == tube.begin()) {
                // we hit luke
                ans++;
                cur = 0;
                dir = 1;
                flag = true;
                continue;
            }
            
            it--;
            cur = *it;
            dir = 1;
            flag = true;
            tube.erase(it);
        }
        else {
            // check if any after me go toward luke
            auto it = luke.lower_bound(cur);
            
            if (it == luke.end()) {
                // nothing we can do :(
                continue;
            }
            
            cur = *it;
            dir = 0;
            flag = true;
            luke.erase(it);
        }
    }
    
    if (tube.empty() and luke.empty()) {
        cout << ans << ln;
    }
    else cout << -1 << ln;
    
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
