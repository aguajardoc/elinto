// Problem: Sherlock and Probability
// Contest: HackerRank - Mathematics - Probability
// URL: https://www.hackerrank.com/challenges/sherlock-and-probability/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll r = 0;
    ll total = 0;
    for (ll i =0 ; i < n; i++) total += (s[i] == '1');
    for (ll i = 0; i < k; i++) {
    	if (s[i] == '1')r++;
    }
    
    ll ans = -total;
    for (ll i = 0; i < n; i++) {
    	if (i and s[i-1] == '1')r--;
    	if (i + k < n and s[i+k] == '1')r++;
    	if (s[i] == '1') ans += 2 * r;
    	// dbg(ans, r, i);
    }
    ll q = n * n;
    ll hcf = gcd(ans, q);
    ans /= hcf;
    q /= hcf;
    cout << ans << "/" << q << ln;
}

int main() {
    fast_cin();
    
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
