// Problem: 498 - Polly the Polynomial
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=439
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
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void parseInput(vector<ll>& x, string c) {
	string cur;
	c += ' ';
	for (auto& i : c) {
		if (i == ' ') {
			if (cur.empty()) continue;
			x.push_back(stoll(cur));
			cur.clear();
		}
		else cur += i;
	}
}

void solve() {
    string c;
    while (getline(cin, c)) {
    	vector<ll> pol;
    	parseInput(pol, c);
    	reverse(pol.begin(), pol.end());
    	vector<ll> vals;
    	getline(cin, c);
    	parseInput(vals, c);
    	
    	bool fi = false;
    	
    	for (auto& i : vals) {
    		ll res = 0;
    		ll xn = 1;
    		for (auto& j : pol) {
    			res += j * xn;
    			xn *= i;
    		}
    		if (fi) cout << " ";
    		fi = true;
    		cout << res;
    	}
    	cout << ln;
    }
}

int main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
