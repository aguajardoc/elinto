// Problem: I. Text Editor
// Contest: Codeforces - Topic 9 - Hashing
// URL: https://codeforces.com/group/OyefIGO3t4/contest/447289/problem/I
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

// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
static vector<pair<int, int>> hasht;
const int M1 = MOD;
const int M2 = MOD + 2;
const int b1 = uniform_int_distribution<int>(256, M1 - 1)(rng);
const int b2 = uniform_int_distribution<int>(256, M2 - 1)(rng);
static vector<long long> p_pow(100001), p_pow2(100001); 

void getHash(string& s) {
	int S = s.length();
	
    p_pow[0] = 1; 
    p_pow2[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
    	p_pow[i] = (p_pow[i-1] * b1) % M1;
    	p_pow2[i] = (p_pow2[i-1] * b2) % M2;
    }
        
    hasht.pb({0,0});
    int C1 = 0, C2 = 0;
    for (int i = 0; i < S; i++) {
    	C1 += p_pow[i] * (s[i] + 1);
    	C1 %= M1;
    	
    	C2 += p_pow2[i] * (s[i]  + 1);
    	C2 %= M2;
    	
    	hasht.pb({C1, C2});
    }
}

int getCount(string const& s, string const& t) {
    int S = s.length();
    long long h_s = 0, h_s2 = 0; 
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (s[i]  + 1) * p_pow[i]) % M1; 
        h_s2 = (h_s2 + (s[i]  + 1) * p_pow2[i]) % M2; 
    }
	
    vector<int> occurrences;
    for (int i = 0; i + (int)s.length() - 1 < (int)t.length(); i++) {
        int ch1 = (hasht[i+S].first + M1 - hasht[i].first) % M1;
        int ch2 = (hasht[i+S].second + M2 - hasht[i].second) % M2;
        
        // dbg(ch1, ch2);
        // dbg(h_s * p_pow[i] % M1);
        // dbg(h_s2 * p_pow2[i] % M2);
        if (make_pair(ch1, ch2) == make_pair(h_s * p_pow[i] % M1, h_s2 * p_pow2[i] % M2))
            occurrences.push_back(i);
    }
    return (int)occurrences.size();
}

void solve() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int k;
    cin >> k;
    
    getHash(s);
    
    int l = 1, r = t.length();
    int ans = 0;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	int fm = getCount(t.substr(0, m), s);
    	// dbg(m, fm);
    	
    	if (fm >= k) {
    		ans = max(ans, m); 
    		l = m + 1;
    	}
    	else {
    		r = m - 1;
    	}
    }
    
    if (!ans) cout << "IMPOSSIBLE" << ln;
    else cout << t.substr(0, ans) << ln;
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
