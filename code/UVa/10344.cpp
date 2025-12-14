// Problem: 10344 - 23 out of 5
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285
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
vector<int> a(5);

bool backtrack(int idx, int res) {
	if(idx == 5) {
		if (res == 23) return true;
		return false;
	}
	
	return 	backtrack(idx+1, res+a[idx]) or 
			backtrack(idx+1, res-a[idx]) or
			backtrack(idx+1, res*a[idx]);
}

void solve() {
    while (true) {
    	bool flag = false;
    	for (int i = 0; i < 5; i++) {
    		cin >> a[i];
    		flag |= (a[i]>0);
	    }
	    if (!flag) break;
	    sort(a.begin(), a.end());
	    do {
	    	if (backtrack(1, a[0])) {
	    		flag = false;
	    		break;
	    	}
	    } while (next_permutation(a.begin(), a.end()));
	    
		cout << (flag ? "Impossible":"Possible") << ln;
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
