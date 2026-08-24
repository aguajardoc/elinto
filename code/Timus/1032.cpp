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
    vector<pair<int, int>> a(n);
    for (auto& i : a) {
        cin >> i.first;
        i.second = i.first;
        i.first %= n;
    }

    sort(a.begin(), a.end());

    vector<int> ans;

    for (int i = 0; i < n and ans.empty(); i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j].first;
            if (sum % n == 0) {
                for (int k = i; k <= j; k++) {
                    ans.pb(a[k].second);
                }
                break;
            }
        }
    }

    cout << ans.size() << ln;
    for (auto& i : ans) {
        cout << i << ln;
    }

}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ 1032.cpp && ./a.out <input.in>output.out