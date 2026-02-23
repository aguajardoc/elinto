// Problem: D. Good Substrings
// Contest: Codeforces - Codeforces Round 166 (Div. 2)
// URL: https://codeforces.com/contest/271/problem/D
// Memory Limit: 512 MB
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

// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M1 = MOD;
const int M2 = MOD + 2; 
const int B1 = uniform_int_distribution<int>(31, M1 - 1)(rng);
const int B2 = uniform_int_distribution<int>(31, M2 - 1)(rng);

static int hashes1[1501][1501], hashes2[1501][1501];

void getHashes(string& s, string& banned, int k) {
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int C1 = 0, C2 = 0;
		int bads = 0;
		
		for (int j = i; j >= 0; j--) {
			if (banned[s[j] - 'a'] == '0') bads++;
			if (bads > k) break;
			
			C1 = (C1 * B1) % M1 + (s[j] - 'a' + 1);
			C2 = (C2 * B2) % M2 + (s[j] - 'a' + 1);
			
			hashes1[j][i] = C1;
			hashes2[j][i] = C2;
		}
	}
}

void solve() {
    string s, banned;
    int k;
    cin >> s >> banned >> k;
    fill_n(&hashes1[0][0], 1501 * 1501, -1);
    fill_n(&hashes2[0][0], 1501 * 1501, -1);
    getHashes(s, banned, k);
    
    vector<pair<int, int>> good;
    
    for (int i = 0; i < (int)s.length(); i++) {
    	for (int j = i; j < (int)s.length(); j++) {
    		if (hashes1[i][j] == -1) continue;
    		
    		good.pb({hashes1[i][j], hashes2[i][j]});
    	}
    }
    
    sort(good.begin(), good.end());
    good.resize(unique(good.begin(), good.end()) - good.begin());
    
    cout << (int)good.size() << ln;
    
    
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

