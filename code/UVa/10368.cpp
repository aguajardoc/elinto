// Problem: 10368 - Euclid's Game
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1309
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
    ll x, y;
    while(cin >> x) {
    	cin >> y;
    	if (!x and !y) break;
    	if (x == y) {
    		cout << "Stan wins" << ln;
    		continue;
    	}
    	
    	int turn = 0;
    	vector<int> pat;
    	while (x and y) {
    		if (x > y) swap (x, y);
    		
    		ll k = y / x + 1;
    		if (y % x) k--;
    		if (y - k * x < 0) k--;
			// dbg(turn, x, y, k);
			    		pat.push_back(k);
    		if (k > 1) {
    			if (turn) {
    				cout << "Ollie wins" << ln;
    			}
    			else cout << "Stan wins" << ln;
    			break;
    		}
    		y -= k * x;
    		turn = 1 - turn;
    	}
    	
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
