// Problem: Mountain Range
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3314
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

const int MAXN = 200001;
int a[MAXN], L[MAXN], R[MAXN], dp[MAXN];

int recurse(int idx) {
    if (dp[idx] != -1) return dp[idx];
    
    int res = 0;
    if (L[idx] != -1) res = max(res, recurse(L[idx])+1);
    if (R[idx] != -1) res = max(res, recurse(R[idx])+1);
    
    return dp[idx] = res;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> st;
    fill_n(&L[0], 200001, -1);
    fill_n(&R[0], 200001, -1);
    fill_n(&dp[0], 200001, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() and a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) {
            L[i] = st.top();
        }
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() and a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) {
            R[i] = st.top();
        }
        st.push(i);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1 + recurse(i));
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
