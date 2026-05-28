// Problem: 1002. Phone Numbers
// Contest: Timus Online Judge - Central European Olympiad in Informatics 1999
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1002
// Memory Limit: 64 MB
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

int num_val[26] = {2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};

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
	HashInterval() {}
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
    while (cin >> s and (s != "-1")) {
    	int n;
    	cin >> n;
    	int m = s.length();
    	
    	HashInterval SH(s);
    	
    	vector<string> words(n), translation(n);
    	vector<HashInterval> words_hash(n);
    	for (int i = 0; i < n; i++) {
    		cin >> words[i];
    		for (auto& j : words[i]) {
    			translation[i] += (num_val[j - 'a'] + '0');
    		}
    		words_hash[i] = HashInterval(translation[i]);
    	}
    	
    	vector<vector<pair<int, int>>> AL(m + 1);
    	
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			int len = words[j].length();
    			int k = i + len;
    			if (k > m) continue;
    			
    			H L = SH.hashInterval(i, k);
    			H R = words_hash[j].hashInterval(0, len);
    			
    			// dbg(i, k);
    			// dbg(0, len);
    			
    			if (L == R) {
    				AL[i].pb({k, j});
    			}
    		}
    	}
    	
    	queue<int> q;
    	q.push(0);
    	vector<int> visited(m + 1, 0), parent(m + 1, -1), wp(m + 1, 0);
    	
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		
    		for (auto& [v, widx] : AL[u]) {
    			if (visited[v]) continue;
    			
    			visited[v] = true;
    			parent[v] = u;
    			wp[v] = widx;
    			
    			
    			q.push(v);
    		}
    	}
    	
    	if (!visited[m]) {
    		cout << "No solution." << ln;
    	}
    	else {
    		int cur = m;
    		vector<string> res;
    		while (cur != 0) {
    			res.pb(words[wp[cur]]);
    			cur = parent[cur];
    		}
    		reverse(res.begin(), res.end());
    		for (auto& i : res) {
    			cout << i << " ";
    		}
    		cout << ln;
    	}
    	
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
