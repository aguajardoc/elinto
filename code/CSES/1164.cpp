// Problem: Room Allocation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1164
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

struct Event {
    int time, ct, who;
    
    bool operator <(const auto& oth) const {
        return time < oth.time;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Event> arriv, depar;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int ta, td; cin >> ta >> td;
        vals.pb(ta); vals.pb(td);
        arriv.pb({ta, 1, i});
        depar.pb({td, -1, i});
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (auto& e : arriv) {
        e.time = lower_bound(vals.begin(), vals.end(), e.time) - vals.begin();
    }
    for (auto& e : depar) {
        e.time = lower_bound(vals.begin(), vals.end(), e.time) - vals.begin();
    }
    
    sort(arriv.begin(), arriv.end());
    sort(depar.begin(), depar.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(i);
    }
    
    int idxa = 0, idxd = 0, ans = 0, cur = 0;
    vector<int> rooms(n, 0);
    for (int i = 0; i < vals.size(); i++) {
        while (idxa < arriv.size() and arriv[idxa].time == i) {
            cur += arriv[idxa].ct;
            rooms[arriv[idxa].who] = pq.top();
            pq.pop();
            idxa++;
        }
        
        ans = max(ans, cur);
        
        while (idxd < depar.size() and depar[idxd].time == i) {
            cur += depar[idxd].ct;
            pq.push(rooms[depar[idxd].who]);
            idxd++;
        }
    }
    
    cout << ans << ln;
    
    for (auto& i : rooms) {
        cout << i << " ";
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
