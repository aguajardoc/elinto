// Problem: 10139 - Factovisors
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1080
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

bitset<100001> bs;
vector<int>p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (ll i = 2; i <= 100000; i++)  {
		if (!bs[i]) continue;
		for (ll j = i * i; j <= 100000; j += i) {
			bs[j] = false;
		}
		p.push_back(i);
	}
}

void solve() {
    int n, m;
    
    while(cin >> n) {
    	cin >> m;
    	int ogn = m;
    	
    	// get prime factors of n
    	// if any pf[i] > m / i -> impossible
    	map<int, int> pf;
    	for (int i = 0; i < p.size() and p[i] * p[i] <= m; i++) {
    		// dbg(p[i]);
    		while (m % p[i] == 0) {
    			pf[p[i]]++;
    			m /= p[i];
    		}
    	}
    	if (m > 1) {
    		pf[m]++;
    	}
    	
    	bool flag = true;
    	for (auto& i : pf) {
    		ll re = 0;
    		for (int j = i.first; j <= n; j *= i.first) {
    			re += n / j;
    		}
    		if (i.second > re) {
    			flag = false;
    		}
    	}
    	
    	if (flag) {
    		cout << ogn << " divides " << n << "!\n";
    	}
    	else {
    		cout << ogn << " does not divide " << n << "!\n";
    	}
    }
}

signed main() {
    fast_cin();
    sieve();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
