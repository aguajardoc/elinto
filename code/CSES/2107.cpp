// Problem: String Functions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2107/
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

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef vector<int> vi;

vi pi(const string& s) {
vi p(sz(s));
rep(i,1,sz(s)) {
int g = p[i-1];
while (g && s[i] != s[g]) g = p[g-1];
p[i] = g + (s[i] == s[g]);
}
return p;
}
vi match(const string& s, const string& pat) {
vi p = pi(pat + '\0' + s), res;
rep(i,sz(p)-sz(s),sz(p))
if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
return res;
}

vi Z(const string& S) {
vi z(sz(S));
int l = -1, r = -1;
rep(i,1,sz(S)) {
z[i] = i >= r ? 0 : min(r - i, z[i - l]);
while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
z[i]++;
if (i + z[i] > r)
l = i, r = i + z[i];
}
return z;
}

void print(vi a) {
    for (auto& i : a) cout << i << " ";
    cout << ln;
}

void solve() {
    string s; cin >> s;
    print(Z(s));
    print(pi(s));
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
