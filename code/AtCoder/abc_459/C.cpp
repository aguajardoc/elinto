// Problem: C - Drop Blocks
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2026  (AtCoder Beginner Contest 459)
// URL: https://atcoder.jp/contests/abc459/tasks/abc459_c
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
    map<int, int> ct;
    int n, q;
    cin >> n >> q;
    ct[0] = n;
    vector<int> blocks(n), thresh(2 * (q + n));
    thresh[0] = n;
    int aff = 0;
    
    while(q--) {
    	int type, x;
    	cin >> type >> x;
    	if (type == 1) {
    		x--;
    		int rb = blocks[x];
    		ct[rb]--;
    		ct[rb+1]++;
    		blocks[x]++;
    		thresh[rb+1]++;
    		
    		if (ct[aff] == 0) {
    			aff++;
    		}
    	} 
    	else {
    		x += aff;
    		// dbg(x, aff);
    		cout << thresh[x] << ln;
    	}
//     	
    	// for (auto& i : ct) {
    		// dbg(i.first);
    		// dbg(i.second);
    		// cout << ln;
    	// }
    	// cout << ln;
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
