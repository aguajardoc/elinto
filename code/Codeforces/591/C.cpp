// Problem: C. Median Smoothing
// Contest: Codeforces - Codeforces Round 327 (Div. 2)
// URL: https://codeforces.com/contest/591/problem/C
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

void process(int start, int n, vector<int>& ans) {
	
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    int sti = -1;
    vector<int> ans(n, 0);
    
    // find blocks of cons 1's
    vector<pair<int, int>> cons, alternating;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0) continue;
    	int start = i;
    	while (i < n and a[i] == 1) {
    		i++;
    	}
    	i--;
    	cons.push_back({start, i});
    }
    
    // find blocks of alternating
    for (int i = 0; i < n; i++) {
    	if (a[i] == 1) continue;
    	int start = i;
    	int x = 0;
    	while (i < n and a[i] == x) {
    		i++;
    		x = 1 - x;
    	}
    	i--;
    	alternating.push_back({start, i});
    }
    
    // we have all structures of stability, now what?
    // TODO: implement this algorithm
    // iterate over alternating regions, if right before we have a structure, 
	int idx = 0;
	int oidx = 0;
    for (int i = 0; i < n; i++) {
    	while (idx < alternating.size() and alternating[idx].first < i) idx++;    	
    	if (idx < alternating.size() and oidx < cons.size()) {
    		// i is not start of alternating
    		if (i != alternating[idx].first) {
    			ans[i] = a[i];
    		}
    		else {
    			
    		}
    	}
    	else {
    		ans[i] = a[i];
    	}
    }
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
