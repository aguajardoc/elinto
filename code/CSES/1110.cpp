// Problem: Minimal Rotation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1110
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
    string s; cin >> s; int n = s.length(); s = s + s;
    
    map<char, vector<int>> start;
    for (int i = 0; i < n; i++) {
        start[s[i]].pb(i);
    }
    
    vector<int> valid = start.begin()->second;
    vector<int> repeat(2*n, 0);
    for (auto& i : valid) repeat[i] = 1;
    // Repeatedly, take all valid starts and check next
    // Keep all where this is minimum
    int it = 1;
    while (valid.size() > 1) {
        char best = 'z';
        for (auto& j : valid) {
            best = min(best, s[j + it]);
        }
        
        vector<int> new_valid;
        bool bad = false;
        for (auto& j : valid) {
            if (s[j+it] == best and !bad) {
                new_valid.pb(j);
                if (repeat[j + it]) {
                    bad = true;
                    continue;
                }
            }
            else repeat[j] = 0;
            
            if (bad) bad = false;
        }
        
        valid = new_valid;
        
        it++;
    }
    
    for (int i = valid[0]; i < valid[0] + n; i++) {
        cout << s[i];
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
