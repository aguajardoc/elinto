// Problem: M. The World's Biggest São João
// Contest: Codeforces - I Maratona Nordestina de Programação — 1st Northeastern Brazil Programming Contest
// URL: https://codeforces.com/gym/106667/problem/M
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

int get(map<string, int>& p) {
    int gp = 0, gr = 0, rp = 0, rr = 0;
    for (auto& [s, ct] : p) {
        if (s == "RR") {
            rp+=ct, rr+=ct;
        }
        if (s == "GG") {
            gp+=ct, gr+=ct;
        }
        if (s == "GR") {
            gp+=ct, rr+=ct;
        }
        if (s == "RG") {
            rp+=ct, gr+=ct;
        }
    }
    
    int res =     gp * (gr - rr) + 
                  rp * (rr - gr);
                  
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s, t; cin >> s >> t;
    map<string, int> ct;
    for (int i = 0; i < n; i++) {
        string x;
        x += s[i];
        x += t[i];
        ct[x]++;
    }
    
    map<string, int> pool1, pool2;
    pool1["GG"] = ct["GG"];
    pool2["RR"] = ct["RR"];
    
    // Pool 1 benefits from at most 1 GR
    // Pool 2 benefits from at most 1 RG
    int opp = min(ct["RG"], ct["GR"]);
    pool1["RG"] += opp;
    pool1["GR"] += opp;
    ct["RG"] -= opp;
    ct["GR"] -= opp;
    
    int tot = ct["GR"] + ct["RG"];
    
    for (int i = 0; i < tot/2; i++) {
        if (ct["GR"]){
            pool1["GR"]++;
            ct["GR"]--;
        }
        else {
            pool1["RG"]++;
            ct["RG"]--;
        }
    }
    for (int i = tot/2; i < tot; i++) {
        if (ct["GR"]){
            pool2["GR"]++;
            ct["GR"]--;
        }
        else {
            pool2["RG"]++;
            ct["RG"]--;
        }
    }
    
    int ap1 = 0, ap2 = 0, ans = 0;
    ap1 = get(pool1);
    ap2 = get(pool2);
    
    ans = ap1 + ap2;
    
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
