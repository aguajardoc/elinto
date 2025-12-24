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
 
    int start = (1ll << n) - 1;
    cout << start << " ";
    for (int free = 0; free <= (n - 2); free++) {
    	// clear those bits
    	start >>= 1;
    	// dbg(free);
    	// print all poss for that free bit
    	for (int i = 0; i < (1ll << free); i++) {
    		// dbg(i);
    		int cur = start;
    		for (int j = 0; j < free; j++) {
    			// dbg(i, j);
    			int x = (1ll << (n - free + j));
    			// dbg(x);
    			if (i & (1ll << (j))) {
					// dbg(cur);
    				cur |= x;
    				// dbg(cur)/;
    			}
    		}
    		cout << cur << " ";
    	}
    }
    
    for (int i = 0; i < (1ll << n); i+= 2) {
    	cout << i << " ";
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
