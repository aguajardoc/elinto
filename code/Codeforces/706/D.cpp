// Problem: D. Vasiliy's Multiset
// Contest: Codeforces - Codeforces Round 367 (Div. 2)
// URL: https://codeforces.com/contest/706/problem/D
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

struct Vertex {
	int nxt[2];
	int ends = 0;
	
	Vertex() {
		nxt[0] = -1;
		nxt[1] = -1;
	}
};

vector<Vertex> trie(1);

void updateNum(int x, bool adding) {
	int v = 0;
	for (int i = 32; i >= 0; i--) {
		bool k = (x & (1ll << i));
		if (trie[v].nxt[k] == -1) {
			trie[v].nxt[k] = trie.size();
			v = trie.size();
			trie.pb(Vertex());
		}
		else v = trie[v].nxt[k];
		
		if (adding) trie[v].ends++;
		else trie[v].ends--;
	}
}

int getMaxXor(int x) {
	int best = 0;
	
	int v = 0;
	for (int i = 32; i >= 0; i--) {
		bool k = (x & (1ll << i));
		
		int looking = 1 - k;
		
		if (trie[v].nxt[looking] == -1 or trie[trie[v].nxt[looking]].ends == 0) {
			v = trie[v].nxt[k];
		}
		else {
			v = trie[v].nxt[looking];
			best |= (1ll << i);
		}
	}
	
	return best;
}

void solve() {
    int n;
    cin >> n;
    
    updateNum(0, true);
    
    for (int i = 0; i < n; i++) {
    	char type; int x;
    	cin >> type >> x;
    	
    	if (type == '+') updateNum(x, true);
    	else if (type == '-') updateNum(x, false);
    	else if (type == '?') cout << getMaxXor(x) << ln;
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