// Problem: 10462 - Is There A Second Way Left?
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1403
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

struct Edge {
	int u, v, w, x;
	bool operator < (const Edge& a) const  {
		if (w != a.w) return w < a.w;
		if (u != a.u) return u < a.u;
		if (v != a.v) return v < a.v;
		return x < a.x;
	}
	bool operator ==(const Edge& a) const {
		return (u == a.u and v == a.v and w == a.w and x == a.x);
	}
};

int kruskal(vector<Edge> EL, int n, vector<Edge>& res) {
	vector<int> id(n, 0);
	int cost = 0;
	iota(id.begin(), id.end(), 0);
	sort(EL.begin(), EL.end());
	
	for (Edge& e : EL) {
		if (id[e.u] == id[e.v]) continue;
		
		cost += e.w;
		res.push_back(e);
		int old_id = id[e.u];
		int new_id = id[e.v];
		
		for (int i = 0; i < n; i++) {
			if (id[i] == old_id) id[i] = new_id;
		}
	}

	for (int i = 1; i < n; i++) {
		if (id[i] != id[i-1]) return -1;
	}
	
	return cost;
}

void print(vector<Edge>& a) {
	for (Edge& e : a) {
		dbg(e.u, e.v, e.w, e.x);
	}
	cout << ln;
}

void solve(int caseN) {
    int n, m;
    cin >> n >> m;
    
    if (n == 1 and m == 0) {
    	cout << "Case #" << caseN << " : No second way" << ln;
    	return; 
    }
    
    map<Edge, int> ctEdge;
    
    vector<Edge> EL(m);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	EL[i] = {u, v, w, 0};
    	EL[i].x = ctEdge[EL[i]]++;
    }
    
    if (n == 1) {
    	cout << "Case #" << caseN << " : No second way" << ln;
    	return; 
    }
    
    // First MST
    vector<Edge> bestRes;
    int bestCost = kruskal(EL, n, bestRes);
    
    if (bestCost == -1) {
    	cout << "Case #" << caseN << " : No way" << ln;
    	return; 
    }
    
    // Second MST
    int secondBest = 1e9;
    for (int i = 0; i < m; i++) {
    	// dbg(i);
    	// Remove this one
    	vector<Edge> altered;
    	for (int j = 0; j < i; j++) altered.push_back(EL[j]);
    	for (int j = i + 1; j < m; j++) altered.push_back(EL[j]);    	
		vector<Edge> extra;
    	int local = kruskal(altered, n, extra);
    	
    	// print(extra);
    	// print(bestRes);
    	
    	if (local != -1 and extra != bestRes) {
    		secondBest = min(secondBest, local);
    	}
    }
    
    if (secondBest == 1e9) {
    	cout << "Case #" << caseN << " : No second way" << ln;
    	return; 
    }
    
    cout << "Case #" << caseN << " : " << secondBest << ln;
    return; 
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
