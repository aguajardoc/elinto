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
    string s;
    cin >> s;
    int R = 0, B = 0;
    int rn = 2*n;
    for (int i = 0; i < rn; i++) {
        int next = (i + 1) % rn;
        if (s[i] == '1' and s[next] == '0') {
            if (i % 2 == 0) B++;
            else R++;
            i++;
        }
        else if (s[i] == '1' and s[next] == '1') {
            if (i % 2 == 0) R++;
            else B++;
        }

        // dbg(i, R, B);
    }

    cout << B << " " << R << ln;
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
// g++ C.cpp && ./a.out <input.in>output.out