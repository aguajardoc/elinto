// Problem: A - ADjacent
// Contest: AtCoder - AtCoder Beginner Contest 480
// URL: https://atcoder.jp/contests/abc480/tasks/abc480_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
    string s, t; cin >> s >> t;
    if (s[0] == 'A' and s[1] == 'D') cout << "Yes";
    else if (s[0] == 'D' and s[1] == 'A') cout << "Yes";
    else if (s[0] == 'A' and t[0] == 'D') cout << "Yes";
    else if (s[0] == 'D' and t[0] == 'A') cout << "Yes";
    else if (t[0] == 'D' and t[1] == 'A') cout << "Yes";
    else if (t[0] == 'A' and t[1] == 'D') cout << "Yes";
    else if (s[1] == 'A' and t[1] == 'D') cout << "Yes";
    else if (s[1] == 'D' and t[1] == 'A') cout << "Yes";
    else cout << "No" << ln;
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
