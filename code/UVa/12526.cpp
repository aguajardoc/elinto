// Problem: 12526 - Cellphone Typing
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3971
// Memory Limit: 32 MB
// Time Limit: 5000 ms
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

struct Vertex {
	int nxt[26];
	int continues = 0;
	bool ends = false;
	
	Vertex() {
		fill(nxt, nxt + 26, -1);
	}
};

void add_string(string s, vector<Vertex>& trie) {
	int v = 0;
	for (char& c : s) {
		int i = c - 'a';
		if (trie[v].nxt[i] == -1) {
			trie[v].nxt[i] = trie.size();
			trie.pb(Vertex());
		}
		
		v = trie[v].nxt[i];
		trie[v].continues++;
	}
	
	trie[v].ends = true;
}

int ans = 0;

void dfs(int u, int depth, vector<Vertex>& trie) {
	
	if (trie[u].continues == 1 or trie[u].ends) {
		// dbg(u, depth);
		ans += depth;
		if (trie[u].continues == 1) return;
	}
	
	for (int i = 0; i < 26; i++) {
		if (trie[u].nxt[i] == -1) continue;
		
		int cost = 1;
		if (trie[u].continues == trie[trie[u].nxt[i]].continues) cost = 0;
		
		dfs(trie[u].nxt[i], depth + cost, trie);
	}
}

void solve() {
    int n;
    while(cin >> n) {
    	vector<Vertex> trie(1);
    	
    	for (int i = 0 ; i < n; i++) {
    		string s;
    		cin >> s;
    		
    		add_string(s, trie);
    	}
    	
    	ans = 0;
    	dfs(0, 0, trie);
    	// dbg(ans);
    	int res = round(1.0*100 * ans / n);
    	string x = to_string(res);
    	cout << x[0] << '.' << x[1] << x[2] << ln;
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
