// Problem: Problem 2. Field Day
// Contest: USACO - USACO 2023 US Open Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=1327
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

void solve() {
    int n, c;
    cin >> c >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	int v = 0;
    	for (int j = 0; j < c; j++) {
    		if (s[j] == 'H') s[j] = '0';
    		else s[j] = '1';
    	}
    	reverse(s.begin(), s.end());
    	v = stoi(s, NULL, 2);
    	
    	vals[i] = v;
    }
    
    queue<int> q;
    vector<int> dist(1<<c, INF);
    for (auto& i : vals) {
    	dist[i] = 0;
    	q.push(i);
    }
    
    while (!q.empty()) {
    	int u = q.front();
    	
    	q.pop();
    	
    	for (int i = 0; i < c; i++) {
    		int v = (u ^ (1ll << i));
    		
    		if (dist[v] != INF) continue;
    		
    		dist[v] = dist[u] + 1;
    		q.push(v);
    	}
    }
    
    for (int i = 0; i < n; i++) {
    	string ns;
    	int nv;
    	for (int j = 0; j < c; j++) {
    		if (vals[i] & (1ll << j)) {
    			ns += '0';
    		}
    		else ns += '1';
    	}
    	reverse(ns.begin(), ns.end());
    	nv = stoi(ns, NULL, 2);
    	// dbg(vals[i], nv);
    	cout << c-dist[nv] << ln;
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
