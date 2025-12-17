// Problem: B. Queue
// Contest: Codeforces - Codeforces Round 279 (Div. 2)
// URL: https://codeforces.com/contest/490/problem/B
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
    int n;
    cin >> n;
    map<int, int> ftb, ct;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	ftb[a] = b;
    	ct[a]++;
    	ct[b]++;
    }
    
    int cur = ftb[0]; // idx1
    int idx = 1;
    while (cur != 0) {
    	a[idx] = cur;
    	idx += 2;
    	if (!ftb.count(cur)) break;
    	cur = ftb[cur];
    }
    
    int c1 = -1, c2 = -1;
    
    for (auto& i : ct) {
    	if (i.second == 1) {
    		if (c1 == -1) c1 = i.first;
    		else c2 = i.first;
    	}
    }
    
    // dbg(c1, c2);
    // dbg(ftb.count(c1));
    if (ftb.count(c1)) cur = c1;
    else cur = c2;
    
    idx = 0;
    while (cur != 0) {
    	// dbg(cur, idx);
    	a[idx] = cur;
    	idx += 2;
    	cur = ftb[cur];
    }
    
    for (auto& i : a) {
    	cout << i << " ";
    }
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
