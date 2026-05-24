// Problem: We Be Flipping (Easy Version)
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2229/problem/C1
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
    vector<int> ops;
    int LN = -1;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    
    vector<int> pos;
    int last = 0;
    
    for (int i = n - 1; i >= 0; i--) {
    	if (a[i] > 0 and last != 1) {
    		last = 1;
    		pos.pb(i);
    	}
    	else if (a[i] < 0 and last != -1) {
    		last = -1;
    		pos.pb(i);
    	}
    }
    
    // for (auto& i : pos) {
    	// cout << i << ln;
    // }
    sort(pos.begin(), pos.end());
    if (!pos.empty() and a[pos.back()] < 0) pos.pop_back();
    
    vector<int> neg, posi;
    for (auto& i : pos) {
    	if (a[i] < 0) neg.pb(i);
    	else posi.pb(i);
    }
    
    cout << pos.size() << ln;
    int idx = 0;
    for (int i = 0; i < posi.size(); i++) {
    	cout << posi[i]+1 << " ";
    	while (idx < neg.size() and neg[idx] < posi[i]) {
    		cout << neg[idx++]+1 << " ";
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
