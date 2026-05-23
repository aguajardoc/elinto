// Problem: B. Baus Stream
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/B
// Memory Limit: 256 MB
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
// #define int ll
#define ld long double
#define pb push_back

const int INF = INT32_MAX;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

/*
IDEAS

- Maybe like a trie that holds how many exist from now
- Okay that's the easy part but like, how to choose?
- Especially because it's cummulative

9, 9, 7, 5, 5, 5, 3, 2, 1, 1, 1
- say we want 4... take 3 then 1
- we can always take exactly one (!)
- maybe in powers of 2?
- that'd be cool, but i dont think thats it

- okay, the problem reduces to:
- pick a minimal number of unique nodes from 
- a trie such that the sum of their endings 
- is k, considering that picking a T_i affects all
- T_j s.t. T_j is an ancestor of T_i

sion
sionfan
sionbot
run
runner

o -> s(3) -> i(3) -> o(3) -> n(3) -> f(1) -> a(1) -> n(1)
|								 \-> b(1) -> o(1) -> t(1)
|--> r(2) -> u(2) -> n(2) -> n(1) -> e(1) -> r(1)

which can be simplified to

o -> sion(3) -> fan(1)
|			\-> bot(1)
|--> run(2) -> ner(1)

if they are all distinct, then that means
there's always a difference of one between some two
branches, right?

ab
aba
abc
abcd

o -> ab(4) 	 -> a(1)
			\-> c(2) -> d(1)

not strictly, if a word ends now, then diff can be >1
e.g. here we can't do 3 in one

dp over which branches to take?
lower branches affect upper branches soooo
	  o
	  |
	  v
	  4
	 / \
	/   \
	v   v
    1   2
        v
        1
        
yeah just that, and we decide to take (add T_u - cur)
or not, but only if it doesnt exceed k

dp[4][1] = 1
dp[3][1] = 1
dp[3][1 + (2 - 1)] = min(dp[4][1] + 1, 1)

dp[2][1] = 1;
dp[1][1] = 1;
dp[1][2] = 1
dp[1][3] = dp[2][1] + dp[3][2] 
(but how do we know which to take?)

maybe the modelling is not correct but I still think dp

yk, there is exactly one that gets lost

you can never have two strings get lost between forks,
as that would mean the string ends there and has the 
same prefix at the same time, which, if they are 
distinct, cannot happen at all

so what, the answer is one or 2?
no, take the following

		o
		|
		v
		4
	   /|\
	  / | \
	 1  1  1
	 
if k = 3, id have to take three leaves


*/

vector<int> dp[100001];

struct Node {
	int next[26];
	int w;
	
	Node() {
		for (auto& i : next) i = -1;
		w = 0;
	}
};

struct Trie {
	vector<Node> trie;
	
	Trie() {
		trie.pb(Node());
	}
	
	void add_word(string s) {
		int u = 0;
		for (auto& c : s) {
			if (trie[u].next[c-'a'] == -1) {
				trie[u].next[c-'a'] = trie.size();
				trie.pb(Node());
			}
			
			u = trie[u].next[c-'a'];
			trie[u].w++;
		}
	}
};

Trie trie;

void recurse(int u) {
	dp[u].resize(trie.trie[u].w + 1, INF);
	dp[u][0] = 0;
	int cur = 0;
	
	for (auto& v : trie.trie[u].next) {
		if (v == -1) continue;
		recurse(v);	
		
		vector<int> nxt(cur + trie.trie[v].w + 1, INF);
		
		for (int i = 0; i <= cur; i++) {
			for (int j = 0; j <= trie.trie[v].w; j++) {
				nxt[i+j] = min(nxt[i+j],
					dp[u][i] + dp[v][j]
				);
			}
		}
		
		dp[u] = nxt;
		cur += trie.trie[v].w;
	}
	
	dp[u].resize(trie.trie[u].w + 1, INF);
	if (u) dp[u][trie.trie[u].w] = 1;
}


void solve() {
    int n, k;
    cin >> n >> k;
    dp[0].assign(100001, 0);
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	trie.add_word(s);
    }
    
    recurse(0);
    cout << dp[0][k] << ln;
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
