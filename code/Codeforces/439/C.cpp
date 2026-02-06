// Problem: C. Devu and Partitioning of the Array
// Contest: Codeforces - Codeforces Round 251 (Div. 2)
// URL: https://codeforces.com/contest/439/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    
    vector<int> odds, evens;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (x%2) odds.pb(x);
    	else evens.pb(x);
    }
    
    // mix of both
    if ((int)evens.size() + (int)odds.size()/2 < p) {
    	cout << "NO" << ln;
    	return;
    }
    
    vector<vector<int>> a(k);
    	
	bool poss = true;
	for (int i = 0; i < p; i++) {
		if (!evens.empty()) {
			a[i].pb(evens.back());
			evens.pop_back();
		}
		else if (!odds.empty()) {
			a[i].pb(odds.back());
			odds.pop_back();
			a[i].pb(odds.back());
			odds.pop_back();
		}
		else poss = false;
	}
	
	int X = k - p;
	
	if (odds.size() < X)  {
		cout << "NO" << ln;
		return;
	}
	
	
	for (int i = p; i < k; i++) {
		a[i].pb(odds.back());
		odds.pop_back();
	}
	
	if (odds.size() % 2) {
		cout << "NO" << ln;
		return;
	}
	
	while (!odds.empty()) {
		a[0].pb(odds.back());
		odds.pop_back();
	}
	
	while (!evens.empty()) {
		a[0].pb(evens.back());
		evens.pop_back();
	}
	
	if (poss) {
		cout << "YES" << ln;
		for (auto& i : a) {
			cout << i.size() << " ";
			for (auto& j : i) {
				cout << j << " ";
			}
			cout << ln;
		}
		cout << ln;
	}
	else cout << "NO" << ln;
	return;
	
    
    
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
