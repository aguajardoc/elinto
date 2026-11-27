// Problem: E - Project Assignment
// Contest: AtCoder - AtCoder Weekday Contest 0200 Beta
// URL: https://atcoder.jp/contests/awc0200/tasks/awc0200_e
// Memory Limit: 1024 MB
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

struct Project {
	int p, r, idx, skill = 0;
	
	bool operator<(const auto& oth) const {
		if (p != oth.p) return p > oth.p;
		return idx < oth.idx;
	}
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> s(n);
    vector<Project> p(m);
    for (auto& i : s) cin >> i;
    for (int i = 0; i < m; i++) {
    	cin >> p[i].p >> p[i].r;
    	p[i].idx = i;
    }
    
    sort(p.begin(), p.end());
    
    sort(s.rbegin(), s.rend());
    int sidx = 0, i;
    for (i = 0; i < m; i++) {
    	while (sidx < n and p[i].r > 0) {
    		p[i].r--;
    		p[i].skill += s[sidx++];
    	}
    }
    
    vector<int> ans(m);
    for (auto& i : p) {
    	if (i.r) {
    		cout << -1 << ln;
    		return;
    	}
    	
    	ans[i.idx] = i.skill;
    }
    
    for (auto& i : ans) {
    	cout << i << ln;
    }
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
