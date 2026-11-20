// Problem: Distinct Values Sum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3150
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
    int n; cin >> n;
    vector<int> a(n); for (auto& i : a) cin >> i;
    map<int, vector<int>> nxt;
    for (int i = 0; i < n; i++) {
    	nxt[a[i]].pb(i);
    }
    for (auto& i : nxt) i.second.pb(n);
    
    int ans = 0, sum = 0;
    set<int> cur;
    for (int i = 0; i < n; i++) {
    	cur.insert(a[i]);
    	sum += cur.size();
    }
    
    ans += sum;
    for (int i = 0; i < n; i++) {
    	int d = *upper_bound(nxt[a[i]].begin(), nxt[a[i]].end(), i) - *lower_bound(nxt[a[i]].begin(), nxt[a[i]].end(), i);
    	sum -= d;
    	ans += sum;
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
