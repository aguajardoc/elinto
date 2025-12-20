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
vector<vector<vector<ll>>> dp;
ll n, k;

int recurse(int idx, int onbits, int prev) {
	if (idx == 30) {
		return 0;
	}
	
	if (dp[idx][onbits][prev] != -1) return dp[idx][onbits][prev];
	
	int res = 0;
	int np = prev;
	for (int i = ((1ll << idx) & (n)); i <= k; i += 2) {
		if (((1ll << idx) & (n))) np = i;
		else if (i > prev) break;
		res = max(res, recurse(idx + 1, i, np) + (1ll << idx) * i);
	}
	
	return dp[idx][onbits][prev];
} 

void solve() {
    cin >> n >> k;
    if (k % 2) {
    	cout << n << " ";
    	k--;
    	while (k--) {
	    	cout << n << " ";
	    }
	    cout << ln;
    }
    else {
    	int ans = 0;
    	int r = 0;
    	int put = 0;
    	vector<int> res(k, 0), prevon(k, 0);
    	for (int i = 31; i >= 0; i--) {
    		if ((1 << i) & (n)) {
    			for (int j = put; j < k - 1 + put; j++) {
    				res[j % k] |= (1ll << i);
    			}
    			prevon[(k - 1 + put) % k] = 1;
    			put++;
    		}
    		else {
    			r = put;
    			if (r % 2) r--;
				// find any whose prevon is on
				for (int l = 0; l < k and r; l++) {
					if (prevon[l]) {
						res[l] |= (1ll << i);
						r--;
					}
				}
    			
    		}
    		
    		// dbg(i);
    		// for (auto& i : res) {
				// cout << i << " ";
				// ans += i;
			// }
    	}
    	
    	for (auto& i : res) {
    		cout << i << " ";
    		ans += i;
    	}
    	// dbg(ans);
    	cout << ln;
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
