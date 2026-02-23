// Problem: C. Watto and Mechanism
// Contest: Codeforces - Codeforces Round 291 (Div. 2)
// URL: https://codeforces.com/contest/514/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int M1 = MOD;
const int M2 = MOD + 2;

// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int b1 = uniform_int_distribution<int>(31, M1 - 1)(rng);
const int b2 = uniform_int_distribution<int>(31, M2 - 1)(rng);

// Usage: a^b % m
long long binexp(long long a, long long b, long long m = 1000000007) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

pair<int, int> getHash(string& s) {
	int C1 = 0, C2 = 0;
	int n = s.length();
	
	for (int i = 0; i < n; i++) {
		C1 += (binexp(b1, i, M1) * (s[i] - 'a' + 1));
		C1 %= M1;
		
		C2 += (binexp(b2, i, M2) * (s[i] - 'a' + 1));
		C2 %= M2;
	}
	
	return {C1, C2};
}

vector<pair<int, int>> alterHash(string& s, int x, pair<int, int> oldHash) {
	vector<pair<int, int>> allHashes;
	
	int bxb1 = binexp(b1, x, M1);
	int bxb2 = binexp(b2, x, M2);
	
	pair<int, int> curHash = oldHash;
	curHash.first -= bxb1 * (s[x] - 'a' + 1);
	curHash.first = ((curHash.first % M1) + M1) % M1;
	curHash.second -= bxb2 * (s[x] - 'a' + 1);
	curHash.second = ((curHash.second % M2) + M2) % M2;
	
	for (char i = 'a'; i <= 'z'; i++) {
		if (i == s[x]) continue;
		
		int C1 = curHash.first + (bxb1 * (i - 'a' + 1)) % M1;
		C1 %= M1;
		int C2 = curHash.second + (bxb2 * (i - 'a' + 1)) % M2;
		C2 %= M2;
		
		allHashes.pb({C1, C2});
	}
	
	return allHashes;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> bankHashes;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	bankHashes.pb(getHash(s));
    }
    
    sort(bankHashes.begin(), bankHashes.end());
    
    for (int i = 0; i < m; i++) {
    	string s;
    	cin >> s;
    	pair<int, int> hash = getHash(s);
    	bool poss = false;
    	
    	for (int j = 0; j < (int)s.length() and !poss; j++) {
    		vector<pair<int, int>> alteredHashes = alterHash(s, j, hash);
    		
    		for (auto& x : alteredHashes) {
    			if (*lower_bound(bankHashes.begin(), bankHashes.end(), x) == x) {
    				poss = true;
					break;
				}
			}
    	}
    	
    	if (poss) {
    		cout << "YES" << ln;
    	}
    	else cout << "NO" << ln;
    }
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
