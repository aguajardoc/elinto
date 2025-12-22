// Problem: C. Almost Equal
// Contest: Codeforces - Codeforces Round 580 (Div. 2)
// URL: https://codeforces.com/contest/1206/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
    	cout << "NO" << ln;
    	return;
    }
    
    vector<int> nums(2 * n);
    int cur = 2;
    for (int i = 0; i < n; i++) {
    	nums[i] = cur;
    	if (cur % 2) cur += 3;
    	else cur++;
    }
    
    for (int i = n; i < 2 * n; i++) {
    	if (nums[i - n] % 2) {
    		nums[i] = nums[i - n] + 1;
    	}
    	else nums[i] = nums[i - n] - 1;
    }
    
    cout << "YES" << ln;
    for (auto& i : nums) {
    	cout << i << " ";
    }
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
