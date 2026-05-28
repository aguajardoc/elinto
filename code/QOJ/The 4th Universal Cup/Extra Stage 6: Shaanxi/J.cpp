// Problem: J. Would You Make a Convex?
// Contest: Universal Cup - The 4th Universal Cup. Extra Stage 6: Shaanxi
// URL: https://contest.ucup.ac/contest/3766/problem/17351
// Memory Limit: 1024 MB
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
    	int c = a[i] + a[i + 1];
    	
    	auto it = lower_bound(a.begin(), a.end(), c);
    	
    	int val = (it - a.begin()) - i;
    	if (val >= 3) res = max(res, val);
    }
    
    cout << res;
    
    for (int i = 0; i < n - 1; i++) {
    	int c = a[i] + a[i + 1];
    	
    	auto it = lower_bound(a.begin(), a.end(), c);
    	
    	int val = (it - a.begin()) - i;
    	
    	if (val == res) {
    		for (int j = i; j < i + val; j++) {
    			cout << " " << a[j];
    		}
    		cout << ln;
    		return;
    	}
    }
    
    cout << ln;
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
