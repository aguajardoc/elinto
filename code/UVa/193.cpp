// Problem: 193 - Graph Coloring
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
vector<vector<int>> AL;
int n, k;
vector<int> color, best;
int ans = 0;

bool canBeBlack(int u) {
	for (auto& v : AL[u]) {
		if (color[v] == 1) return false;
	}
	
	return true;
}

void recurse(int idx, int black, vector<int>& blacks) {
	if (idx == n) {
		if (black > ans) {
			ans = black;
			best = blacks;
		}
		return;
	}
	
	if (black + (n - idx) <= ans) return;
	
	if (canBeBlack(idx)) {
		color[idx] = 1;
		blacks.push_back(idx);
		recurse(idx + 1, black + 1, blacks);
		color[idx] = 0;
		blacks.pop_back();
	}
	
	recurse(idx + 1, black, blacks);
	
	return;
}

string magic;

void solve() {
	cin >> n >> k;
	ans = 0;
	AL.assign(n, vector<int>());
	color.assign(n, 0);
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}
	vector<int> blacks;
	recurse(0, 0, blacks);
	// cout << ans << ln;
	
	string path;
	path += to_string(ans) + "\n";
	
	for (auto& i : best) {
		// dbg(i);
		path += to_string(i + 1) + " ";
	}
	path.pop_back();
	magic += path + "\n";
}
     

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    magic.pop_back();
    cout << magic << ln;

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
