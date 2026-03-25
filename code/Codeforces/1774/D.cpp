// Problem: D. Same Count One
// Contest: Codeforces - Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1774/problem/D
// Memory Limit: 512 MB
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
    int n, m;
    cin >> n >> m;
    vector<int> per(n);
    int ct = 0;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i< n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    		if (a[i][j]){
    			ct++;
    			per[i]++;
    		}
    	}
    }
    
    if (ct % n) {
    	cout << -1 << ln;
    	return;
    }
    
    int goal = ct / n;
    
    vector<vector<int>> swaps;
    bool poss = true;
    
    for (int j = 0; j < m; j++) {
    	vector<int> ones, zeros;
    	
    	for (int i = 0; i < n; i++) {
    		if (per[i] > goal and a[i][j]) ones.pb(i);
    		else if (per[i] < goal and !a[i][j]) zeros.pb(i);
    	}
    	
    	while (!ones.empty() and !zeros.empty()) {
    		swaps.pb({ones.back(), zeros.back(), j});
    		per[ones.back()]--;
    		per[zeros.back()]++;
    		swap(a[ones.back()][j], a[zeros.back()][j]);
    		
    		ones.pop_back();
    		zeros.pop_back();
    	}
    }
    
    cout << swaps.size() << ln;
    for (auto & i : swaps) {
    	for (auto& j : i) {
    		cout << j + 1 << " ";
    	}
    	cout << ln;
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
