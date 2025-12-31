// Problem: C. Terse princess
// Contest: Codeforces - Codeforces Round 105 (Div. 2)
// URL: https://codeforces.com/contest/148/problem/C
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
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1 and (a or b)) {
    	cout << -1 << ln;
    	return;
    }
    if ((a and not b) and n - a == 1) {
    	cout << -1 << ln;
    	return;
    }
    
    int base = 1;
    
    
    vector<int> ans(n, base);
    if (b == 0) {
    	for (int i = 2; i < a + 2; i++) {
    		ans[i] = i;
    	}
    	for (auto& i : ans) {
	    	cout << i << " ";
	    }
	    cout << ln;
	    return;
    }
    
    
    int idx = 1;
    while (idx < n and b) {
    	ans[idx] = (base << idx);
    	b--;
    	idx++;
    }
    
    int stay = (base << (idx - 1));
    int k = 1;
    while (idx < n and a) {
    	ans[idx] = (stay + k++);
    	idx++;
    	a--;
    }
    
    while (idx < n) {
    	ans[idx] = 1;
    	idx++;
    }
    
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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
