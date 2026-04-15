// Problem: E. Compress Words
// Contest: Codeforces - Codeforces Round 578 (Div. 2)
// URL: https://codeforces.com/contest/1200/problem/E
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+ (H o) { return x + o.x + (x + o.x < x); }
	H operator- (H o) { return *this + ~o.x; }
	H operator* (H o) { auto m = (__uint128_t)x * o.x;
	    return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator< (H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11+3;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string &str) : ha(str.size() + 1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); i++) {
			ha[i+1] = ha[i] * C + str[i];
			pw[i+1] = pw[i] * C;
		}
	}
	H hashInterval(int a, int b) { // [a, b)
		return ha[b] - ha[a] * pw[b-a];
	}
	void extend(int oldsz, string& str) {
		ha.resize(str.size() + 1);
		pw.resize(str.size() + 1);
		for (int i = oldsz; i < str.size(); i++) {
			ha[i+1] = ha[i] * C + str[i];
			pw[i+1] = pw[i] * C;
		}
	}
};

H hashString(string& s) {H h{}; for (char& c : s) h=h*C+c; return h; }

void solve() {
    int n;
    cin >> n;
    
    string ans;
    string prev;
    HashInterval AI(ans);
    int prev_len = 0;
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	if (ans.empty()) {
    		ans = s;
    		prev = s;
    		continue;
    	}
    	
    	// Get interval for this one, and extend ans
    	AI.extend(prev_len, ans);
    	prev_len = ans.length();
    	
    	HashInterval CI(s);
    	
    	// Compare prefixes of new word with suffixes of ans
    	int addition = 0;
    	for (int j = 0; j < s.length(); j++) {
    		if (prev_len - j - 1 < 0) break;
    		
    		if (CI.hashInterval(0, j + 1) == 
    			AI.hashInterval(prev_len - j - 1, prev_len)
    		) {
    			addition = j + 1;
    		}
    	}
    	
    	
    	ans += s.substr(addition, string::npos);
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
