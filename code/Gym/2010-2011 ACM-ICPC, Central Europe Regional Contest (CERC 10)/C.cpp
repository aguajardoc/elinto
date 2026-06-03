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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        if(i <= r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> M = manacher(s);
    
    set<int> valid;
    vector<vector<int>> expiry(n + 1);
    int ans = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int MV = M[2*i+1] - 1;
        int rad = MV / 2;
        int x = i - rad/2;
        
        valid.insert(i);
        int expiry_date = rad + i + 1;
        if (expiry_date <= n) {
            expiry[expiry_date].pb(i);
        }
        
        for (auto& j : expiry[i]) {
            valid.erase(j);
        }
        
        auto it = valid.lower_bound(x);
        
        if (it != valid.end()) {
            int j = *it;
            ans = max(ans, 4 * (i - j));
        }
    }
    
    cout << ans << ln;
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
