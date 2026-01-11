// Problem: 12299 - RMQ with Shifts
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3720
// Memory Limit: 32 MB
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

const int TREE_SIZE = 1 << 20;

int st[2 * TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] = x;
	i >>= 1;
	while(i) {
		st[i] = min(st[2*i], st[2*i + 1]);
		i>>=1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 1e9;
	while (l <= r) {
		if (l&1) res = min(res, st[l++]);
		if (!(r&1)) res = min(res, st[r--]);
		
		l>>=1;
		r>>=1;
	}
	
	return res;
}

pair<int, vector<int>> getQuery() {
	pair<int, vector<int>> res;
	string s;
	cin >> s;
	if (s[0] == 'q') res.first = 0;
	else res.first = 1;
	
	string cur;
	for (int i = 5; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			if (cur.empty()) continue;
			res.second.pb(stoll(cur));
			cur.clear();
		}
		else cur += s[i];
	}
	
	return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	update(i, x);
    }
    
    cin.ignore();
    while (q--) {
    	pair<int, vector<int>> v = getQuery();
    	
    	if (v.first == 0) {
    		cout << query(v.second[0] - 1, v.second[1] - 1) << ln;
    	}
    	else {
    		int k = v.second.size();
    		vector<int> prev;
    		for (int i = 0; i < k; i++) {
    			prev.pb(query(v.second[i] - 1, v.second[i] - 1));
    		}
    		
    		for (int i = 0; i < k; i++) {
    			update(v.second[i] - 1, prev[(i + 1) % k]);
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
