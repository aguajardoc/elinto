// Problem: D. Array Division
// Contest: Codeforces - Educational Codeforces Round 21
// URL: https://codeforces.com/contest/808/problem/D
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

bool check(vector<int>a, int n, int sum) {
	set<int> exists;
	int target = sum/2;
	for (int i = n - 1; i >= 0; i--) {
		sum -= a[i];
		// dbg(i);
		// dbg(sum, target);
		// dbg(target - sum);
		if ((target - sum == 0) or exists.count(target - sum)) return true;
		
		exists.insert(a[i]);
	}
	return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    int sum = 0;
    for (auto& i : a) {
    	cin >> i;
    	sum += i;
    }
    
    
    if (sum % 2 or n < 2) {
    	cout << "NO" << ln;
    	return;
    }
    
    bool res = false;
    
    res |= check(a, n, sum);
    reverse(a.begin(), a.end());
    res |= check(a, n, sum);
    
    cout << (res ? "YES":"NO") << ln;
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
