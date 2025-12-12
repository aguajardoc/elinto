// Problem: 10509 - R U Kidding Mr. Feynman?
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1450
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
vector<ll> cubes;

void solve() {
    string s;
    while (cin >> s and s != "0") {
    	ld n = stold(s);
    	ll a = distance(cubes.begin(), upper_bound(cubes.begin(), cubes.end(), floor(n))) - 1; 
    	ld dx = (n - (ld)(a*a*a)) / ((ld)3 * a * a);
    	
    	// dbg(n, a, dx);
    	
    	ld res = (ld)a + dx;
    	cout << fixed << setprecision(4) << res << ln;
    }
}

int main() {
    fast_cin();
    cubes = {0};
    for (ll i = 1; i <= 101; i++) {
    	cubes.push_back(i*i*i);
    }
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
