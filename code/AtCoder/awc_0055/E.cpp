// Problem: E - Mixing and Target Amount
// Contest: AtCoder - AtCoder Weekday Contest 0055 Beta
// URL: https://atcoder.jp/contests/awc0055/tasks/awc0055_e
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

vector<int> L, R;

void merge(vector<pair<int, int>>& modes, int n, bool mode) {
	int m = 1;
	for (int i = 0; i < n; i++) m *= 3; 
	
	for (int i = 0; i < m; i++) {
		int res = 0;
		
		int cur = i;
		int pow = m/3;
		for (int j = n-1; j >= 0; j--) {
			int t = 0;
			while (cur - pow >= 0) {
				t++;
				cur -= pow;
				// dbg(t, cur, pow);
			}
			pow /= 3;
			
			if (t == 1) {
				res += modes[j].first;
			}
			else if (t == 2) {
				res += modes[j].second;
			}
		}
		
		
		if (!mode) {
			L.pb(res);
		}
		else R.pb(res);
		
		// dbg(res);
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    L.reserve(16000000);
    R.reserve(16000000);
    
    vector<pair<int, int>> modes1, modes2;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	if (i < n/2) {
    		modes1.pb({x, y});
    	}
    	else modes2.pb({x, y});
    }
    
    int m1 = n / 2;
    int m2 = n - m1;
    
    merge(modes1, m1, 0);
    merge(modes2, m2, 1);
    
    bool poss = false;
    
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    
    L.resize(unique(L.begin(), L.end()) - L.begin());
    R.resize(unique(R.begin(), R.end()) - R.begin());
    
    
    if (binary_search(L.begin(), L.end(), k) or
    	binary_search(R.begin(), R.end(), k)
    ) poss = true;
    
    for (auto& i : L) {
    	int rem = k - i;
    	if (binary_search(R.begin(), R.end(), rem)) poss = true;
    }
    
    // Merge:
    // Check one, check the other
    // Or use all from left to target right
    
    cout << (poss ? "Yes":"No") << ln;
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
