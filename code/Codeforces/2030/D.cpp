// Problem: D. QED's Favorite Permutation
// Contest: Codeforces - Codeforces Round 979 (Div. 2)
// URL: https://codeforces.com/contest/2030/problem/D
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) {
    	cin >> i;
    	i--;
    }
    
    string s;
    cin >> s;
    vector<int> d(n, 0), nd(n-1), LR(n, 0), RL(n, 0);
    int mx = 0, mn = INF;
    for (int i = 0; i < n; i++) {
    	mx = max(mx, a[i]);
    	if (mx != i) {
    		LR[i] = 1;
    	}
    }
	for (int i = n - 1; i >= 0; i--) {
		mn = min(mn, a[i]);
		if (mn != i) {
			RL[i] = 1;
		}
	}
	for (int i = 0; i < n-1; i++) {
		if (LR[i] and RL[i+1]) {
		}
	}
	
	// vector<int>pref(n,0);
	// for (int i = 0; i < n - 1; i++) {
		// pref[i+1] = pref[i] + nd[i];
	// }
    
    // for (auto& i : LR) {
    	// cout << i << " ";
    // }
    // cout << ln;
    // for (auto& i : RL) {
    	// cout << i << " ";
    // }
    // cout << ln;
    // for (auto& i : d) {
    	// cout << i << " ";
    // }
    // cout << ln;
    
    // have a set of the inflictions
    set<int> inflict;
    for (int i = 0; i < n-1; i++) {
    	if (s.substr(i, 2) == "LR" and LR[i] and RL[i+1]) {
    		inflict.insert(i);
    	}
    }
    
    // for (auto& i : inflict) {
    	// cout << i << " ";
    // }
    // cout << ln;
    
    while (q--) {
    	int i;
    	cin >> i;
    	i--;
    	
    	if (s[i] == 'R') {
    		if (inflict.count(i-1)) {
    			inflict.erase(i-1);
    		}
    		s[i] = 'L';
    		if (i < n - 1 and s[i+1] == 'R' and LR[i] and RL[i+1]) {
    			inflict.insert(i);
    		}
    	}
    	else {
    		if (inflict.count(i)) {
    			inflict.erase(i);
    		}
    		s[i] = 'R';
    		
    		if (i and s[i-1] == 'L' and LR[i-1] and RL[i]) {
    			inflict.insert(i-1);
    		}
    	}
    	// dbg(s);
    	
    	if (!inflict.empty()) {
    		cout << "NO" << ln;
    	}
    	else cout << "YES" << ln;
    	
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
