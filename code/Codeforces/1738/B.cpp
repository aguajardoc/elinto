// Problem: B. Prefix Sum Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
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
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
    	cin >> s[i];
    }
    
    int mx = s[0] / (n - k + 1);
    vector<int> a(n);
    a[n - k] = s[0];
    for (int i = n - k + 1; i < n; i++) {
    	int idx = i - n + k;
    	a[i] = s[idx] - s[idx - 1];
    }
    
    for (int i = 0; i <= n - k; i++) {
    	a[i] = mx;
    }
    
    int surplus = abs(s[0]) % (n -k + 1);
    
    if (s[0] < 0) {
    	for (int i = 0; i < surplus; i++) {
    		a[i]--;
    	}
    }
    else {
    	for (int i = n - k; i > n - k - surplus; i--) {
    		a[i]++;
    	}
    }
    
    bool poss = true;
    for (int i = 1; i < n; i++) {
    	if (a[i] < a[i-1]) poss = false;
    }
    cout << (poss ? "YES":"NO") << ln;
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