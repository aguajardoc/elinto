// Problem: D. Sea Battle
// Contest: Codeforces - Technocup 2017 - Elimination Round 2
// URL: https://codeforces.com/contest/729/problem/D
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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    
    vector<int> oloc;
    string s;
    cin >> s;
    oloc.pb(-1);
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') oloc.pb(i);
    }
    oloc.pb(n);
    
    vector<int> magic;
    for (int i = 0; i < (int)oloc.size() - 1; i++) {
    	int start = oloc[i];
    	int end = oloc[i + 1];
    	
    	for (int j = start + b; j < end; j += b) {
    		magic.pb(j);
    	}
    }
    
    int x = magic.size();
    x = x - a + 1;
    x = max(x, 1ll);
    cout << x << ln;
    for (int i = 0; i < x; i++) {
    	cout << magic[i] + 1 << " ";
    }
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
