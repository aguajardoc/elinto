// Problem: B - Stolen Necklace
// Contest: AtCoder - AtCoder Regular Contest 215
// URL: https://atcoder.jp/contests/arc215/tasks/arc215_b
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
    int n; cin >> n;
    vector<int> a(2*n); for (auto& i : a) cin >> i;
    
    set<int> odd, even;
    vector<int> dividers;
    int cur = 1;
    for (int i = 0; i < 2*n; i++) {
    	if (cur) odd.insert(a[i]);
    	else even.insert(a[i]);
    	
    	if (i < 2 * n - 1) {
    		if (cur and odd.count(a[i+1])) {
    			cur = 1 - cur;
    			dividers.pb(i+1);
    		}
    		else if (!cur and even.count(a[i+1])) {
    			cur = 1 - cur;
    			dividers.pb(i+1);
    		}
    	}
    }
    
    cout << dividers.size() << ln;
    for (auto& i : dividers) {
    	cout << i << " ";
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
