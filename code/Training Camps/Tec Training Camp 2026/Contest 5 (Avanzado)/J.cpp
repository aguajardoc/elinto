// Problem: J. Vasiliy's Multiset
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/J
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

struct Trie {
	struct Node {
		int count;
		int n[2];
		
		Node() {
			count = 0;
			n[0] = -1, n[1] = -1;
		}
	};
	
	vector<Node> trie;
	
	Trie() {
		trie.pb(Node());
	}
	
	void change_number(int x, int op) {
		int node = 0;
		for (int i = 30; i >= 0; i--) {
			bool val = (x & (1ll << i));
			
			if (trie[node].n[val] == -1) {
				trie[node].n[val] = trie.size();
				trie.pb(Node());
			}
			
			trie[node].count += op;
			node = trie[node].n[val];
		}
		trie[node].count += op;
	}
	
	int query(int x) {
		// dbg(x);
		// for (int i = 0; i <= 30; i++) {
			// x ^= (1ll << i);
		// }
		// dbg(x);
		
		int node = 0;
		int res = 0;
		for (int i = 30; i >= 0; i--) {
			int cur = (x & (1ll << i));
			
			// if exists, we want 0
			// else we want a 1
			int val = (cur == 0);
			
			// if it doesnt exist, dont toggle that bit
			if (trie[node].n[val] == -1 or trie[trie[node].n[val]].count == 0) {
				val ^= 1;
			}
			else res ^= (1ll << i);
			
			node = trie[node].n[val];
		}
		
		return res;
	}
};

void solve() {
	int n;
	cin >> n;  
	
	Trie trie;
	trie.change_number(0, 1);
	
	for (int i = 0; i < n; i++) {
		char type;
		int x;
		cin >> type >> x;
		
		if (type == '+') {
			trie.change_number(x, 1);
		}
		else if (type == '-') {
			trie.change_number(x, -1);
		}
		else {
			cout << trie.query(x) << ln;
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
