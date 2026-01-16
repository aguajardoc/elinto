// Problem: E. Fire
// Contest: Codeforces - Codeforces Round 436 (Div. 2)
// URL: https://codeforces.com/contest/864/problem/E
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
struct item {
	int t, d, p, idx;
};

int n;
vector<item> a;
int dp[101][2001];
pair<int, int> p[101][2001];

int recurse(int idx, int time) {
	if (idx == n) {
		return 0;
	}
	
	if (dp[idx][time] != -1) return dp[idx][time];
	
	int res = 0;
	int c = recurse(idx + 1, time);
	int b = -INF;
	if (time + a[idx].t < a[idx].d) {
		b = recurse(idx + 1, time + a[idx].t) + a[idx].p;
	}
	
	if (c > res) {
		res = c;
		p[idx][time] = {idx + 1, time};
	}
	if (b > res) {
		res = b;
		p[idx][time] = {idx + 1, time + a[idx].t};
	}
	
	return dp[idx][time] = res;
}

void print() {
	for (auto& i : p) {
		for (auto& j : i) {
			cout << j.first << ", " << j.second << " ";
		}
		cout << ln;
	}
}

void solve() {
    cin >> n;
    a.assign(n, {0, 0, 0});
    fill_n(&dp[0][0], 101*2001, -1);
    fill_n(&p[0][0], 101*2001, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
    	int t, d, p;
    	cin >> t >> d >> p;
    	a[i] = {t, d, p, i+1};
    }
    sort(a.begin(), a.end(), [](const auto& l, const auto& r) {
    	if (l.d != r.d) return l.d < r.d;
    	return l.t < r.t;
    });
    
    int ans = recurse(0, 0);
    
    // print();
    
    // then try to retrieve by traversing?
    int idx = 0, time = 0;
    vector<int> path;
    while (p[idx][time] != make_pair(-1ll, -1ll)) {
    	if (p[idx][time].second != time) path.pb(a[idx].idx);
    	pair<int, int> next = p[idx][time];
    	idx = next.first;
    	time = next.second;
    }
    
    cout << ans << ln << path.size() << ln;
    for (auto& i : path) {
    	cout << i << " ";
    }
	cout << ln;    
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
