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

// 11112222
// 1441 (2) -> 4

// 11212212
// 211211 -> 121212 (6)

// 1122
// 1212

// 112

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.pb(x);
    }

   vector<int> changes;
   vector<vector<int>> changes2(n + 1);
   int cur = a[0];
   int times = 0;
   for (int i = 0; i < n; i++) {
    if (cur != a[i]) {
        changes.pb(times);
        times = 1;
        cur = a[i];
    }
    else times++;
   }

   changes.pb(times);
   int idx = 0;
//    for (auto& i : changes) {
//     cout << i << " ";
//    }
//    cout << ln;

   int ans = changes.size();
   bool flag = false;
   for (int i = 0; i < (int)changes.size() - 1; i++) {
    if (changes[i] >= 2 and changes[i+1] >= 2) {
        ans+=2;
        flag = true;
        break;
    }
   }

   if (flag) {
    cout << ans << ln;
    return;
   }

   // add one if
   // Left is same, right and two right are not
   // Right is same, left and two left are not
   for (int i = 0; i < n; i++) {
    if (i > 0 and i < n - 2) {
        if (a[i] == a[i-1] and a[i] != a[i+1] and a[i] != a[i+2]) {
            ans++;
            break;
        }
    }
    if (i > 0 and i == n - 2) {
        if (a[i] == a[i-1] and a[i] != a[i+1]) {
            ans++;
            break;
        }
    }
    if (i > 1 and i < n - 1) {
        if (a[i] == a[i+1] and a[i] != a[i-1] and a[i] != a[i-2]) {
            ans++;
            break;
        }
    }
    if (i == 1 and i < n - 1) {
        if (a[i] == a[i+1] and a[i] != a[i-1]) {
            ans++;
            break;
        }
    }
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