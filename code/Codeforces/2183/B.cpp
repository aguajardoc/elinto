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
    
    int mx = 0;
    vector<int> a(n);
    for (auto& i : a) {
    	cin >> i;
    }
    
    map<int, int> ct;
    set<int> cc;
    for (int i = 0; i <= n; i++) {
    	cc.insert(i);
    }
    for (int i = 0; i < k; i++) {
    	ct[a[i]]++;
    	cc.erase(a[i]);
    }
    
    mx = *cc.begin();
    
    for (int i = k; i < n; i++) {
    	// if (!--ct[a[i - k]]) {
    		// ct.erase(a[i - k]);
    		// cc.insert(a[i - k]);
    	// }
    	ct[a[i]]++;
    	cc.erase(a[i]);
    	
    	// dbg(a[i], a[i - k]);
    	
    	mx = max(mx, *cc.begin());
    }
    
    // dbg(mx);
    int ans = min(mx, k - 1);
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
