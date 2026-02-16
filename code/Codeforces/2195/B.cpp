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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    map<int, set<int>> d;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
    	if (vis[i]) continue;
    	
    	int cur = i * 2;
    	d[i].insert(a[i-1]);
    	vis[i] = true;
    	while (cur <= n) {
    		vis[cur] = true;
    		
    		d[i].insert(a[cur-1]);
    		cur *= 2;
    	}	
    }
    
    bool poss = true;
    for (auto& i : d) {
    	int j = i.first;
    	for (auto& k : i.second) {
    		if (k != j) poss = false;
    		j *= 2;
    	}
    }
    
    cout << (poss ? "YES":"NO") << ln;
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
