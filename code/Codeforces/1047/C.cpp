// Problem: C. Enlarge GCD
// Contest: Codeforces - Codeforces Round 511 (Div. 2)
// URL: https://codeforces.com/contest/1047/problem/C
// Memory Limit: 256 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

// Usage: sieve(); p -> list of primes up to N
const int N = 4000;
bitset<N + 1> bs;
vector<int> p;
vector<int> a;

void sieve() {
	int n = a.size();
    bs.set();
    bs[0] = bs[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (!bs[i]) continue;
        for (long long j = i; j <= N; j += i) {
        	bs[j] = false;
        }
        p.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    int g = 0;
    a.assign(n, 0);
    for (auto& i : a) {
    	cin >> i;
    	g = gcd(g, i);
    }
    
    int ans = 0;
    for (auto& i : a) i /= g;
    
    sort(a.begin(), a.end());
    
    if (a.back() == 1) {
    	cout << -1 << ln;
    	return;
    }
    
    map<int, int> fct;
    // dbg(p.size());
    
    for (auto& i : a) {
    	int x = i;
    	for (int j =  0; p[j] * p[j] <= x and j < p.size(); j++) {
    		bool flag = false;
    		while (x % p[j] == 0) {
    			x /= p[j];
    			flag = true;
    		}
    		if (flag) fct[p[j]]++;
    	}
    	
    	if (x > 1) fct[x]++;
    }
    
    int mx = 0;
    for (auto& i : fct) {
    	mx = max(mx, i.second);
    }
    
    cout << n - mx << ln;
    
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