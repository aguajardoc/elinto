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

vector<int> a, flips;
vector<vector<int>> dp;


int recurse(int idx, int flipped) {
    if (idx == -1) return 0;

    if (dp[idx][flipped] != INF) return dp[idx][flipped];

    // If cannot be flip dont bother
    int res = -INF;
    int val = a[idx];
    if (flipped) val *= -1;
    if (!flips[idx]) {
        res = max(res, recurse(idx - 1, flipped) + val);
    }
    else {
        // Try both
        // int aa = recurse(idx - 1, flipped) + val;
        // int bb = recurse(idx - 1, 1 - flipped) + val;
        // dbg(idx, aa, bb);
        res = max({res,
            recurse(idx - 1, flipped) + val,
            recurse(idx - 1, 1 - flipped) - val
        });
    }

    // dbg(idx, flipped, res);
    // dbg(a[idx]);

    return dp[idx][flipped] = res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    a.assign(n, 0);
    flips.assign(n, 0);
    for (auto& i : a) cin >> i;

    for (int i = 0; i < k; i++) {
        int x; cin >> x; flips[x-1] = 1;
    }

    dp.assign(n, vector<int> (2, INF));

    cout << recurse(n - 1, 0) << ln;
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
// g++ D.cpp && ./a.out <input.in>output.out