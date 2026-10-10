// Problem: D. Domain Expansion Abraham échate un hint
// Contest: Codeforces - 2026 XVIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106722/problem/D
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

bool query(int i, int k) {
    cout << "? " << i << " " << k << endl;
    string x; cin >> x;
    return (x == "Yes");
}

void answer(vector<int>& ans) {
    cout << "! " << ans.size() << " ";
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

void solve() {
    int n; cin >> n;
    
    int cur = n;
    int best = n;
    for (int i = 1; i <= n; i++) {
        while(cur and query(i, cur)) {
            best = cur;
            cur--;
        }
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (query(i, best)) {
            ans.pb(i);
        }
    }
    
    answer(ans);
 }

signed main() {
    // fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
