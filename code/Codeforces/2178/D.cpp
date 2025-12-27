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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> corr;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	corr[a[i]] = i;
    }
    sort(a.begin(), a.end());
    int FA = n / 2;
    int FR = FA - m;
    if (FR < 0) {
    	cout << -1 << ln;
    	return;
    }
    
    
    vector<pair<int, int>> moves;
    
    if (m == 0) {
    	int i = n - 2;
    	int ogb = a.back();
    	for (; i >= 0; i--) {
    		a.back() -= a[i];
    		if (a.back() <= 0) break;
    	}
    	
    	if (a.back() > 0) {
    		cout << -1 << ln;
    		return;
    	}
    	
    	for (int j = 1; j <= i; j++) {
    		moves.push_back({corr[a[j - 1]], corr[a[j]]});
    	}
    	
    	for (int j = n - 2; j >= i; j--) {
    		moves.push_back({corr[a[j]], corr[ogb]});
    	}
    	
    }
    else {
    	for (int i = 1; i <= FR; i++) {
    		moves.push_back({corr[a[i]], corr[a[i - 1]]});
    	}
    	
    	for (int i = FA; i < n; i++) {
    		moves.push_back({corr[a[i]], corr[a[FR + i - FA]]});
    	}
    }
    
    cout << moves.size() << ln;
    for (auto& [x, y] : moves) {
    	cout << x + 1 << " " << y + 1 << ln;
    }
    // cout << ln;
    
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
