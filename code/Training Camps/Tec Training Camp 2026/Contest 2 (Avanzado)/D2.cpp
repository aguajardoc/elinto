// Problem: D. Loppinha, the boy who likes sopinha
// Contest: Codeforces - TC Tec 2026 Contest 2 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690950/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

vector<int> gauss(451, 0);

vector<int> get_next(vector<int> a) {
	vector<int> b(4);
	
	int og = a[1];
	int cuts = a[2];
	
	int R = (og - cuts);
	
	int Q = R / (cuts + 1);
	int REM = R % (cuts + 1);
	
	int P = (REM * gauss[Q + 1]) + ((cuts + 1 - REM) * gauss[Q]);
	int diff = a[3] - P;
	
	return {diff, og, cuts + 1, P};
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= 450; i++) {
    	gauss[i] = (i * (i + 1)) / 2;
    }
    
    priority_queue<vector<int>> pq;
    
    vector<int> cuts;
    int cons = 0;
    string s;
    cin >> s;
    s += '0';
    
    for (auto& i : s) {
    	if (i == '1') {
    		cons++;
    	}
    	else {
    		if (cons) cuts.pb(cons);
    		cons = 0;
    	}
    }
    
    int cur = 0;
    for (auto& i : cuts) {
    	pq.push(get_next({0, i, 1, gauss[i]}));
    	
    	cur += gauss[i];
    }
    
    int ans = 0;
    while (cur > k) {
    	cur -= pq.top()[0];
    	vector<int> x = pq.top();
    	pq.pop();
    	ans++;
    	pq.push(get_next(x));
    }
    
    cout << ans << ln;
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
