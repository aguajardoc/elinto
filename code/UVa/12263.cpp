// Problem: 12263 - Rankings
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3415
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    map<int, set<int>> beats;
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		beats[a[i]].insert(a[j]);
    	}
    }
    beats[a.back()];
    
    bool poss = true;
    
    int m;
    cin >> m;
    while(m--) {
    	int x, y;
    	cin >> x >> y;
    	// dbg(x, y);
    	// dbg(beats[2].size());
    	if (!beats[x].count(y) and !beats[y].count(x)) poss = false;
    	else {
    		if (beats[x].count(y)) {
    			beats[x].erase(y);
    			beats[y].insert(x);
    		}
    		else if (beats[y].count(x)) {
    			beats[y].erase(x);
    			beats[x].insert(y);
    		}
    	}
    }
    
    if (!poss) {
    	cout << "IMPOSSIBLE";
    	return;
    }
    
    vector<pair<int, int>> ans;
    for (auto& i : beats) {
    	ans.pb({-i.second.size(), i.first});
    	// dbg(i.second.size());
    }
    
    sort(ans.begin(), ans.end());
    
    for (int i = 1; i < n; i++) {
    	if (ans[i].first == ans[i-1].first) {
    		poss = false;
    	}
    }
    
    if (!poss) {
    	cout << "IMPOSSIBLE";
    	return;
    }
    
    for (int i = 0; i < n; i++) {
    	cout << ans[i].second;
    	if (i != n - 1) cout << " ";
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
        cout << ln;
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
