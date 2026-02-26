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

int lsb(int x) {
	for (int i = 0; i <= __lg(x); i++) {
		if (x & (1ll << i)) return i;
	}
	return __lg(x);
}

int check(int n, int m, int s) {
	int x = 0;
	
	for (int i = __lg(m); i >= 0; i--) {
		int p = (1ll << i);
		if (not(m & p)) continue;
		int allowed = (s - x) / p;
		allowed = min(allowed, n);
		
		x += p * allowed;
	}
	
	return x;
}

void solve() {
    //(998244353)10 = (111011100000000000000000000001)2
    //(1557287)10 = (           101111100001100100111)2
    
    int s, m;
    cin >> s >> m;
    
    // Get LSB of both
    int lsbs = lsb(s);
    int lsbm = lsb(m);
    
    if (lsbs < lsbm) {
    	cout << -1 << ln;
    	return;
    }
    
    int ans = INF;
    int l = 0, r = INF;
    while (l <= r) {
    	int MID = (l + r) / 2;
    	
    	int fm = check(MID, m, s);
    	
    	
    	if (fm == s) {
    		ans = min(ans, MID);
    		r = MID - 1;
    	}
    	else l = MID + 1;
    }
    
    cout << ans << ln;
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
