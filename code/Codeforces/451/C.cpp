// Problem: C. Predict Outcome of the Game
// Contest: Codeforces - Codeforces Round 258 (Div. 2)
// URL: https://codeforces.com/contest/451/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

vector<ll> getW(ll k, ll d1, ll d2) {
	ll w1 = (k + 2 * d1 + d2) / 3;
	ll w2 = (k -d1 + d2) / 3;
	ll w3 = (k - d1 - 2 * d2) / 3;
	
	return {w1, w2, w3};
}

void prll(vector<ll>& x) {
	for (auto& i : x) {
		cout << i << " ";
	}
	cout << ln;
}

void solve() {
    ll n, k, d1, d2;
    cin >> n >> k >> d1 >> d2;
    if (n % 3) {
    	cout << "no" << ln;
    	return;
    }
    
    vector<ll> pospos = getW(k, d1, d2);
    vector<ll> posneg = getW(k, d1, -d2);
    vector<ll> negpos = getW(k, -d1, d2);
    vector<ll> negneg = getW(k, -d1, -d2);
    
    vector<vector<ll>> cur = {pospos, posneg, negpos, negneg};
    bool poss = false;
	// At least enough games, and surplus an be %3'd
	for (auto& i : cur) {
		// prll(i);
		ll tot = 0;
		bool local = true;
		ll mx = 0;
		for (auto& j : i) {
			tot += j;
			mx = max(mx, j);
			if (j < 0) local = false;
		}
		if (tot != k) local = false;
		if (abs(i[1] - i[0]) != d1) local = false;
		if (abs(i[1] - i[2]) != d2) local = false;		
		
		ll diff = 0;
		if (local) {
			// get diff to max
			for (auto& j : i) {
				diff += abs(mx - j);
			}
			// if diff is at least the number of other games, and surplus is divisible by 3...
			// dbg(n, k, diff);
			if ((n - k >= diff) and (n - k - diff) % 3 == 0) poss = true;
		}
	}
	
	if (poss) cout << "yes" << ln;
	else cout << "no" << ln;
}

signed main() {
    fast_cin();
    
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
