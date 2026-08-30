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
    // maximize number of carrots size k
    // For an x;
    // We cant do anything to those before us
    // so just count at x
    // all others can add one to count
    // or 2 if l == 2x -> readd ct[2x]

    // just try every k
    int n, m;
    cin >> n >> m;
    vector<int> ct(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; ct[x]++;
    }

    int ans = 0;
    int rest = n;
    int cur = 0;
    for (int x = 1; x <= m; x++) {
        cur += ct[x];
        rest -= ct[x];

        int result = ct[x] + rest;
        if (2 * x <= m) result += ct[2*x];

        ans = max(ans, result);
    }

    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ B.cpp && ./a.out <input.in>output.out