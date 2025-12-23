// Problem: B. Balls Game
// Contest: Codeforces - Codeforces Round 245 (Div. 2)
// URL: https://codeforces.com/contest/430/problem/B
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
#define int ll
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

ll getRes(vector<ll>& a, int n, int idx, int x) {
	// place ball at pos i
	vector<int> na;
	for (int i = 0; i < idx; i++) na.push_back(a[i]);
	na.push_back(x);
	for (int i = idx; i < n; i++) na.push_back(a[i]);
	
	// perform!
	int rem = 0;
	bool moved = true;
	while (moved) {
		moved = false;
		int cons = 1;
		int start = 0;
		for (int i = 1; i < na.size(); i++) {
			if (na[i] != na[i - 1]) {
				if (cons >= 3) break;
				cons = 1;
				start = i;
			}
			else {
				cons++;
			}
		}
		
		if (cons < 3) {
			continue;
		}
		moved = true;
		rem += cons;
		
		vector<int> narep;
		for (int i = 0; i < start; i++) {
			narep.push_back(na[i]);
		}
		for (int i = start + cons; i < na.size(); i++) {
			narep.push_back(na[i]);
		}
		
		na = narep;
	}
	
	return rem;
}

void solve() {
    // at most you destroy all balls, every time, so n^2 impl?
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    
    // try every pos, get max
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
    	ans = max(ans, getRes(a, n, i, x));
    }
    if (ans)ans--;
    
    cout << ans << ln;
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
