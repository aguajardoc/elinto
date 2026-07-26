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
    
    // If even, must be same count
    // 000111
    // 010101 -> k = 0
    // 010110 -> k = 1
    // 001011 -> k = 2
    // 001110 -> k = 3
    // 

    if (n - k < 2) {
        cout << -1 << ln;
        return;
    }

    string s;
    int z = 0, o = 0;

    if (
        (k % 2 == 0)
    ) {
        // 010101010
        for (int i = 0; i < n; i++) {
            if (i % 2) s += '1';
            else s += '0';
        }

        o = 1, z = 2;
    }
    else if (n % 2) {
        // 00 1010101
        s = "00";
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) s += '1';
            else s += '0';
        }

        // dbg(s);
        o = 2, z = 3;
    }
    else {
        // 100 1010
        s = "100";
        for (int i = 3; i < n; i++) {
            if (i % 2) s += '1';
            else s += '0';
        }

        // dbg(s);
        o = 3, z = 1;
    }

    for (int i = 0; i < k/2; i++) {
        swap(s[o], s[z]);
        if (i == k/2 -1) continue;

        while (o < n and s[o] == '0') o++;
        while (z < n and s[z] == '1') z++;
    }

    cout << s << ln;
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