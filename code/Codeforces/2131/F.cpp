// Problem: F. Unjust Binary Life
// Contest: Codeforces - Codeforces Round 1042 (Div. 3)
// URL: https://codeforces.com/contest/2131/problem/F
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

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> px(n), py(n);
    
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') z++;
    	else o++;
    	px[i] = z - o;
    }
    z = 0, o = 0;
    for (int i = 0; i < n; i++) {
    	if (t[i] == '0') z++;
    	else o++;
    	py[i] = o - z;
    }
    
    int ans = n * n * n + n * n;
    ans >>= 1;
    
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    
    vector<int> ppy(n+1);
    for (int i = 0; i < n; i++) {
    	ppy[i+1] = ppy[i] + py[i];
    }
    
    int a2 = 0;
    int k = 0, sp = 0;
    for (int i = 0; i < n; i++) {
    	while (k < n and py[k] <= px[i]) k++;
    	
    	a2 += (k * px[i]) - ppy[k];
    	a2 += (ppy[n] - ppy[k]) - ((n - k) * px[i]);
    }
    a2>>= 1;
    
    ans -= a2;
    cout << ans << ln;
    
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
