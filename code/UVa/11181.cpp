// Problem: 11181 - Probability|Given
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2122
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
    int n, r;
    int c = 1;
    while (cin >> n >> r and (n or r)) {
    	vector<ld> p(n);
    	
    	for (auto& i : p) cin >> i;
    	
    	ld den = 0;
    	vector<ld> num(n, 0);
    	for (int i = 0; i < (1ll << n); i++) {
    		if (__builtin_popcountll(i) != r) continue;
    		ld prob = 1;
    		vector<int> active;
    		for (int j = 0; j < n; j++) {
    			if (i & (1ll << (j))) {
    				active.pb(j);
    				prob *= p[j];
    			}
    			else prob *= ((ld)1 - p[j]);
    		}
    			
    		if (active.size() == r) {
				den += prob;
    			for (auto& j : active) {
    				num[j] += prob;
    			}
    	    }
    	}
    	
    	cout << "Case " << c++ << ":\n";
    	for (int i = 0; i < n; i++) {
    		ld prob = num[i] / den;
    		cout << fixed << setprecision(6) << prob << ln;
    	} 
    	
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
