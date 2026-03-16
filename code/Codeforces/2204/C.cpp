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
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    
    int A = 6 * (m/a), B = 6 * (m/b), C = 6 * (m/c);
    
    int LAB = lcm(a, b);
    int LAC = lcm(a, c);
    int LBC = lcm(b, c);
    int LABC = lcm(LAB, c);
    
    // dbg(a, b, c);
    // dbg(LAB, LAC, LBC);
    // dbg(LABC);
    
    A -= 3 * (m / (lcm(a, b)));
    A -= 3 * (m / (lcm(a, c)));
    B -= 3 * (m / (lcm(a, b)));
    B -= 3 * (m / (lcm(b, c)));
    C -= 3 * (m / (lcm(a, c)));
    C -= 3 * (m / (lcm(b, c)));
    
    A += 2 * (m / (lcm(a, lcm(b, c))));
    B += 2 * (m / (lcm(a, lcm(b, c))));
    C += 2 * (m / (lcm(a, lcm(b, c))));
    
    cout << A << " " << B << " " << C << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
