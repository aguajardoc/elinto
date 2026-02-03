// Problem: D. Safe
// Contest: Codeforces - Codeforces Beta Round 44 (Div. 2)
// URL: https://codeforces.com/contest/47/problem/D
// Memory Limit: 256 MB
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
	long nxt[2];
	char ends = 0;
	
	Vertex() {
		fill(nxt, nxt + 2, -1);
	}
};

Vertex trie[21'750'000];

int n, m;
int last = 1;

void addNum(string s) {
	int v = 0;
	for (auto& c : s) {
		int i = c - '0';
		
		if (trie[v].nxt[i] == -1) {
			trie[v].nxt[i] = last++;
		}
		
		v = trie[v].nxt[i];
	}
	trie[v].ends++;
}

int ans = 0;

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
    	string s;
    	int correct;
    	cin >> s >> correct;
    	string t(n, '1');
    	for (int k = 0; k < correct; k++) {
    		t[k] = '0';
    	}
    	
    	do {
    		// dbg(t);
    		string q;
    		for (int j = 0; j < n; j++) {
    			if (t[j] == '1') q += s[j];
    			else {
    				if (s[j] == '0') q += '1';
    				else q += '0';
    			}
    		}
    		addNum(q);
    	} while (next_permutation(t.begin(), t.end()));
    	
    	// cout << ln;
    }
    
    // cout << trie.size() << ln;
    for (auto& i : trie) {
    	if (i.ends == m) ans++;
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
