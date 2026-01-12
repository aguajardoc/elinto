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

vector<vector<int>> AL;
vector<int> cherries, visited;
map<int, int> chct;
int leafct = 0;
bool ans = false;

int dfs(int u, bool redux=false) {
	bool hasChild = false;
	visited[u] = true;
	
	if (redux) {
		// check if any comb does it!
		// for (auto& i : chct) {
			// dbg(i.first, i.second);
		// }
		if (leafct % 3 == 1) {
			if (chct[2] > 0 or (chct[0] > 1)) ans = true;
		}
		else if (leafct % 3 == 2) {
			if (chct[0] > 0 or (chct[2] > 1)) ans = true;
		}
	}
	
	int res = 0;
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		if (redux) {
			if(cherries[v] != -1 and !--chct[cherries[v]%3]) chct.erase(cherries[v]%3);
		}
		hasChild = true;
		res += dfs(v, redux);
	}
	
	if (!hasChild) {
		if (!redux)leafct++;
		return 1;
	}
	else {
		
		if (redux and res)chct[res%3]++;
		return cherries[u] = res;
	}
}


void solve() {
    int n;
	cin >> n;
	AL.assign(n, vector<int>());
	cherries.assign(n, 0);
	visited.assign(n, 0);
	chct.clear();
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		AL[u].pb(v);
		AL[v].pb(u);
	}
	leafct = 0;
	
	dfs(0);
	
	if (leafct < 3) {
		cout << "NO" << ln;
		return;
	}
	
	if (leafct % 3 == 0) {
		cout << "YES" << ln;
		return;
	}
	
	cherries.assign(n, -1);
	visited.assign(n, 0);
	ans = false;
	dfs(0, true);
	
	
	cout << (ans ? "YES":"NO") << ln;
	
	
	return;
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
