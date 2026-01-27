// Problem: D. Andrey and Problem
// Contest: Codeforces - Codeforces Round 253 (Div. 2)
// URL: https://codeforces.com/contest/443/problem/D
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
    int n;
    cin >> n;
    vector<ld> p(n);
    for (auto& i : p) cin >> i;
    
    ld lt = 0;
    ld ht = 0;
    ht = p.back();
    
    sort(p.rbegin(), p.rend());
    
    for (int i = 0; i < n; i++) {
    	ld loc1 = 0;
    	for (int j = 0; j <= i; j++) {
    		ld loc2 = p[j];
    		for (int k = 0; k <= i; k++) {
    			if (j == k) continue;
    			loc2 *= (1.0 - p[k]);
    		}
    		loc1 += loc2;
    	}
    	
    	lt = max(lt, loc1);
    	// dbg(loc1);
    }
    
    // dbg(lt, ht);
    
    cout << fixed << setprecision(10) << max(lt, ht) << ln;
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
