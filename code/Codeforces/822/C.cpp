// Problem: C. Hacker, pack your bags!
// Contest: Codeforces - Codeforces Round 422 (Div. 2)
// URL: https://codeforces.com/contest/822/problem/C
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

struct Ticket {
	ll L, R, C;
	bool operator<(const auto& a) const {
		if (L != a.L) return L < a.L;
		if (R != a.R) return R < a.R;
		return C < a.C;				
	}
};

void solve() {
	// map them
	ll n, x;
	cin >> n >> x;
	
	map<ll, set<Ticket>> ticks;
	vector<Ticket> tickets;
	
	for (ll i = 0; i <  n; i++) {
		ll l, r, c;
		cin >> l >> r >> c;
		tickets.push_back({l, r, c});
	}
	
	sort(tickets.rbegin(), tickets.rend());
	
	ll ans = 1e11;
	for (ll i = 0; i < n; i++) {
		ll L = tickets[i].L;
		ll R = tickets[i].R;
		ll C = tickets[i].C;
		ll duration = R - L + 1;
		ll mc = C;

		if (!ticks[duration].empty()) {
			// dbg(i, ticks.count(duration), L, R);
			// dbg(ticks[duration].begin()->C);
			mc = min(mc, ticks[duration].begin()->C);
		}
		
		// look for best
		ll bestCost = 1e11;
		ll rem = x - duration;
		Ticket compare = {R+1, -1, -1};
		ticks[rem];
		auto it = ticks[rem].upper_bound(compare);

		Ticket inserted = {L, R, mc};
		ticks[duration].insert(inserted);
		
		if (it != ticks[rem].end()) {
			bestCost = it->C;
		}
		
		ans = min(ans, C + bestCost);
	}
	
	if (ans >= 1e10) {
		cout << -1 << ln;
	}
	else cout << ans << ln;
    
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
