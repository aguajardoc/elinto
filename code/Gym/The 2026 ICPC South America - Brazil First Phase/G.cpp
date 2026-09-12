// Problem: G. Genes
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/G
// Memory Limit: 1024 MB
// Time Limit: 5500 ms
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

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

const int K = 17;
const int N = 100001;
string genes[500001];
unordered_map<ull, int> buckets[1001];

void work(vector<vector<int>>& st, vector<int>& og) {

    copy(og.begin(), og.end(), st[0].begin());

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

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


void solve() {
    string s;
    cin >> s;
    int ls = s.length();    
    int n;
    cin >> n;
    vector<int> sizes;
    sizes.reserve(500001);
    
    for (int i = 0; i < n; i++) {
        string t; cin >> t; sizes.pb(t.size());
        genes[i] = t;
    }
    sort(sizes.begin(), sizes.end());
    sizes.resize(unique(sizes.begin(), sizes.end()) - sizes.begin());
    
    int m = sizes.size();
    int q;
    cin >> q;
    vector<int> ans(q, 1e9);
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    for (int i = 0; i < n; i++) {
        string t = genes[i];
        if (t.length() > ls) continue;
        HashInterval H(t);
        ull hash = H.hashInterval(0, t.size()).x;
        int idx = lower_bound(sizes.begin(), sizes.end(), t.size()) - sizes.begin();
        // dbg(hash, idx);
        buckets[idx][hash] = i;
    }
    
    HashInterval HS(s);
    
    for (int i = 0; i < m; i++) {
        int len = sizes[i];
        vector<int> og(ls, 1e9);
        
        for (int j = 0; j + len <= ls; j++) {
            ull hash = HS.hashInterval(j, j + len).x;
            // dbg(hash);
            if (buckets[i].count(hash)) {
                // dbg(len, j);
                og[j] = buckets[i][hash];
            }
        }
        
        vector<vector<int>> st(18, vector<int>(100001, 1e9));
        work(st, og);
        
        for (int j = 0; j < q; j++) {
            int l = queries[j].first-1, r = queries[j].second - sizes[i];
            if (r < l) continue;
            int idx = log2_floor(r - l + 1);
            int minimum = min(st[idx][l], st[idx][r - (1 << idx) + 1]);
            ans[j] = min(ans[j], minimum);
        }
    }
    
    for (auto& i : ans) cout << (i == (int)1e9 ? -1:i+1) << ln;
    
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
