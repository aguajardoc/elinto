// Problem: C. Least Prefix Sum
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/C
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

int getPrefix(vector<int>& a, int n, int m) {
	int cur = 0;
	for (int i = 0; i <= m; i++) {
		cur += a[i];
	}
	
	return cur;
}

void solve() {
    int n, m;
    cin >> n >> m;
    m--;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int ops = 0;

    if (m != 0 and a[m] > 0) {
    	ops = 1;
    	a[m] = -a[m];
    }
    
    // Get actual value
    int pm = getPrefix(a, n, m);
    
    // get difference between min and actual
    int cur = a[m];
    priority_queue<int> pq;
    for (int i = m - 1; i > 0; i--) {
    	cur += a[i];
    	if (a[i] > 0) pq.push(a[i]);
    	while (cur > 0) {
    		int tp = pq.top();
	    	ops++;
	    	pq.pop();
	    	
	    	cur -= 2 * tp;
    	}
    }
    
    // dbg(ops);
    
    // now after, if any is out of line as well, die
    cur = pm;
    priority_queue<int> JFC;
    
    for (int i = m + 1; i < n; i++) {
    	cur += a[i];
    	if (a[i] < 0)JFC.push(abs(a[i]));
    	
    	// dbg(pm, cur, ops);
    	
    	while (cur < pm) {
    		int tp = JFC.top();
    		
    		cur += 2 * tp;
    		ops++;
    		JFC.pop();
    	}
    	
    	// dbg(pm, cur, ops);
    }
    
    cout << ops;
    
    cout << ln;
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