// Problem: We Be Flipping (Hard Version)
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2229/problem/C2
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

void solve() {
    // Can it be positive? at the cost of the cheapest largest
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    // For each positive, what would be the gain if flipped?
    vector<int> gains(n, 0);
    int current = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > 0) {
    		gains[i] = current - a[i];
    	}
    	else {
    		current -= a[i];
    	}
    }
    
    int mxg = 0;
    int idx = -1;
    for (int i = 0; i < n; i++) {
    	// dbg(i, gains[i]);
    	if (gains[i] > mxg) {
    		mxg = gains[i];
    		idx = i;
    	}
    }
    
    int flipped = true;
    vector<int> flips;
    vector<int> pos, neg;
    if (idx != -1) flips.pb(idx);
    for (int i = idx-1; i >= 0; i--) {
    	if (a[i] < 0 and !flipped) {
    		flips.pb(i);
    		flipped = true;
    		neg.pb(i);
    	}
    	else if (a[i] > 0 and flipped) {
    		flips.pb(i);
    		pos.pb(i);
    		flipped = false;
    	}
    }
    
    if (idx != -1) pos.pb(idx);
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    cout << flips.size() << ln;
    idx = 0;
    for (int i = 0; i < pos.size(); i++) {
    	cout << pos[i]+1 << " ";
    	while (idx < neg.size() and neg[idx] < pos[i]) {
    		cout << neg[idx++]+1 << " ";
    	}
    }
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
