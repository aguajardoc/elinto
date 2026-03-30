// Problem: F - #(subset sum = K) with Add and Erase
// Contest: AtCoder - SuntoryProgrammingContest2023（AtCoder Beginner Contest 321）
// URL: https://atcoder.jp/contests/abc321/tasks/abc321_f
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
const int MOD = 998244353;
const double eps = 1e-9;

void solve() {
    int q, k;
    cin >> q >> k;
    vector<int> ways(k + 1, 0);
    ways[0] = 1;
    
    while(q--) {
    	char type;
    	int x;
    	cin >> type >> x;
    	
    	if (type == '+') {
    		for (int i = k; i >= x; i--) {
    			ways[i] += ways[i-x];
    			ways[i] %= MOD;
    		}
    	}
    	else {
    		for (int i = 0; i <= k - x; i++) {
    			ways[i+x] -= ways[i];
    			ways[i+x] = ((ways[i+x] % MOD) + MOD) % MOD;
    		}
    	}
    	
    	cout << ways[k] << ln;
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
