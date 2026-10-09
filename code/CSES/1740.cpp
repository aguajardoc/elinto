// Problem: Intersection Points
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1740
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

const int TREE_SIZE = 1 << 20;
int st[2*TREE_SIZE];

void update(int i, int x) {
    i += TREE_SIZE;
    st[i] += x;
    i >>= 1;
    
    while (i) {
        st[i] = st[2*i] + st[2*i+1];
        i >>= 1;
    }
}

int query(int l, int r) {
    l += TREE_SIZE;
    r += TREE_SIZE;
    int res = 0;
    
    while(l <= r) {
        if (l&1) res += st[l++];
        if (!(r&1)) res += st[r--];
        
        l >>= 1;
        r >>= 1;
    }
    
    return res;
}

struct Event {
    int time, place, type;
    bool operator<(const auto& oth) const {
        return time < oth.time;
    }  
};

struct Query {
    int time, l, r;
    bool operator<(const auto& oth) const {
        return time < oth.time;
    }
};

struct Line {
    int x1, y1, x2, y2;
    bool is_event() {
        return y1 == y2;
    }
};

void print() {
    for (int i = 0; i < 6; i++) {
        cout << query(i, i) << " ";
    }
    cout << ln;
}

void solve() {
    int n; cin >> n;
    
    vector<Line> lines;
    vector<Event> events;
    vector<Query> queries;
    int ans = 0;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vals.pb(x1);
        vals.pb(y1);
        vals.pb(x2);
        vals.pb(y2);
        lines.pb({x1, y1, x2, y2});
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (int i = 0; i < n; i++) {
        lines[i].x1 = lower_bound(vals.begin(), vals.end(), lines[i].x1) - vals.begin();
        lines[i].y1 = lower_bound(vals.begin(), vals.end(), lines[i].y1) - vals.begin();
        lines[i].x2 = lower_bound(vals.begin(), vals.end(), lines[i].x2) - vals.begin();
        lines[i].y2 = lower_bound(vals.begin(), vals.end(), lines[i].y2) - vals.begin();
        
        
        if (lines[i].is_event()) {
            events.pb({lines[i].x1, lines[i].y1, 1});
            events.pb({lines[i].x2, lines[i].y1, -1});
        }
        else {
            queries.pb({lines[i].x1, lines[i].y1, lines[i].y2});
        }
    }
    
    sort(events.begin(), events.end());
    sort(queries.begin(), queries.end());
    int m = vals.size();
    int idxE = 0, idxQ = 0;
    for (int i = 0; i < m; i++) {
        while (idxE < events.size() and events[idxE].time == i) {
            update(events[idxE].place, events[idxE].type);
            idxE++;
        }
        
        while (idxQ < queries.size() and queries[idxQ].time == i) {
            ans += query(queries[idxQ].l, queries[idxQ].r);
            idxQ++;
        }
    }
    
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
