// Problem: C. Removing Columns
// Contest: Codeforces - Codeforces Round 283 (Div. 2)
// URL: https://codeforces.com/contest/496/problem/C
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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    
    int idx = -1;
    for (int i = 0; i < m; i++) {
    	bool flag = true;
    	for (int j = 1; j < n; j++) {
    		if (a[j][i] < a[j-1][i]) flag = false;
    	}
    	
    	if (flag) {
    		idx = i;
    		break;
    	}
    }
    
    if (idx == -1) {
    	cout << m << ln;
    	return;
    }
    
    vector<string> actual(n);
    for (int i = 0; i < n; i++) {
    	actual[i] += a[i][idx];
    }
    
    for (int i = idx + 1; i < m; i++) {
    	string cur;
    	cur += actual[0] + a[0][i];
    	bool flag = true;
    	for (int j = 1; j < n; j++) {
    		string next = actual[j] + a[j][i];
    		if (next < cur) {
    			flag = false;
    		}
    		cur = next;
    	}
    	
    	if (flag) {
    		for (int j = 0; j < n; j++) {
		    	actual[j] += a[j][i];
		    }
    	}
    }
    
    cout << m - actual[0].length() << ln;
  
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
