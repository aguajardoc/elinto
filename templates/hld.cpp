// pair with segtree
// Example: path/subtree set, path/subtree max
struct HLD {
	int n, r, time = 0;
	vector<vector<int>> AL;
	vector<int> pos, size, par, root, dist;
	Segtree st;
	
	HLD(vector<vector<int>>& _AL, int _r) {
		r = _r; AL = _AL; n = AL.size();
		
		pos.assign(n, 0);
		size.assign(n, 1);
		par.assign(n, -1);
		root.assign(n, r);
		dist.assign(n, 0);
		st = Segtree(n);
		
		dfs_sz(r); dfs_hld(r);
	}
	
	void dfs_sz(int u) {
		if (par[u] != -1) {
			AL[u].erase(find(AL[u].begin(), AL[u].end(), par[u]));
		}
		for (auto& v : AL[u]) {
			dist[v] = dist[u] + 1;
			par[v] = u;
			dfs_sz(v);
			size[u] += size[v];
			if (size[v] > size[AL[u][0]]) swap(v, AL[u][0]);
		}
	}
	
	void dfs_hld(int u) {
		pos[u] = time++;
		for (auto& v : AL[u]) {
			root[v] = (v == AL[u][0] ? root[u]:v);
			dfs_hld(v);
		}
	}

    int update_node(int i, int v) {
		return st.update(pos[i], pos[i], v);
	}

    int update_subtree(int i, int v) {
		return st.update(pos[i], pos[i] + size[i] - 1, v);
	}
	
	void update_path(int u, int v, int w) {
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) swap(u, v);
			st.update(pos[root[u]], pos[u], w);	
			u = par[root[u]];
		}
		if (dist[u] > dist[v]) swap(u, v);
		st.update(pos[u], pos[v], w);
	}
	
	int query_node(int i) {
		return st.query(pos[i], pos[i]);
	}

    int query_subtree(int i) {
		return st.query(pos[i], pos[i] + size[i] - 1);
	}

    int query_path(int u, int v) {
		int res = -INF;
		while (root[u] != root[v]) {
			if (dist[root[u]] < dist[root[v]]) swap(u, v);
			res = max(res, st.query(pos[root[u]], pos[u]));	
			u = par[root[u]];
		}
		if (dist[u] > dist[v]) swap(u, v);
		res = max(res, st.query(pos[u], pos[v]));
		return res;
	}
};