// Problem: A - Add and Swap
// Contest: AtCoder - AtCoder Regular Contest 187
// URL: https://atcoder.jp/contests/arc187/tasks/arc187_a
// Memory Limit: 1024 MB
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
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& i : a) cin >> i;
    vector<int> ops;
    
    for (int i = 1; i < n - 2; i++) {
    	while (a[i] < a[i-1]) {
    		swap(a[i], a[i+1]);
    		a[i] += k;
    		ops.pb(i+1);
    	}
    }
    int j = n - 3, l = n-2;

    bool poss = false;
    for (int i = 0; i < 1000 and j >= 0 and !poss; i++) {    
		swap(a[j], a[l]);
		a[j] += k;
		ops.pb(j+1);
		
		if (a[l] >= a[j] and i > 967) poss = true;
	}
	
	poss = false;
	j++, l++;
	int p = n - 3;
	if (p == -1) p++;
    for (int i = 0; i < 300000 and !poss; i++) {    
		swap(a[j], a[l]);
		a[j] += k;
		ops.pb(j+1);
		
		if (a[l] >= a[j] and a[j] >= a[p]) poss = true;
	}
	
	// for (auto& i : a) {
		// cout << i << " ";
	// }
	// cout << ln;
	if (!poss) {
		cout << "No" << ln;
		return;
	}
    
    cout << "Yes" << ln;
    cout << ops.size() << ln;
    for (auto& i : ops) {
    	cout << i << " ";
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
