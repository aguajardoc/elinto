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

bool touches(vector<int> A, vector<int> B) {
	if (A[0] == B[0] and A[1] == B[1] and A[2] != B[2]) return false;
	int D = ((A[1] - B[1]) * (A[1] - B[1]) - 4ll * (A[0] - B[0]) * (A[2] - B[2]));
	// dbg(D);
	return (D > 0);
}

vector<int> visited;
int res = 0;
void dfs(int& king, int u, int len, vector<vector<int>>& AL) {
	visited[u] = 1;
	
	for (auto& v : AL[u]) {
		if (visited[v]) {
			// dbg(v, len);
			if (v == king) res = min(res, len+1);
			
			continue;
		}
		
		dfs(king, v, len + 1, AL);
	}
	
	
	
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int> (4, 0));
    for (int i= 0; i < n; i++) {
    	for (int j = 0; j < 3; j++) cin >> a[i][j];
    	a[i][3] = i;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> AL(n);
    
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		if (!touches(a[i], a[j])) {
    			AL[i].pb(j);
    			// AL[j].pb(i);
    		}
    	}
    }
    
    vector<int> ans(n, 0);
    
    for (int i = 0; i < n; i++) {
		res = 0;
		visited.assign(n, 0);
		dfs(i, i, (int)AL[i].size(), AL);
		if(res==0)res=1;
		
		ans[a[i][3]] = res;
    	
    }
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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