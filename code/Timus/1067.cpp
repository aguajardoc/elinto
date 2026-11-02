// Problem: 1067. Disk Tree
// Contest: Timus Online Judge - 2000-2001 ACM Northeastern European Regional Programming Contest
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1067
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Node {
	string path;
	map<string, int> nxt;
	Node(string s) {
		path = s;
	}
	Node() {
		
	}
};

string get_path(string& s, int& pt) {
	string res;
	while (s[pt] != '\\') {
		res += s[pt++];
	}
	pt++;
	
	return res;
}

struct Trie {
	vector<Node> t;
	
	Trie() {
		t.pb(Node());	
	}
	
	void add_entry(string s) {
		int node = 0;
		int pt = 0;
		
		while (pt != s.length()) {
			string cur = get_path(s, pt);
			
			if (!t[node].nxt.count(cur)) {
				t[node].nxt[cur] = t.size();
				t.pb(cur);
			}
			
			node = t[node].nxt[cur];
		}
	}
	
	void dfs(int u, int& depth) {
		if (depth) {
			cout << string(depth-1, ' ') << t[u].path << ln;
		}
		
		for (auto& [x, v] : t[u].nxt) {
			depth++;
			dfs(v, depth);
			depth--;
		}
	}
};

void solve() {
    int n; cin >> n;
    Trie t;
    for (int i = 0; i < n; i++) {
    	string s; cin >> s;
    	s += '\\';
    	t.add_entry(s);
    }
    
    int d = 0;
    t.dfs(0, d);
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
