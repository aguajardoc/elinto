// Problem: I. Inspecting Spells
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize ("Ofast, unroll-loops")
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
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64);
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11+3;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(str.size()+1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); i++) {
			ha[i+1] = ha[i] * C + str[i];
			pw[i+1] = pw[i] * C;
		}
	}
	H hashInterval(int a, int b) {
		return ha[b] - ha[a] * pw[b - a];
	}
};

void clean(vector<ull>& x) {
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
}

bool visited[1002];

void solve() {
	int n;
	cin >> n;
	vector<ull> prefixes, suffixes, FW;
	
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int k = t.length();
		
		HashInterval T(t);
		
		for (int j = 0; j < k; j++) {
			prefixes.pb(T.hashInterval(0, j + 1).x);
			suffixes.pb(T.hashInterval(k - j - 1, k).x);
		}
		FW.pb(T.hashInterval(0, k).x);
	}
	clean(prefixes);
	clean(suffixes);
	clean(FW);
	
	string s;
	cin >> s;
	int m = s.length();
	HashInterval S(s);
	vector<vector<int>> AL(m + 67);
	
	for (int i = 0; i < m; i++) {
		// prefix of S matches any suffix -> 0 to i + 1
		ull v = S.hashInterval(0, i + 1).x;
		
		if (*lower_bound(suffixes.begin(), suffixes.end(), v) == v) {
			AL[0].pb(i + 1);
		}
		
		// suffix of S matches any prefix -> i to m
		v = S.hashInterval(m-i-1, m).x;
		
		if (*lower_bound(prefixes.begin(), prefixes.end(), v) == v) {
			AL[m-i-1].pb(m);
		}
		
		// all other intervals -> i to j + 1
		for (int j = i; j < m; j++) {
			v = S.hashInterval(i, j+1).x;
			
			if (*lower_bound(FW.begin(), FW.end(), v) == v) {
				AL[i].pb(j+1);
			}
		}
	}
	
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (auto& v : AL[u]) {
			if (visited[v]) continue;
			
			visited[v] = 1;
			q.push(v);
		}
	}
	
	cout << (visited[m] ? "YES":"NO") << ln;
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
