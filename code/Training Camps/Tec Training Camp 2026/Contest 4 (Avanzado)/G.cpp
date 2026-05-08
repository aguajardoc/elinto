// Problem: G. Everything Nim
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/G
// Memory Limit: 256 MB
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    
    if (n == 1 or a[0] != 1) {
    	cout << "Alice" << ln;
    	return;
    }
    
    int idx;
    for (idx=0; idx < n; idx++) {
    	if (a[idx] != idx + 1) break;
    }
    
    int turn = idx % 2;
    if (idx == n) {
    	if (turn) cout << "Alice" << ln;
    	else cout << "Bob" << ln;
    	return;
    }
    else {
    	if (!turn) cout << "Alice" << ln;
    	else cout << "Bob" << ln;
    	return;
    }
    
    
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
