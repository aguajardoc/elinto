// Problem: B - 456
// Contest: AtCoder - AtCoder Beginner Contest 456
// URL: https://atcoder.jp/contests/abc456/tasks/abc456_b
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
    vector<vector<int>> P(3, vector<int> (3, 0));
    
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 6; j++) {
    		int x;
    		cin >> x;
    		
    		if (x >= 4) P[x-4][i]++;
    	}
    }
    
    vector<int> A = {0, 1, 2};
    ld ans = 0;
    
    do {
    	ld loc = (ld)P[A[0]][0] / 6 *
    			(ld)P[A[1]][1] / 6 * 
    			(ld)P[A[2]][2] / 6;
    			
    	ans += loc;
    } while (next_permutation(A.begin(), A.end()));
    
    cout << fixed << setprecision(10) << ans << ln;
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
