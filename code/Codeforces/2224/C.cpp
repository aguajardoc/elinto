// Problem: Zhily and Bracket Swapping
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2224/problem/C
// Memory Limit: 512 MB
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

#define open '('
#define closed ')'

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    int curOpen = 0, curClosed = 0;
    bool poss = true;
    
    if (a[0] == closed or b[0] == closed) poss = false;
    if (a.back() == open or b.back() == open) poss = false;
    
    for (int i = 0; i < n; i++) {
    	curOpen += (a[i] == open) + (b[i] == open);
    	curClosed += (a[i] == closed) + (b[i] == closed);
    	
    	if (!(i % 2) and curClosed > curOpen - 2) poss = false;
    	else if ((i % 2) and curClosed > curOpen) poss = false;
    }
    
    if (curOpen != curClosed) poss = false;
    
    cout << (poss ? "YES":"NO") << ln;
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
