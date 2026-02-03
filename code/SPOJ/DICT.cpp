// Problem: Search in the dictionary!
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/DICT/
// Memory Limit: 1536 MB
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

struct Node {
	char letter = '$';
	Node* follows[26];
	bool ends = false;
	
	Node(char x, bool f) {
		letter = x;
		ends = f;
		fill_n(&follows[0], 26, nullptr);
	}
	
	Node () {
		fill_n(&follows[0], 26, nullptr);
	}
	
	~Node() {
	    for (int i = 0; i < 26; i++) {
	        delete follows[i];
	    }
	}

};

struct Trie {
	Node start;
	
	// Add word
	void addWord(string s) {
		// Iterate over the string
		int n = s.length();
		Node* cur = &start;
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			// If it already follows, go, else create
			if (cur->follows[c] == nullptr) {
				cur->follows[c] = new Node(s[i], false);
			}
			
			cur = cur->follows[c];
		}
		
		cur->ends = true;
	}
	
	void recurse(Node* cur, string& cs, vector<string>& res) {
		if (cur->ends) {
			res.pb(cs);
		}
		
		for (int i = 0; i < 26; i++) {
			if (cur->follows[i] != nullptr) {
				cs += (i + 'a');
				recurse(cur->follows[i], cs, res);
				cs.pop_back();
			}
		}
	}
	
	// Get all words with that prefix
	vector<string> getWithPrefix(string s) {
		vector<string> res;
		
		int n = s.length();
		Node* cur = &start;
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			if (cur->follows[c] == nullptr) {
				return res;
			}
			
			cur = cur->follows[c];
		}
		
		// Now backtrack over all possibilities
		string cs = s;
		recurse(cur, cs, res);
		
		return res;
	}
	
};

void solve() {
    int n;
    cin >> n;
    
    Trie trie;
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	
    	trie.addWord(s);
    }
    
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
    	string s;
    	cin >> s;
    	vector<string> res = trie.getWithPrefix(s);
    	sort(res.begin(), res.end());
    	cout << "Case #" << i << ":\n";
    	if (res.empty() or (res.size() == 1 and res[0] == s)) {
    		cout << "No match.\n";
    	}
    	else {
    		for (auto& j : res) {
    			if (j != s)
    			cout << j << ln;
    		}
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
