// Problem: D. Event Dates
// Contest: Codeforces - School Team Contest 3 (Winter Computer School 2010/11)
// URL: https://codeforces.com/contest/45/problem/D
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dates(n, vector<int>(3));
    vector<int> starts, ends, vals, idxs;
    for (int i = 0; i < n; i++) {
    	cin >> dates[i][0] >> dates[i][1];
    	
    	dates[i][2] = i;
    	vals.pb(dates[i][0]);
    	vals.pb(dates[i][1]);
    	
    	for (int j = dates[i][0] + 1; j <= min(dates[i][1], dates[i][0] + 15); j++) {
    		vals.pb(j);
    	}
    }
    
    sort(dates.begin(), dates.end());
    for (int i = 0; i < n; i++) {
    	starts.pb(dates[i][0]);
    	ends.pb(dates[i][1]);
    	idxs.pb(dates[i][2]);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& i : starts) {
    	i = lower_bound(vals.begin(), vals.end(), i) - vals.begin();
    }
    for (auto& i : ends) {
    	i = lower_bound(vals.begin(), vals.end(), i) - vals.begin();
    }
    
    
    int si = 0, ei = 0;
    vector<int> ans(n);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int killed = 0;
    int time = 0;
    while (si < n or !pq.empty()) {
    	while (si < n and starts[si] == time) {
    		pq.push({ends[si], starts[si], idxs[si]});
    		si++;
    	}
    	
    	if (!pq.empty()) {
    		ans[pq.top()[2]] = vals[time];
    		pq.pop();
    	}
    	
    	time++;
    }
    
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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