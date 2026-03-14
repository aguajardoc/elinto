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

void solve() {
    int n;
    cin >> n;
    
    vector<string> AM(n);
    vector<set<int>> AL(n), AL2(n);
    
    queue<int> q;
    vector<string> match(n, string(n, '0'));
    bool poss = true;
    int root = -1;
    
    // dbg(n);
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	
    	if (count(s.begin(), s.end(), '1') == 1 and s[i] == '1') {
    		q.push(i);
    		match[i][i] = '1';
    	}
    	else if (s[i] != '1') {
    		poss = false;
    	}
    	else if (count(s.begin(), s.end(), '0') == 0) {
    		if (root != -1) {
    			poss = false;
    		}
    		else {
    			root = i;
    		}
    	}
    	
    	AM[i] = s;
    }
    
    // if (root == -1) poss = false;
    
    if (!poss) {
    	cout << "No" << ln;
    	return;
    }
    
    // dbg(q.size());
    int edgeCt = 0;
    
    while (!q.empty() and edgeCt < n - 1) {
    	int u = q.front();
    	q.pop();
    	
    	// Get one that conns to it
    	int v = -1;
    	int minimal = INF;
    	int amct = count(AM[u].begin(), AM[u].end(), '1');
    	for (int i = 0; i < n; i++) {
    		if (AL[i].count(u)) continue;
    		AM[i][i] = '0';
    		
    		bool lc = true;
    		int ct = count(AM[i].begin(), AM[i].end(), '1');
    		for (int j = 0; j < n; j++) {
    			if (AM[i][j] == '0' and match[u][j] == '1') {
    				lc = false;
    			}
    		}
    		
    		AM[i][i] = '1';
    		if (!lc) continue;
    		// dbg(ct, amct);
    		// dbg(i, u);
    		// dbg(AM[i]);
    		// dbg(AM[u]);
    		if (ct < amct) continue;
    		
    		if (ct < minimal) {
    			v = i;
    			minimal = ct;
    		}
    		AM[i][i] = '1';
    	}
    	
    	// dbg(u, v);
    	// cout << ln;
    	
    	if (v == -1) {
    		continue;
    	}
    	
    	AL[v].insert(u);
    	AL2[u].insert(v);
    	AL2[v].insert(u);
    	edgeCt++;
    	for (int i = 0; i < n; i++) {
    		if (match[u][i] == '1') match[v][i] = '1';
    	}
    	match[v][v] = '1';
    	q.push(v);
    	q.push(u);
    	
    }
    
    // dbg(poss);
    
    if (edgeCt != n - 1) poss = false;
    // dbg(edgeCt);
    if (!poss) {
    	cout << "No" << ln;
    	return;
    }
    
    // vector<int> visited(n, 0);
    // visited[root] = true;
    // queue<int> nq;
    // nq.push(root);
//     
    // while (!nq.empty() and poss) {
    	// int u = nq.front();
    	// nq.pop();
//     	
    	// for (auto& v : AL[u]) {
    		// if (visited[v]) {
    			// poss = false;
    			// break;
    		// }
//     		
    		// visited[v] = true;
    		// nq.push(v);
    	// }
    // }
    
    // if (count(visited.begin(), visited.end(), false)) {
    	// poss = false;
    // }
    
    for (auto& i : AL2) {
    	if (i.empty()) poss = false;
    }
    
    for (int i = 0; i < n; i++) {
    	AM[i][i] = '1';
    	// dbg(AM[i], match[i]);
    	if (AM[i] != match[i]) poss = false;
    }
    
    // dbg(poss);
    
    if (!poss) {
    	cout << "No" << ln;
    	return;
    }
    
    // dbg(poss);
    
    cout << "Yes" << ln;
    for (int i= 0; i < n; i++) {
    	for (auto& v : AL[i]) {
    		cout << i+1 << " " << v+1 << ln;
    	}
    }
    
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
