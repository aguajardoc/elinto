// Problem: J. Jamboree
// Contest: Codeforces - 2023-2024 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2023)
// URL: https://codeforces.com/gym/105427/problem/J
// Memory Limit: 512 MB
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



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(a.size() <= m){
    	cout << a.back() << '\n';
    	return;
    }
    
    vector<int> tienen(m, 0);
    for(int i = 0; i<m; i++){
    	tienen[i] = a.back();
    	a.pop_back();
    }
    
    sort(tienen.begin(), tienen.end());
    sort(a.begin(), a.end(), greater<int>());
    
    for(int i = 0; i<a.size(); i++){
    	tienen[i] += a[i];
    }

	int ans = 0;
	for(int i = 0; i<tienen.size(); i++){
		ans = max(tienen[i], ans);
	}
	cout << ans << '\n';
	return;
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
