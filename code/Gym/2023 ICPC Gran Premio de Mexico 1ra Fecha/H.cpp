// Problem: H. Hell or paradise?
// Contest: Codeforces - 2023 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/104375/problem/H
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
// #define int ll
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


ll dp[100001];
int n, m;

void solve() {
    cin >> n;
    vector<vector<H>> words(100001);
    vector<vector<pair<H, int>>> modded(100001);
    fill_n(&dp[0], 100001, 0);
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        HashInterval S(s);
        
        words[s.length()].pb(S.hashInterval(0, (int)s.length()));
    }
    
    for (int i = 1; i <= 100000; i++) {
        sort(words[i].begin(), words[i].end());
        
        for (auto& j : words[i]) {
            if (modded[i].empty() or modded[i].back().first != j) {
                modded[i].pb({j, 1});
            }
            else {
                modded[i].back().second++;
            }
        }
    }
    
    string s;
    cin >> s;
    m = s.length();
    dp[0] = 1;
    
    HashInterval S(s);
    vector<int> lens;
    
    for (int i = 1; i <= m; i++) {
        
        if (!words[i].empty()) lens.pb(i);
        
        for (int& j : lens) {
            
            H x = S.hashInterval(i - j, i);
            pair<H, int> target = {x, -1};
            
            auto it = lower_bound(modded[j].begin(), modded[j].end(), target);
            
            if (it != modded[j].end() and it->first == x) {
                ll loc = dp[i-j] * (it->second);
                loc %= MOD;
                dp[i] += loc;
                dp[i] %= MOD;
            }
        }    
    }
    
    cout << dp[m] << ln;
    
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
