// Problem: 1556 - Disk Tree
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4331
// Memory Limit: 32 MB
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

struct Vertex {
	map<string, int> nxt;
	bool ends = false;
	
	Vertex() {
		
	}
};

vector<string> parse(string s) {
	s += '\\';
	vector<string> seq;
	string cur;
	for (char& i : s) {
		if (i == '\\') {
			seq.pb(cur);
			cur.clear();
		}
		else cur += i;
	}
	
	return seq;
}

void add_seq(vector<Vertex>& trie, vector<string> parsed) {
	int v = 0;
	for (string& s : parsed) {
		if (trie[v].nxt.count(s)) {
			v = trie[v].nxt[s];
			continue;
		}
		
		trie[v].nxt[s] = trie.size();
		v = trie.size();
		trie.pb(Vertex());
	}
}

void dfs(vector<Vertex>& trie, int u, int depth) {
	for (const pair<string, int>& x : trie[u].nxt) {
		cout << string(depth, ' ') << x.first << ln;
		dfs(trie, x.second, depth + 1);
	}
}

void solve() {
    int n;
    while(cin >> n) {
    	vector<Vertex> trie(1);
    	
    	for (int i = 0; i < n; i++) {
    		string s;
    		cin >> s;
    		vector<string> parsed = parse(s);
    		
    		add_seq(trie, parsed);
    	}
    	
    	// print
    	dfs(trie, 0, 0);
    	cout << ln;
    }
    cin.ignore();
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
