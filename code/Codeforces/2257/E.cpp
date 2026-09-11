// Problem: E. Busy Beaver
// Contest: Codeforces - Codeforces Round 1117 (Div. 2)
// URL: https://codeforces.com/contest/2257/problem/E
// Memory Limit: 512 MB
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

struct Block {
    int b, lastf, profit, req;
    bool operator<(const auto& oth) const {
        return req > oth.req;
    }
};

struct Plan {
    int profit, req;
};

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<vector<Block>> blocks(n);
    vector<vector<Plan>> plans(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> a(m), b(m);
        for (auto& j : a) cin >> j;
        for (auto& j : b) cin >> j;
        
        Block cur = {i, 0, 0, 0};
        int req = 0;
        int curProfit = 0;
        for (int j = 0; j < m; j++) {
            req = max(req, a[j] - curProfit);
            
            int nextProfit = b[j] - a[j];
            curProfit += nextProfit;
            plans[i].pb({nextProfit, a[j]});
            
            cur.lastf = j;
            cur.req = req;
            cur.profit = curProfit;
            
            if (cur.profit >= 0) {
                blocks[i].pb(cur);
                cur.profit = 0;
                curProfit = 0;
                cur.req = 0;   
                req = 0;
            }
        }
    }
    
    vector<int> lastFloor(n, -1), lastBlock(n, -1);
    priority_queue<Block> pq;
    for (int i = 0; i < n; i++) {
        if (!blocks[i].empty()) {
            lastBlock[i]++;
            pq.push(blocks[i][0]);
        }
    }
    
    int ans = -1;
    int buildAns = 0;
    while (!pq.empty()) {
        Block u = pq.top();
        if (u.req <= x) {
            pq.pop();
            lastFloor[u.b] = u.lastf;
            lastBlock[u.b]++;
            x += u.profit;
            if (blocks[u.b].size() > lastBlock[u.b]) {
                pq.push(blocks[u.b][lastBlock[u.b]]);
            }
            
            if (u.lastf > ans) {
                ans = u.lastf;
                buildAns = u.b;
            }
            else if (u.lastf == ans and u.b < buildAns) {
                buildAns = u.b;
            }
        }
        else break;
    }
    
    
    for (int i = 0; i < n; i++) {
        int local = x;
        int start = lastFloor[i] + 1;
        int m = plans[i].size();
        
        for (int j = start; j < m; j++) {
            if (local >= plans[i][j].req) {
                local += plans[i][j].profit;
                if (j > ans) {
                    ans = j;
                    buildAns = i;
                }
                else if (j == ans and i < buildAns) {
                    buildAns = i;
                }
            }
            else break;
        }
    }
    
    cout << ans + 1 << " " << buildAns + 1 << ln;
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
