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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> p(n + 1, 0), sec(n + 1, 0);
    for (int i = 0; i < n ; i++) {
    	int x = a[i];
    	if (i == 0) x = a[i];
    	else if (i == n - 1) x = -a[i];
    	else x = max(a[i], -a[i]);
    	// dbg(x);
    	p[i + 1] = p[i] + x;
    	sec[i + 1] = sec[i] - a[i];
    }
    
    int ans = -1e17;
    // exclude each element
    for (int i = 0; i < n; i++) {
    	int sum = p[i] - p[0];
    	sum += sec[n] - sec[i + 1];
    	ans = max(ans, sum);
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
