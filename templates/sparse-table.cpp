// Usage: SparseTable(array) to build, st.query to query.
// Uses min, but works with any segtree-able function
struct SparseTable {
	vector<vector<int>> st;
	int k;
	
	
	SparseTable(vector<int>& a) {
		int n = a.size();
		k = __lg(n);
		
		st.assign(k + 1, vector<int>(n));
		
		for (int i = 0; i < n; i++) {
			st[0][i] = a[i];
		}
		
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j + (1<<i) <= n; j++) {
				st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
			}
		}
	}
	
	int query(int l, int r) {
		int i = __lg(r - l + 1);
		
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};