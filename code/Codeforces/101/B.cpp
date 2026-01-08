// Problem: B. Buses
// Contest: Codeforces - Codeforces Beta Round 79 (Div. 1 Only)
// URL: https://codeforces.com/contest/101/problem/B
// Memory Limit: 265 MB
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

int mod(int x) {
	return ((x % MOD) + MOD) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> ranges(m);
    set<int> vals;
    for (int i = 0; i < m; i++) {
    	cin >> ranges[i].first >> ranges[i].second;
    	vals.insert(ranges[i].first);
    	vals.insert(ranges[i].second);
    }
    
    vector<int> mapping = {0};
    for (auto& i : vals) {
    	if (i != 0 and i != n)
    	mapping.pb(i);
    }
    mapping.pb(n);
    
    for (auto& i : ranges) {
    	auto it = lower_bound(mapping.begin(), mapping.end(), i.first);
    	i.first = distance(mapping.begin(), it);
    	
    	it = lower_bound(mapping.begin(), mapping.end(), i.second);
    	i.second = distance(mapping.begin(), it);
    }
    
    sort(ranges.begin(), ranges.end());
    deque<pair<int, int>> inactive;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> active;
    for (auto& i : ranges) {
    	if (i.first == 0) {
    		active.push({i.second, i.first});
    	}
    	else inactive.pb(i);
    }
    
    int goal = (int)mapping.size() - 1;
    
    vector<int> pref = {0, 1};
    vector<int> pref2 = {0, 1};
    
    int stop = 1;
    while (stop <= goal) {
    	// Process endings
    	int added = 0;
    	while (!active.empty() and active.top().first == stop) {
    		int tt = active.top().first;
    		int st = active.top().second;
    		int x = pref2[tt] - pref2[st];
    		x = mod(x);
    		added += x;
    		added = mod(added);
    		
    		active.pop();
    	}
    	
    	pref.pb(added);
    	int y = pref2.back() + added;
    	y = mod(y);
    	pref2.pb(y);
    	
    	pref.back() = mod(pref.back());
    	pref2.back() = mod(pref2.back());
    	
    	// Process starts
    	while (!inactive.empty() and inactive.front().first == stop) {
    		active.push({inactive.front().second, inactive.front().first});
    		inactive.pop_front();
    	}
    	
    	stop++;
    }
    
    cout << mod(pref.back()) << ln;
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
