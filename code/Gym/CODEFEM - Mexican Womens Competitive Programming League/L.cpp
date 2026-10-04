// Problem: L. Coding in Stitches
// Contest: Codeforces - CODEFEM - Mexican Womens Competitive Programming League
// URL: https://codeforces.com/gym/106718/problem/L
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

string W[10] = {
    "pgr", // 3
    "byyb", // 4
    "wwgyw", // 5
    "bwwbwb", // 6
    "prpb", // 4
    "prrb", // 4
    "rrggr", // 5
    "pywb", // 4
    "vpggpv", // 6
    "gpbrywvpg" // 9
};

int score[10] = {3,5,7,8,10,12,14,17,20,25};

struct Section {
    int score, x;
    bool operator <(const auto& oth) const {
        return x < oth.x;
    }
};

pair<int, int> get_diff(string& a, string& b) {
    int n = a.length();
    int ans = 0, differing = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans++;
            differing = i;
        }
    }
    
    return {ans, differing};
}

Section get_beauty(string& s, int offset) {
    pair<int, int> d;
    vector<int> valid;
    if (s.length() == 3) {
        valid = {0};
    }
    else if (s.length() == 4) {
        valid = {7, 5, 4, 1};
    }
    else if (s.length() == 5) {
        valid = {6, 2};
    }
    else if (s.length() == 6) {
        valid = {8, 3};
    }
    else if (s.length() == 9) {
        valid = {9};
    }
    
    for (auto& w : valid) {
        d = get_diff(s, W[w]);
        if (d.first == 0) {
            return {-1, -1};
        }
    }
    
    for (auto& w : valid) {
        d = get_diff(s, W[w]);
        if (d.first == 1) {
            return {score[w], d.second + offset};
        }
    }
    
    return {-1, -1};
}

int finf;
int dp[1000000 + 1];

int recurse(int idx, vector<Section>& A, int& x) {
    if (idx == finf) {
        return 0;
    }
    
    if (dp[idx] != -1) return dp[idx];
    
    Section ele = {-1, A[idx].x + x};
    auto it = lower_bound(A.begin(), A.end(), ele);
    
    int res = 0;
    int nxt;
    if (it == A.end()) nxt = finf;
    else nxt = it - A.begin();
    
    res = max({
        res,
        recurse(nxt, A, x) + A[idx].score,
        recurse(idx + 1, A, x)
    });
    
    return dp[idx] = res;
}

void solve() {
    string s; getline(cin, s); int x; cin >> x;
    s += ' ';
    vector<string> a;
    fill_n(&dp[0], 1000000 + 1, -1);
    string cur;
    for (auto& c : s) {
        if (c == ' ') {
            if (!cur.empty()) {
                a.pb(cur);
                cur.clear();
            }
        }
        else cur += c;
    }
    
    vector<Section> proc;
    int offset = 0;
    int m = a.size();
    for (int i = 0; i < m; i++) {
        Section new_stitch = get_beauty(a[i], offset);
        if (new_stitch.score != -1) {
            proc.pb(new_stitch);
        }
        
        offset += a[i].length() + 1;
    }
    
    finf = proc.size();
    
    cout << recurse(0, proc, x) << ln;
    
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
