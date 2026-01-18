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
    int ans = -1;
    string s;
    cin >> s;
    for (auto& i : s) {
    	if (i == '(') i = '0';
    	if (i == ')') i = '1'; 
    }
    
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n;i++) {
    	p[i+1] = p[i] + (s[i] == '0');
    }
    
   for (int i = 0; i < n - 1; i++) {
   		if (s[i] == '1' and s[i+1] == '0' and (p[n] - p[i+2] > 0)) {
   			cout << n - 2 << ln;
   			return;
   		} 
   }
    
    cout << -1 << ln;
    
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
