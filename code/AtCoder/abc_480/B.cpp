// Problem: B - Invalid Vote
// Contest: AtCoder - AtCoder Beginner Contest 480
// URL: https://atcoder.jp/contests/abc480/tasks/abc480_b
// Memory Limit: 1024 MB
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
    int n, m; cin >> n >> m;
    vector<string> p(n);
    map<string, pair<int, int>> votes;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        p[i] = s;
        votes[s].first = i;
    }
    
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (votes.count(s)) votes[s].second++;
        else {
            int match = 0;
            string semi;
            for (auto& j : votes) {
                int diff = 0;
                if (j.first.length() != s.length()) continue;
                for (int k = 0; k < s.length(); k++) {
                    if (s[k] != j.first[k]) diff++;
                }
                
                if (diff == 1) {
                    match++;
                    semi = j.first;
                }
            }
            
            if (match == 1) votes[semi].second++;
        }
    }
    
    for (auto& i : p) {
        cout << votes[i].second << ln;
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
