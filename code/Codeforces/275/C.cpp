// Problem: C. k-Multiple Free Set
// Contest: Codeforces - Codeforces Round 168 (Div. 2)
// URL: https://codeforces.com/contest/275/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> which(n, -1);
	int ans = 0;
	vector<int> bang(n);
	int ct = 0;
    for (int i = 0; i < n; i++) {
    	if (which[i] == -1) {
    		which[i] = ct++;
    	}
    	auto it = lower_bound(a.begin(), a.end(), a[i] * k);
    	if (it == a.end()) continue;
    	if (*it != a[i] * k) continue;
    	
    	int idx = distance(a.begin(), it);
    	which[idx] = which[i];
    }
    
    for (auto& i : which) {
    	bang[i]++;
    }
    
    for (auto& i : bang) {
    	ans += i / 2 + i % 2;
    }
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
