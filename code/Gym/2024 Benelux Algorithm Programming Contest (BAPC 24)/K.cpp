// Problem: K. Karaoke Compression
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/K
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll M1 = 1e9 + 7;
ll M2 = 1e9 + 9;
ll b1 = uniform_int_distribution<ll>(31, M1-1)(rng);
ll b2 = uniform_int_distribution<ll>(31, M2-1)(rng);

int hashes1[5001][5001], hashes2[5001][5001], lut[5001][5001];

void getHashes(string& s) {
	int n = s.length();
	for (int r = 0; r < n; r++) {
		ll cur1 = 0, cur2 = 0;
		
		for (int l = r; l >= 0; l--) {
			cur1 = (cur1 * b1) % M1 + (s[l] - 'a' + 1);
			cur1 %= M1;
			
			cur2 = (cur2 * b2) % M2 + (s[l] - 'a' + 1);
			cur2 %= M2;
			
			hashes1[l][r] = cur1;
			hashes2[l][r] = cur2;
		}
	}
}


void solve() {
    string s;
    cin >> s;
    int n = s.length();
    getHashes(s);
    
    vector<pair<pair<int, int>, pair<int, int>>> vals;
    vals.reserve(n * (n + 1) / 2);
    for (int i = 0; i < n; i++) {
    	for (int j = i; j < n; j++) {
    		vals.pb({{hashes1[i][j], hashes2[i][j]}, {i, j}});
    	}
    }
    sort(vals.begin(), vals.end());
    
    int id = 0;
    for (int i = 0; i < vals.size(); i++) {
    	if (i > 0 and vals[i].first != vals[i-1].first) id++;
    	
    	
    	int L = vals[i].second.first;
    	int R = vals[i].second.second;
    	
    	lut[L][R] = id;
    }
    
    vector<pair<int, int>> ct(id + 1, {0, -1});
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < n; j++) {
    		int L = j;
    		int R = j + i - 1;
    		if (R >= n) break;
    		
    		int h1 = hashes1[L][R];
    		int h2 = hashes2[L][R];
    		
    		int idx = lut[L][R];
    	
			if (ct[idx].second < L) {
				ct[idx].first++;
				ct[idx].second = R;
			}
		
    	}
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
    	for (int j = i; j < n; j++) {
    		int h1 = hashes1[i][j];
    		int h2 = hashes2[i][j];
    		
    		int idx = lut[i][j];
    		
    		int occ = ct[idx].first;
    		int len = j - i + 1;
    		int res = n - (len - 1) * occ + len;
    		
    		ans = min(ans, res);
    	}
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
