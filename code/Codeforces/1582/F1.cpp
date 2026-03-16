// Problem: F1. Korney Korneevich and XOR (easy version)
// Contest: Codeforces - Codeforces Round 750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/F1
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
    vector<int> ctLR(520, 0);
    for (auto& i : a) {
    	cin >> i;
    	ctLR[i]++;
    }
    vector<int> ctRL(520, 0);
    set<int> res;
    res.insert(0);
    vector<int> mn(550, INF);
    mn[0] = 0;
    
    for (int i = 0; i < n; i++) {
    	ctLR[a[i]]--;
    	
    	vector<int> nl;
    	nl.pb(a[i]);
    	res.insert(a[i]);
    	mn[a[i]] = min(mn[a[i]], a[i]);
    	
    	for (int j = 0; j <= 520; j++) {
    		if (mn[j] < a[i]) {
    			int x = a[i] ^ j;
    			
    			if (a[i] < mn[x]) {
    				mn[x] = a[i];
    				nl.pb(x);
    				res.insert(x);
    			}
    		}
    	}
    	

    	
    	ctRL[a[i]]++;
    }
    
    cout << res.size() << ln;
    for (auto& i : res) {
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
