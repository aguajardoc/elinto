// Problem: Maximize XOR, Minimize Operations
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2260/problem/C
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

int brute(int x, int y) {
    for (int i = 0; x >= 0; x--, y++, i++) {
        if ((x ^ y) == (x + y)) {
           return i;
        }
    }
    
    return 0;
}

bool biton(int x, int bit) {
    return (x & (1ll << bit));
}

int optim(int x, int y) {
    int res = x + y;
    int moves = 0;
    
    for (int i = 30; i >= 0; i--) {
        if (!biton(res, i)) continue;
        
        if (!biton(x, i) and !biton(y, i)) {
            int var = (y | (1ll << i));
            for (int j = 0; j < i; j++) var &= ~(1ll << j);
            int diff = (var) - y;
            moves += diff;
            
            // dbg(i, diff);
            
            y += diff;
            x -= diff;
        }
    }
    
    return moves;
}

void solve() {
    int x, y;
    cin >> x >> y;
    
    // int bans = brute(x, y);
    int oans = optim(x, y);
    
    cout << x + y << " " << oans << ln;
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
