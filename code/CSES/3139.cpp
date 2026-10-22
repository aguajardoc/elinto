// Problem: Hidden Permutation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3139
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

bool query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string s; cin >> s;
    return (s == "YES");
}

vector<int> merge_sort(vector<int> a) {
    int n = a.size();
    if (n == 1) return a;
    int nl = n / 2, nr = n - nl;
    vector<int> L(nl), R(nr);
    
    for (int i = 0; i < n; i++) {
        if (i < nl) L[i] = a[i];
        else R[i-nl] = a[i]; 
    }
    
    L = merge_sort(L);
    R = merge_sort(R);
    
    vector<int> sorted;
    int pl = 0, pr = 0;
    while (pl < nl and pr < nr) {
        if (query(L[pl], R[pr])) {
            sorted.pb(L[pl++]);
        }
        else sorted.pb(R[pr++]);
    }
    
    while (pl < nl) {
        sorted.pb(L[pl++]);
    }
    
    while (pr < nr) {
        sorted.pb(R[pr++]);
    }
    
    return sorted;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    
    vector<int> res = merge_sort(a);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[res[i]-1] = i + 1;
    }
    cout << "! ";
    for (auto& i : ans) {
        cout << i << " ";
    }
}

signed main() {
    // fast_cin();
    // 3 2 4 7 1 5 6
    // 4 2 1 3
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
