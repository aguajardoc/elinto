// Problem: C. Posterized
// Contest: Codeforces - Codeforces Round 480 (Div. 2)
// URL: https://codeforces.com/contest/980/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<int> groups(256, -1);
    
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (groups[x] == -1) {
    		int mn = x - k + 1;
    		mn = max(mn, 0ll);
    		int ele = -1;
    		int last = -1;
    		
    		bool poss = false;
    		for (int j = 0; j < x; j++) {
    			if (groups[j] == -1 or (j and groups[j] == groups[j-1])) {
    				continue;
    			}
    			
    			int diff = x - j + 1;
    			if (diff <= k) {
    				ele = groups[j];
    				last = j;
    				poss = true;
    				break;
    			}
    		}
    		
    		if (poss) {
    			for (int j = last; j <= x; j++) {
    				groups[j] = last;
    			}	
    		}
    		else {
	    		while (groups[mn] != -1) {
	    			mn++;
	    		}
				for (int j = 0; j < k; j++) {
					if (mn + j > x) break;
					groups[mn + j] = mn;
				}
			}
    	}
    	
    	// for (int j = 0; j < 15; j++) {
    		// cout << groups[j] << " ";
    	// }
    	
    	cout << groups[x] << " ";
    	// cout << ln;
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
