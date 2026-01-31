// Problem: Problem 2. Declining Invitations
// Contest: USACO - USACO 2026 Second Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem&cpid=1555
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"

#define ll long long
#define int ll // best line ever <3
#define pb push_back

const int TREE_SIZE = 1 << 20;
pair<int, int> st[2 * TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i].first = x;
	st[i].second = (x!=0);
	
	i>>=1;
	
	while (i) {
		st[i].first = st[2*i].first + st[2*i+1].first;
		st[i].second = st[2*i].second + st[2*i+1].second;
		i>>=1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res += st[l++].first;
		if (!(r&1)) res += st[r--].first;
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

int query2(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res += st[l++].second;
		if (!(r&1)) res += st[r--].second;
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

int binarySearch(int n, int fs) {
	int l = 0, r = n - 1;
	int res = n - 1;
	
	while (l <= r) {
		int m = (l + r) / 2;
		int fm = query2(0, m);
		
		if (fm >= fs) {
			res = min(res, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	
	return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    int fs = 0;
    for (int i = 0; i < c; i++) {
    	int f;
    	cin >> f;
    	fs+= f;
    }
	
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		update(i, i+1);
	}
	
	vector<vector<int>> crit(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			crit[i].pb(y);
		}
	}
	
	for (int i = 0; i < n; i++) {
		// get first idx s.t. query2 returns >= fs
		int L = 0;
		int R = binarySearch(n, fs);
		
		int res = query(L, R);
		cout << res << ln;
		
		update(p[i] - 1, 0);
	}

    return 0;
}
