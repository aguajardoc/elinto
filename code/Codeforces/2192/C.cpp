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
    int n, h, k;
    cin >> n >> h >> k;
    
    vector<pair<int, int>> a(n),b;
    set<int> banned;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    	sum += a[i].first;
    }
    b = a;
    sort(b.rbegin(), b.rend());
    
    int x = h / sum;
    h -= x * sum;
    int cost;
    if (h > 0) {
    	cost = x * k + x * n;
    }
    else cost = (x - 1) * k + x * n;
    
    
    if (h <= 0) {
    	cout << cost << ln;
    	return;
    }
    
    int cur = 0;
    int idx = 0;
    int mn = INF;
    for (int i = 0; i < n; i++) {
    	while (idx < n and b[idx].second <= i) idx++;
    	
    	mn = min(mn, a[i].first);
    	cur += a[i].first;
    	cost++;
    	
    	// get highest after me s.t.
    	// max - min >= h - cur
    	int x = b[idx].first;
    	int dL = x - mn;
    	int dR = h - cur;
    	
    	if (dL >= dR) {
    		cout << cost << ln;
    		return;
    	}
    	
    
    	
    	if (cur >= h) {
    		cout << cost << ln;
    		return;
    	}
    }
    
    // dbg(x, h);
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
