// Problem: B. The Walkway
// Contest: Codeforces - Codeforces Round 893 (Div. 2)
// URL: https://codeforces.com/contest/1858/problem/B
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

void solve() {
    int n, m ,d;
    cin >> n >> m >> d;
    vector<int> a = {0};
    bool one = false;
    for (int i = 0; i < m ; i++) {
    	int x;
    	cin >> x;
    	x--;
    	if (!x) {
    		one = true;
    		continue;
    	}
    	a.pb(x);
    }
    a.pb(n);
    m = a.size();
    
    vector<int> c(m, 0);
    int s = 0;
    for (int i = 0; i < m - 1; i++) {
    	int nc = 1;
    	nc += (a[i + 1] - a[i] - 1) / d;
    	c[i] = nc;
    	s += nc;
    }
    
    int ss = s;
    map<int, int> ct;
    int cum = 0;
    for (int i = 0; i < m - 1; i++) {
    	// How much would this one contribute
    	s -= c[i];
    	int nc = INF;
    	if (i) {
    		nc = (a[i + 1] - a[i - 1] - 1) / d;
    		nc -= c[i-1] - 1;
    	}
    	
    	ct[cum + nc + s]++;
    	
    	// Update cum
    	cum += c[i];
    }
    
    // cout << ln;
    auto [A,B] = *ct.begin();
    if (A == ss and one) B++;
    cout << A << " " << B << ln;
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
