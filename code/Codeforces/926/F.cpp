// Problem: F. Mobile Communications
// Contest: Codeforces - VK Cup 2018 - Wild-card Round 1
// URL: https://codeforces.com/contest/926/problem/F
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

void brute(vector<pair<int, int>>& e, int n, int p, int m) {
	int cur = 0;
	int idx = 0;
	for (int i = 1; i <= m; i++) {
		if (idx <= n and e[idx].first == i) cur += e[idx++].second + p;
		
		cur -= p;
		
		dbg(i, cur);
	}
}

void solve() {
    int n, p, m;
    cin >> n >> p >> m;
    
    vector<pair<int, int>> events(n+ 1);
    for (int i = 0; i < n; i++) {
    	cin >> events[i].first >> events[i].second;
    	events[i].second -= p;
    }
    events[n] = {m+1, INF};
    
    // brute(events, n, p, m);
    
    int prev = 0;
    int balance = 0;
    int ans = 0;
    
    for (int i = 0; i <= n; i++) {
    	int day = events[i].first;
    	int added = events[i].second;
    	
    	int new_balance = balance - p * (day - prev - 1) + added;
    	
    	int x = (1 + balance) / p + min(1ll, (1 + balance) % p);
    	
    	int days_under = day - prev - x;
    	days_under = min(day - prev, max(days_under, 0ll));
    	
    	// dbg(balance);
    	// dbg(day, added);
    	// dbg(prev);
    	// dbg(new_balance);
    	// dbg(x);
    	// dbg(days_under);
    	// cout << ln;
    	
    	ans += days_under;
    	
    	prev = day;
    	balance = new_balance;
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
