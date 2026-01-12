// Problem: C. Sereja and Brackets
// Contest: Codeforces - Codeforces Round 223 (Div. 1)
// URL: https://codeforces.com/contest/380/problem/C
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int TREE_SIZE = 1 << 20;

int st[2 * TREE_SIZE][3];

void update(int i, int x) {
	i += TREE_SIZE;
	if (x == 0) {
		st[i][0] = 0;
		st[i][1] = 0;
		st[i][2] = 1;
	}
	else {
		st[i][0] = 0;
		st[i][1] = 1;
		st[i][2] = 0;
	}
	i >>= 1;
	
	while(i) {
		auto& left = st[2*i];
		auto& right = st[2*i + 1];
		
		int nm = min(left[1], right[2]);
		
		int res[3] = {left[0] + right[0] + 2 * nm, left[1] + right[1] - nm, left[2] + right[2] - nm};
		st[i][0] = res[0];
		st[i][1] = res[1];
		st[i][2] = res[2];
		
		i >>= 1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int lres[3] = {0, 0, 0};
	int rres[3] = {0, 0, 0};
	int res[3] = {0, 0, 0};
	
	while (l <= r) {
		// dbg(l);
		// dbg(r);
		if (l&1) {
			int nm = min(lres[1], st[l][2]);
			
			lres[0] += st[l][0] + 2 * nm;
			lres[1] = st[l][1] + lres[1] - nm;
			lres[2] = st[l][2] + lres[2] - nm;
			
			l++;
		}
		if (!(r&1)) {
			int nm = min(rres[2], st[r][1]);
			
			rres[0] += st[r][0] + 2 * nm;
			rres[1] = rres[1] + st[r][1] - nm;
			rres[2] = rres[2] + st[r][2] - nm;
			
			r--;
		}
		
		l>>=1;
		r>>=1;
	}
	
	int nm = min(lres[1], rres[2]);
	
	res[0] = lres[0] + rres[0] + 2 * nm;
	res[1] = lres[1] + rres[1] - nm;
	res[2] = lres[2] + rres[2] - nm;
	
	return res[0];
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
    	if (s[i] == '(') update(i, 1);
    	if (s[i] == ')') update(i, 0);
    }
    
    int q;
    cin >> q;
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	
    	cout << query(l, r) << ln;
    }
}

signed main() {
    fast_cin();
    
    for (auto& i : st) {
    	i[0] = 0;
    	i[1] = 0;
    	i[2] = 0;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
