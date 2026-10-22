// Problem: Permuted Binary Strings
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3228
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

struct Response {
    string s;
};

Response query(vector<int>& q) {
    cout << "? "; for (auto& i : q) cout << i;
    cout << endl;
    string s; cin >> s;
    
    int n = s.length();
    Response r;
    r.s = s;
    
    return r;
}

void solve() {
    int n; cin >> n;
    
    vector<Response> res;
    for (int i = 0; i < 10; i++) {
        vector<int> q(n, 0);
        for (int j = 0; j < n; j++) {
            if (j & (1ll << i)) q[j] = 1;
        }
        
        res.pb(query(q));
    }
    
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 9; j >= 0; j--) {
            s += res[j].s[i];
        }
        
        ans[i] = stoi(s, nullptr, 2) + 1;
    }
    
    cout << "! ";
    for (auto& i : ans) cout << i << " ";
}

signed main() {
    // fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
