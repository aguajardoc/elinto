// Problem: Problem 1. Modern Art
// Contest: USACO - USACO 2017 US Open Contest, Platinum
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=744
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
    freopen("art.in", "r", stdin); \
    freopen("art.out", "w", stdout)
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
    vector<vector<int>> a(n+1, vector<int> (n+1, 0)), BBMAT = a, pref = a;
    vector<int> X1(n * n+1, INF), X2(n * n+1, -INF), Y1 = X1, Y2 = X2;
    
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    		X1[a[i][j]] = min(X1[a[i][j]], i);
    		X2[a[i][j]] = max(X2[a[i][j]], i);
    		
    		Y1[a[i][j]] = min(Y1[a[i][j]], j);
    		Y2[a[i][j]] = max(Y2[a[i][j]], j);
    	}
    }
    
    int avail = 0;
    for (int i = 1; i <= n * n; i++) {
    	if (X1[i] == INF) continue;
    	avail++;
    	BBMAT[X1[i]][Y1[i]]++;
    	BBMAT[X2[i]+1][Y1[i]]--;
    	BBMAT[X1[i]][Y2[i]+1]--;
    	BBMAT[X2[i]+1][Y2[i]+1]++;
    }
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + BBMAT[i-1][j-1];
    	}
    }
    
    set<int> banned;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (pref[i+1][j+1] >= 2) {
    			banned.insert(a[i][j]);
    		}
    	}
    }
    
    cout << n * n - (int)banned.size() - (avail == 1) << ln;
}

signed main() {
    fast_cin();
    iofiles();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
