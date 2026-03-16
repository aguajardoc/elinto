// Problem: B. White Magic
// Contest: Codeforces - Codeforces Round 1004 (Div. 1)
// URL: https://codeforces.com/contest/2066/problem/B
// Memory Limit: 256 MB
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

vector<int> suffmex(vector<int> a) {
	int n = a.size();
	vector<int> mex(n, 0);
	set<int> inc;
	int cur = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		inc.insert(a[i]);
		while (inc.count(cur)) {
			cur++;
		}
		mex[i] = cur;
	}
	
	return mex;
}

bool magical(vector<int> a) {
	int n = a.size();
	vector<int> mex = suffmex(a);
	int cm = a[0];
	
	for (int i = 1; i < n - 1; i++) {
		// dbg(i);
		// dbg(cm, mex[i]);
		if (cm < mex[i]) return false;
		cm = min(cm, a[i]);
	}
	
	return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> new_a;
    bool zinc = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i]) new_a.pb(a[i]);
    	else if (!zinc) {
    		zinc = 1;
    		new_a.pb(0);
    	}
    }
    
    int ans = new_a.size();
    
    if (!magical(new_a)) ans--;
    
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
