// Problem: Zhily and Mex and Max
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2224/problem/B
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

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> nums;
   	for (int i = 0; i < n; i++){
   		int x;
   		cin >> x;
   		nums[x]++;
   	}
   	
   	// if max is 1, and there's a 0, do it
   	if (nums.rbegin()->first == 1 and nums.count(0)) {
   		a.pb(0);
   		a.pb(1);
   		nums[0]--;
   		nums[1]--;
   	}
   	else {
   		a.pb(nums.rbegin()->first);
   		nums[nums.rbegin()->first]--;
   	}
   	
   	for (auto& i : nums) {
   		if (i.second) {
   			a.pb(i.first);
   			i.second--;
   		}
   	}
   	for (auto& i : nums) {
   		while (i.second) {
   			a.pb(i.first);
   			i.second--;
   		}
   	}
   	
    int ans = 0;
    int maax = 0;
    int meex = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] == meex) meex++;
    	maax = max(maax, a[i]);
    	
    	if (maax == meex) meex++;
    	
    	// dbg(maax, meex);
    	
    	ans += maax + meex;
    }
    cout << ans << ln;
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
