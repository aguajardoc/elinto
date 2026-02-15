// Problem: C. The Tower is Going Home
// Contest: Codeforces - Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)
// URL: https://codeforces.com/contest/1075/problem/C
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
    int n, m;
    cin >> n >> m;
    
    vector<int> vert(n);
    
    vector<int> hends;
    for (int i = 0; i < n; i++) {
    	cin >> vert[i];
    }
    for (int i = 0; i < m; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	if (x == 1) hends.pb(y);
    }
    
    int ans = hends.size();
    sort(hends.begin(), hends.end());
    sort(vert.begin(), vert.end());
    
    int loc = 0, loc2 = hends.size();
    int cur = 0;
    for (auto& i : vert) {
    	while (cur < (int)hends.size() and hends[cur] < i) {
    		cur++;
    		loc2--;
    	}
    	
    	int local = loc + loc2;
    	
    	// dbg(loc, loc2, i);
    	
    	ans = min(ans, local);
    	loc++;
    }
    
    int endans = n;
    for (auto& i : hends) {
    	if (i == 1000000000) endans++;
    }
    ans = min(ans, endans);
    
    cout << ans << endl;
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
