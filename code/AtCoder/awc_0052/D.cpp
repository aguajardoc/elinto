// Problem: D - Virus Testing and Infected Terminals
// Contest: AtCoder - AtCoder Weekday Contest 0052 Beta
// URL: https://atcoder.jp/contests/awc0052/tasks/awc0052_d
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

struct Infection {
	vector<int> targ;
	int r;
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    int ans = INF;
    vector<Infection> a(m);
    for (int i = 0;i < m; i++) {
    	int k;
    	cin >> k;
    	a[i].targ.assign(k, 0);
    	for (int j = 0; j < k; j++) {
    		cin >> a[i].targ[j];
    		a[i].targ[j]--;
    	}
    	int r;
    	cin >> r;
    	a[i].r = r;
    }
    
    for (int i = 0; i < (1ll << n); i++) {
    	
    	bool poss = true;
    	for (int j = 0; j < m; j++) {
    		bool possLocal = false;
    		for (auto& k : a[j].targ) {
    			if (i & (1ll << k)) {
					if (!a[j].r) poss = false;
					else possLocal = true;
    			}
    		}
    		
    		if (a[j].r and !possLocal) poss = false;
    	}
    	
    	if (poss) {
    		ans = min(ans, (ll)__builtin_popcountll(i));
    	}
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
