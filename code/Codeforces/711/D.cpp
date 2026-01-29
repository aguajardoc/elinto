// Problem: D. Directed Roads
// Contest: Codeforces - Codeforces Round 369 (Div. 2)
// URL: https://codeforces.com/contest/711/problem/D
// Memory Limit: 256 MB
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

int binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) {
			res = (a * res) % MOD;
		}
		
		a = (a * a) % MOD;
		b >>= 1;
	}
	
	return res;
}

vector<int> visited, AL,len, depths;

void solve() {
    int n;
    cin >> n;
    AL.assign(n, -1);
    visited.assign(n, 0);
    depths.assign(n, 0);
    for (auto& i : AL) {
    	cin >> i;
    	i--;
    }
    
    // Start a DFS on every node, if i land back, good!
    for (int i = 0; i < n; i++) {
    	if (visited[i]) continue;
    	
    	stack<int> q;
    	q.push(i);
    	while (!q.empty()) {
    		int u = q.top();
    		
    		if (visited[u] == 1) {
    			visited[u] = 2;
    			q.pop();
    			continue;
    		}
    		visited[u] = 1;
    		
    		
    		int v = AL[u];
    		if (visited[v] == 0) {
				depths[v] = depths[u] + 1;
				q.push(v);
			}
			else if (visited[v] == 2) {
				continue;
			}
			else {
				// Cycle found!
				int d = depths[u] - depths[v] + 1;
				len.pb(d);
			}
    	}
    }
    
    int rem = n;
    for (auto& i : len) rem -= i;
    
    int ans = binexp(2, rem);
    for (auto& k : len) {
    	int loc = binexp(2, k) - 2;
    	loc = ((loc % MOD) + MOD) % MOD;
    	
    	ans *= loc;
    	ans %= MOD;
    }
    
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
