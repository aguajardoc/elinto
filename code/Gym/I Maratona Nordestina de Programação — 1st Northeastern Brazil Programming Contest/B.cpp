// Problem: B. Good Spotlights
// Contest: Codeforces - I Maratona Nordestina de Programação — 1st Northeastern Brazil Programming Contest
// URL: https://codeforces.com/gym/106667/problem/B
// Memory Limit: 1024 MB
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

vector<string> ans;
string init;

bool recurse(string s, vector<string>& config, int ct) {
    if (ct == 8) {
        if (s == init) {
            ans = config;
            return true;
        }
        return false;
    }
    
    bool poss = false;
    for (int i = 0; i < 3; i++) {
        s[i] = (1 - (s[i] - '0') + '0');
        if (find(config.begin(), config.end(), s) == config.end()) {
            config.pb(s);
            poss |= recurse(s, config, ct + 1);
            config.pop_back();
        }
        s[i] = (1 - (s[i] - '0') + '0');
    }
    
    return poss;
}

void solve() {
    string s; cin >> s;
    init = s;
    vector<string> config;
    
    recurse(s, config, 0);
    reverse(ans.begin(), ans.end());
    ans.pb(init);
    
    for (auto& i : ans) {
        cout << i << ln;
    }
    
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
