// Problem: Problem 3. Exercise
// Contest: USACO - USACO 2020 US Open Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=1043
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("exercise.in", "r", stdin); \
    freopen("exercise.out", "w", stdout)
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

int n, m;
int dp[1300][10001];
// Usage: sieve(); p -> list of primes up to N
const int N = 10000;
bitset<N + 1> bs;
vector<int> p;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (!bs[i]) continue;
        for (long long j = i * i; j <= N; j += i) bs[j] = false;
        p.push_back(i);
    }
}

int recurse(int idx, int s) {
	if (idx >= p.size()) return 1;
	if (s > n) return 0;
	if (s == n) {
		return 1;
	}

	if (dp[idx][s] != -1) return dp[idx][s];
	
	int res = 0;
	int cp = p[idx];
	for (int i = 0; s + cp <= n; i++, cp *= p[idx]) {
		res += (recurse(idx + 1, s+cp) * cp) % m;
		res %= m;
	}
	res += recurse(idx + 1, s);
	res %= m;
	
	return dp[idx][s] = res;
}

void solve() {
    cin >> n >> m;
    fill_n(&dp[0][0], 1300*10001, -1);
    cout << recurse(0, 0) << ln;
}

signed main() {
    fast_cin();
    iofiles();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
