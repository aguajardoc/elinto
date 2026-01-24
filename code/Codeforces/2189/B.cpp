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
    int n, x;
    cin >> n >> x;
    
    int extraUnits = 0;
    int bestPR = 0;
    int ba, bb, bc;
    for (int i = 0; i < n; i++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	
    	int jpr = a * (b - 1) + a - c;
    	int tk = a * (b - 1);
    	extraUnits += tk;
    	
    	if (jpr > bestPR) {
    		ba = a;
    		bb = b;
    		bc = c;
    		bestPR = jpr;
    	}
    }
    
    if (bestPR == 0) {
    	if (extraUnits < x) {
    		cout << -1 << ln;
    	}
    	else cout << 0 << ln;
    	return;
    }
    
    if (extraUnits >= x) {
    	cout << 0 << ln;
    	return;
    }
    
    // consume rollback
    int cur = extraUnits;
    
    // dbg(cur, bestPR);
    
    int d = x - cur;
    // dbg(d);
    
    int rem = d / bestPR + min(1ll, d % bestPR);
    
    cur += bestPR * rem;
    // cur += ba * (bb - 1);
    
    // dbg(cur, x);
    // if (cur < x) rem++;
    
    cout << rem << ln;
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
