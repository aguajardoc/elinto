// Problem: G. Expanding STACKS!
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/G
// Memory Limit: 1024 MB
// Time Limit: 300 ms
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

struct C {
	int enter, leave;
};

void solve() {
    int n;
    cin >> n;
    vector<C> a(n);
    vector<vector<int>> AL(n);
  	for (int i = 0; i < 2*n; i++) {
  		string s;
  		cin >> s;
  		if (s[0] == '+') a[-1+stoi(s.substr(1, string::npos))].enter = i;
  		if (s[0] == '-') a[-1+stoi(s.substr(1, string::npos))].leave = i;
  	}
  	
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			C x = a[i];
  			C y = a[j];
  			
  			if (y.enter < x.leave and y.enter > x.enter and y.leave > x.leave) {
  				AL[i].pb(j);
  				AL[j].pb(i);
  			}
  		}
  	}
  	
  	vector<int> color(n, -1);
  	bool poss = true;
  	for (int i = 0; i < n; i++) {
	  	if (color[i] != -1) continue;
	  	
	  	color[i] = 0;
	  	queue<int> q;
	  	q.push(i);
	  	
	  	while (!q.empty()) {
	  		int u = q.front();
	  		q.pop();
	  		
	  		for (auto& v : AL[u]) {
	  			if (color[v] != -1) {
	  				if (color[v] == color[u]) poss = false;
	  				continue;
	  			}
	  			
	  			color[v] = 1 - color[u];
	  			q.push(v);
	  		}
	  	}
  	}
  	
  	if (!poss) {
  		cout << "*" << ln;
  		return;
  	}
  	
  	for (auto& i : color) {
  		if (i) cout << "S";
  		else cout << "G";
  	}
  	cout << ln;
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
