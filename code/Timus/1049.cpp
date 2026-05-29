// Problem: 1049. Brave Balloonists
// Contest: Timus Online Judge - Ural State University collegiate programming contest (25.03.2000)
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1049
// Memory Limit: 64 MB
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

vector<int> p;
bitset<101> bs;

void sieve() {
	bs.set();
	bs[0]  = bs[1] = false;
	
	for (int i = 2; i <= 100; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 100; j += i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}

void solve() {
    int ans = 1;
    vector<int> ct(10001, 0);
    for (int i = 0; i < 10; i++) {
    	int x;
    	cin >> x;
    	
    	for (int j = 0; j < p.size() and p[j] * p[j] <= x; j++) {
    		while (x % p[j] == 0) {
    			ct[p[j]]++;
    			x /= p[j];
    		}
    	}
    	if (x > 1) {
    		ct[x]++;
    	}
    }
    
    for (int i = 0; i <= 10000; i++) {
    	ans *= (ct[i] + 1);
    	ans %= 10;
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
