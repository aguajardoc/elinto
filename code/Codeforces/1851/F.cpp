// Problem: F. Lisa and the Martians
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/F
// Memory Limit: 512 MB
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

int n,k;
int bestDiv;
int bestAns;
int Lidx, Ridx;
vector<int> a;

struct Node {
	int next[2] = {-1, -1};
	int end = -1;
};

struct Trie {
	vector<Node> trie;
	
	Trie() {
		trie.pb(Node());
	}
	
	void add(int x, int idx) {
		int cur = 0;
		int res = INF;
		bool diverted = false;
		
		for (int i = k; i >= 0; i--) {
			int v = (x & (1ll << i));
			v = min(v, 1ll);
			
			if (trie[cur].next[v] == -1) {
				trie[cur].next[v] = trie.size();
				trie.pb(Node());
				
				// Found better answer
				if (i <= bestDiv and not diverted and trie[cur].next[1-v] != -1) {
					bestDiv = i;
					diverted = true;
					// Go down the other path and retrieve node
					
					int oth = trie[trie[cur].next[1-v]].end;
					
					res = x ^ a[oth];
					
					if (res < bestAns) {
						Lidx = oth;
						Ridx = idx;
						bestAns = res;
					}
				}
			}
			
			cur = trie[cur].next[v];
			trie[cur].end = idx;
		}
		
		trie[cur].end = idx;
	
	}
};

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    bestDiv = INF;
    bestAns = INF;
    
    Trie trie;
    map<int, int> checked;
    
    for (int i = 0; i < n; i++) {
    	trie.add(a[i], i);
    	
    	if (checked.count(a[i])) {
    		cout << checked[a[i]]+1 << " " << i + 1 << " " << (((1ll << k) - 1) ^ (a[i])) << ln;
    		return;
    	}
    	
    	checked[a[i]] = i;
    }
    
    int x = 0;
    for (int i = k-1; i >= 0; i--) {
    	if (!(a[Lidx] & (1ll << i))) {
    		x ^= (1ll << i);
    	}
    }
    
    cout << Lidx+1 << " " << Ridx+1 << " " << x << ln;
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
