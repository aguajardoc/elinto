// Problem: E - Packing Potatoes
// Contest: AtCoder - AtCoder Beginner Contest 258
// URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
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

void solve() {
    int n, q, x; cin >> n >> q >> x;
    vector<int> a(n); for (auto& i : a) cin >> i;
    vector<int> pref(2 * n + 2, 0);
    for (int i = 0; i < 2 * n; i++) {
    	pref[i+1] = pref[i] + a[i%n];
    }
    int s = 0;
    for (auto& i : a) s += i;
    // for (auto& i : pref) {
    	// cout << i << " ";
    // }
    // cout << ln;
//     
    int times = (x/s + min(1ll, x%s)) - 1;
    vector<int> AL(n);
    for (int i = 0; i < n; i++) {
    	int cur = times * s;
    	int target = x - cur + pref[i];
    	auto it = lower_bound(pref.begin(), pref.end(), target);
    	int idx = it - pref.begin();
    	AL[i] = idx + times * n;
    }
    
    vector<int> visited(n, -1);
    vector<int> seq;
    int turns = 0;
    int u = 0;
    int start, cycle;
    while(true) {
    	if (visited[u] != -1) {
    		start = visited[u];
    		cycle = turns - start;
    		break;
    	}
    	visited[u] = turns;
    	seq.pb(AL[u] - u);
    	u = AL[u]%n;
    	turns++;
    }
    
    
    while(q--) {
    	int k; cin >> k;
    	k--;
    	if (k < seq.size()) {
    		cout << seq[k] << ln;
    		continue;
    	}
    	
    	k -= start;
    	cout << seq[start + k % cycle] << ln;
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
