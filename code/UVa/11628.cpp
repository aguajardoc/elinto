// Problem: 11628 - Another lottery
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2675
// Memory Limit: 32 MB
// Time Limit: 1000 ms
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    int n, m;
    while(cin >> n) {
    	cin >> m;
    	if (n == 0 and m == 0) break;
    	
    	int sum = 0;
    	vector<int> con(n);
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
    			if (j == (m - 1)) {
    				sum += x;
    				con[i] = x;
    			}
    		}
    	}
    	
    	
    	for (int i = 0; i < n; i++) {
    		int num = con[i];
    		int den = sum;
    		int hcf = __gcd(num, den);
    		num /= hcf;
    		den /= hcf;
    		
    		cout << num << " / " << den << ln;
    	}
    	
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
