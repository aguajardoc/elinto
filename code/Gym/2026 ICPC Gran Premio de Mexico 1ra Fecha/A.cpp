// Problem: A. Anxiety at the restaurant
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, m;
    cin >> n >> m;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	s1+=x;
    }
    
    for (int i = 0; i < m; i++) {
    	int x;
    	cin >> x;
    	s2+=x;
    }
    s1 *= 11;
    s2 *= 10;
    
    cout << (s2 >= s1 ? "YES":"NO") << ln;
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
