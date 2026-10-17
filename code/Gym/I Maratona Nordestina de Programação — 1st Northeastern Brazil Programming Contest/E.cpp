// Problem: E. The Scale Riddle
// Contest: Codeforces - I Maratona Nordestina de Programação — 1st Northeastern Brazil Programming Contest
// URL: https://codeforces.com/gym/106667/problem/E
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

vector<vector<int>> ct(8, vector<int>(3, 0));

vector<string> tot(int n) {
    vector<string> res;
    
    for (int i = 0; i < n; i++) {
        int x = i;
        string y;
        
        int idx = 0;
        while (x) {
            y += (x % 3) + '0';
            
            ct[idx++][x%3]++;
            
            x /= 3;
        }
        
        while (y.size() < 8) {
            y += '0';
            ct[idx++][0]++;
        }
        res.pb(y);
    }
    
    return res;
}

int query(vector<vector<int>>& q) {
    cout << "? " << q[0].size() << " ";
    for (auto& i : q[0]) cout << i+1 << " ";
    for (auto& i : q[1]) cout << i+1 << " ";
    char x; cin >> x;
    if (x == 'E') return 0;
    if (x == 'D') return 1;
    return 2;
}

void solve() {
    int n; cin >> n;
    
    vector<string> ternary = tot(n);
    vector<vector<vector<int>>> queries(8, vector<vector<int>> (3));
    vector<vector<int>> target(8, vector<int>(3, 0));
    for (int i = 0; i < 8; i++) {
        int tar = min(ct[i][0], ct[i][1]);
        int s = ct[i][0] + ct[i][1] + ct[i][2];
        
        target[i][0] = target[i][1] = tar;
        target[i][2] = s - 2 * tar;
    }
    
    // for (int j = 0; j < 8; j++) {
        // dbg(target[j][0]);
        // dbg(target[j][1]);
        // dbg(target[j][2]);
    // }
    
    vector<vector<int>> unassigned(8);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            int x = ternary[i][j] - '0';
            if (x == 0 and target[j][0] > 0) {
                queries[j][x].pb(i);
                target[j][x]--;
            }
            else if (x == 0) ternary[i][j] = '2';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            int x = ternary[i][j] - '0';
            if (x == 1 and target[j][1] > 0) {
                queries[j][x].pb(i);
                target[j][x]--;
            }
            else if (x == 1) ternary[i][j] = '2';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            int x = ternary[i][j] - '0';
            if (x == 2 and target[j][2] > 0) {
                queries[j][2].pb(i);
                target[j][2]--;
            }
            
        }
    }
    
    // for (int j = 0; j < 8; j++) {
        // dbg(target[j][0]);
        // dbg(target[j][1]);
        // dbg(target[j][2]);
    // }
    
    vector<int> responses;
    for (int i = 0; i < 8; i++) {
        if (queries[i][0].empty()) {
            responses.pb(2);
            continue;
        }
        int res = query(queries[i]);
        responses.pb(res);
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(i);
    }
    
    for (int i = 0; i < 8; i++) {
        set<int> prelim, nans;
        for (auto& j : queries[i][responses[i]]) {
            prelim.insert(j);
        }
        
        for (auto& j : prelim) {
            if (ans.count(j)) nans.insert(j);
        }
        
        ans = nans;
    }
    
    cout << "! " << 1 + *ans.begin() << ln;
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
