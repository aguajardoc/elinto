// Problem: Kompići
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/KOMPICI/
// Memory Limit: 1536 MB
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
    int ct1[1024], ct2[1024];
    for (auto& i : ct1) i = 0;
    for (auto& i : ct2) i = 0;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	int mask = 0;
    	for (auto& j : s) {
    		mask |= (1ll << (j - '0'));
    	}
    	
    	ct1[mask]++;
    }
    
    for (int j = 1; j < (1ll << 10); j++) {
		for (int i = 1; i < (1ll << 10); i++) {
			if ((i & j) == j) {
				ct2[j] += ct1[i];
			}
		}
	}
    
    // i guess?
    int ans = 0;
    for (int i = 1; i < 1024; i++) {
    	int x = __builtin_popcount(i);
    	int y = ct2[i];
    	
    	// if (ct[i])dbg(i, ct[i]);
    	
    	if (x % 2) {
    		ans += (y * (y - 1)) / 2;
    	}
    	else ans -= (y * (y - 1)) / 2;
    }
    
    cout << ans << ln;
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
