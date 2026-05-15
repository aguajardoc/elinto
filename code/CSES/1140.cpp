// Problem: Projects
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1140
// Memory Limit: 512 MB
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

int dp[400100];
vector<vector<pair<int, int>>> projects_by_time;
int mt;

int recurse(int idx) {
	if (idx > mt) {
		return 0;
	}
	
	if (dp[idx] != -1) return dp[idx];
	
	int res = 0;
	
	// take any project that starts now
	for (auto& p : projects_by_time[idx]) {
		res = max(res, recurse(p.first + 1) + p.second);
	}
	
	// or dont do anything today
	res = max(res, recurse(idx + 1));
	
	return dp[idx] = res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> times;
    vector<vector<int>> projects(n);
    fill_n(&dp[0], 400100, -1);
    projects_by_time.resize(2 * n + 50);
    for (int i = 0; i < n; i++) {
    	int a, b, p;
    	cin >> a >> b >> p;
    	projects[i] = {a, b, p};
    	times.pb(a);
    	times.pb(b);
    }
    
    sort(times.begin(), times.end());
    times.resize(unique(times.begin(), times.end()) - times.begin());
    
    for (auto& p : projects) {
    	p[0] = lower_bound(times.begin(), times.end(), p[0]) - times.begin();
    	p[1] = lower_bound(times.begin(), times.end(), p[1]) - times.begin();
    	
    	projects_by_time[p[0]].pb({p[1], p[2]});
    }
    
    mt = times.size() + 40;
    
    cout << recurse(0) << ln;
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
