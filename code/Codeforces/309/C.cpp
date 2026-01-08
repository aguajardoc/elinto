// Problem: C. Memory for Arrays
// Contest: Codeforces - Croc Champ 2013 - Finals (online version, Div. 1)
// URL: https://codeforces.com/contest/309/problem/C
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ct(40, 0);
    
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	for (int j = 0; j <= 33; j++) {
    		if ((x & (1ll << j))) {
    			ct[j]++;
    		}
    	}
    }
    
    int ans = 0;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    
    sort(b.begin(), b.end());
    
    for (int i = 0; i < m; i++) {
    	if (ct[b[i]]) {
    		ct[b[i]]--;
    		ans++;
    		continue;
    	}
    	
    	// else see if can borrow from higher
    	int j = b[i] + 1;
    	for (; j < 40; j++) {
    		if (ct[j]) break;
    	}
    	if (j == 40) continue;
    	
    	while (j > b[i]) {
    		ct[j]--;
    		ct[j - 1] += 2;
    		j--;
    	}
    	
    	ct[b[i]]--;
    	ans++;
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
