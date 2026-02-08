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
    int mx = 0;
    int s = 0;
    vector<int> a(n);
    for (auto& i : a){
    	cin >> i;
    	s += i;
    	mx = max(mx, i);
    }
    
    sort(a.begin(), a.end());
    
    vector<int> ans;
    for (int i = 1; i * i <= s; i++) {
    	if (s % i == 0) {
    		if (i >= mx) ans.pb(i);
    		if (i * i != s) {
    			if (s/i >= mx) ans.pb(s/i);
    		}
    	}
    }
    
    sort(ans.begin(), ans.end());
    
    for (auto& i : ans) {
    	bool poss = true;
    	
    	int l = 0, r = n - 1;
    	while (r >= 0 and a[r] == i) r--;
    	if (r == -1) {
    		cout << i << " ";
    		continue;
    	}
    	
    	if ((r - l) % 2 == 0) continue;
    	
    	while (l < r) {
    		if (a[l++] + a[r--] != i) poss = false;
    	}
    	if (poss) cout << i << " ";
    }
    cout << ln;
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
