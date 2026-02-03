// Problem: Phone List
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PHONELST/
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

struct Vertex {
	int nxt[10];
	bool ends = false;
	
	Vertex() {
		fill(nxt, nxt + 10, -1);
	}
};

bool addNum(string s, vector<Vertex>& trie) {
	int v = 0;
	
	for (auto& c : s) {
		int i = c - '0';
		
		if (trie[v].nxt[i] == -1) {
			trie[v].nxt[i] = trie.size();
			trie.pb(Vertex());
		}
		
		v = trie[v].nxt[i];
		if (trie[v].ends) return false;
	}
	
	trie[v].ends = true;
	
	return true;
}

void solve() {
    // trie, if we reach one where ends is already true, inconsistent!
    int n;
    cin >> n;
    vector<Vertex> trie(1);
    bool poss = true;
    
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
    	cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++) {
    	poss &= addNum(nums[i], trie);
    }
    
    cout << (poss ? "YES":"NO") << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
