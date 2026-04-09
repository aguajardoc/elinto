// Problem: De Bruijn Sequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1692
// Memory Limit: 512 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    
    if (n == 1) {
    	cout << 10 << ln;
    	return;
    }
    
    vector<vector<int>> AL(1 << (n-1));
    for (int i = 0; i < (1 << (n-1)); i++) {
    	
    	int M1 = i, M2 = i;
    	if (__lg(i) == (n - 2)) {
    		M1 ^= (1 << (n - 2));
    		M2 ^= (1 << (n - 2));
    	}
    	M1 <<= 1;
    	M1 |= 1;
    	M2 <<= 1;
    
    	AL[i].pb(M1);
    	AL[i].pb(M2);
    }
    
    string ans;
    stack<int> q;
    q.push(0);
    
    while (!q.empty()) {
    	int u = q.top();
    	
    	if (!AL[u].empty()) {
    		q.push(AL[u].back());
    		AL[u].pop_back();
    	}
    	else {
    		ans += (u & 1) + '0';
    		q.pop();
    	}
    }
    for (int i = 0; i < n - 2; i++) ans+='0';
    
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
