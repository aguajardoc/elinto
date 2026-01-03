// Problem: C. DNA Alignment
// Contest: Codeforces - Codeforces Round 295 (Div. 2)
// URL: https://codeforces.com/contest/520/problem/C
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

map<char, int> c = {{'A', 0},
                    {'C', 1},
                    {'G', 2},
                    {'T', 3}};
                    
map<vector<int>, int> ct;

int calculate(vector<int>& a, vector<int>& b) {
	int res = 0;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[(i + j) % n]) res++;
		}
	}
	
	return res;
}

void brute(vector<int>& a, int idx, vector<int>& x) {
	if (idx == a.size()) {
		ct[x] = calculate(a, x);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		x.pb(i);
		brute(a, idx + 1, x);
		x.pop_back();
	}
}										

int brute(string s) {
	vector<int> a;
	ct.clear();
	for (auto& i : s) {
		a.pb(c[i]);
	}
	vector<int> x;
	int idx = 0;
	brute(a, idx, x);
	
	int mx = 0;
	for (auto& i : ct) {
		mx = max(mx, i.second);
	}
	
	int res = 0;
	for (auto& i : ct) {
		if (i.second == mx) {
			res++;
			// for (auto& j : i.first) {
				// cout << j;
			// }
			// cout << ln;
		}
	}
	
	return res;
}

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b& 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    map<int, int> lc;
    for (auto& i : s) {
    	lc[i]++;
    }
    
    vector<int> cts;
    for (auto& i : lc) {
    	cts.pb(i.second);
    }
    sort(cts.rbegin(), cts.rend());
    while (cts.size() < 4) cts.pb(0);
    ll ans = 1;
    
    if (cts[0] == cts[1] and cts[0] == cts[2] and cts[0] == cts[3]){
    	ans = binexp(4, 4 * cts[3]);
    }
    else if (cts[0] == cts[1] and cts[0] == cts[2]){
    	ans = binexp(3, 3 * cts[2] + cts[3]);
    }
    else if (cts[0] == cts[1]){
    	ans = binexp(2, 2 * cts[1] + cts[2] + cts[3]);
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
