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
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> hold(n, 0);
    vector<vector<int>> miss(n, vector<int> (n, 0)), holding = miss;
    
    for (int i = 0; i < n; i++) {
    	hold[i] = h - a[i];
    	holding[i][i] = h - a[i];
    	int mx = a[i];
    	for (int j = i - 1; j >= 0; j--) {
    		mx = max(mx, a[j]);
    		hold[i] += h - mx;
    		holding[i][j] = h - mx;
    		miss[i][j] += mx - a[j];
    	}
    	
    	mx = a[i];
    	for (int j = i + 1; j < n; j++) {
    		mx = max(mx, a[j]);
    		hold[i] += h - mx;
    		holding[i][j] = h - mx;
    		miss[i][j] += mx - a[j];
    	}
    }
    int ans = *max_element(hold.begin(), hold.end());
    int idxb = distance(hold.begin(), max_element(hold.begin(), hold.end()));
    
	for (int j = 0; j < n; j++) {
		int r = 0;
		for (int k = 0; k < n; k++) {
			r += max(holding[idxb][k], holding[j][k]);
		}
		ans = max(ans, r);
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
