// Problem: I. Inside the Guinea Pig Playpen
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/I
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

struct GroupEventPre {
    int arr, dep, ct;
};

struct GroupEvent {
    int time, ct;
    
    bool operator<(const auto& oth) const {
        return time < oth.time;
    }
};

struct InviteResponse {
    char den;
    int start, x, end;
    
    InviteResponse() {}
};

struct Invite {
    int k, p;
};

vector<int> vals, vComp, minuteVals, minutesComp, groupSize;
string status;
vector<vector<int>> AL;
vector<int> visited;

vector<Invite> invites;
vector<InviteResponse> inviteResponses;
vector<GroupEventPre> preproc;
vector<GroupEvent> processed;
vector<int> startTime, endTime;

void dfs(int u, int p) {
    if (status[u] == 'A') {
        preproc.pb({startTime[u], endTime[u], groupSize[u]});
    }
    else if (status[u] == 'T') {
        if (p >= 0 and status[p] == 'A') {
            status[u] = 'A';
            preproc.back().ct += groupSize[u];
        }
        else status[u] = 'D';
    }
    visited[u] = true;
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        if (visited[v]) continue;
        
        dfs(v, u);
    }
}

void compressV() {
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (auto& invite : invites) {
        invite.k = lower_bound(vals.begin(), vals.end(), invite.k) - vals.begin();
    }
    for (auto& resp : inviteResponses) {
        if (resp.den == 'T') {
            resp.x = lower_bound(vals.begin(), vals.end(), resp.x) - vals.begin();
        }
    }
}

void compressM() {
    sort(minuteVals.begin(), minuteVals.end());
    minuteVals.resize(unique(minuteVals.begin(), minuteVals.end()) - minuteVals.begin());
    
    for (auto& resp : inviteResponses) {
        if (resp.den == 'A') {
            resp.start = lower_bound(minuteVals.begin(), minuteVals.end(), resp.start) - minuteVals.begin();
            resp.end = lower_bound(minuteVals.begin(), minuteVals.end(), resp.end) - minuteVals.begin();
        }
    }
}


void solve() {
    int f, n;
    cin >> f >> n;
    for (int i = 0; i < n; i++) {
        int k, p;
        cin >> k >> p;
        invites.push_back({k, p});
        vals.pb(k);
    }
    for (int i = 0; i < n; i++) {
        inviteResponses.pb({});
        char den;
        cin >> den;
        inviteResponses.back().den = den;
        if (den == 'A') {
            int a, t;
            cin >> a >> t;
            inviteResponses.back().start = a;
            inviteResponses.back().end = a + t;
            
            minuteVals.pb(a);
            minuteVals.pb(a + t);
        }
        else if (den == 'T') {
            int x;
            cin >> x;
            inviteResponses.back().x = x;
            vals.pb(x);
        }
    }
    
    compressV();
    compressM();
    status = string(vals.size(), 'D');
    groupSize.assign(vals.size(), 0);
    startTime.assign(vals.size(), 0);
    endTime.assign(vals.size(), 0);
    for (int i = 0; i < n; i++) {
        status[invites[i].k] = inviteResponses[i].den;
        groupSize[invites[i].k] = invites[i].p;
        
        if (inviteResponses[i].den == 'A') {
            startTime[invites[i].k] = inviteResponses[i].start;
            endTime[invites[i].k] = inviteResponses[i].end;
        }
    }
    
    AL.assign(vals.size(), vector<int>());
    visited.assign(vals.size(), 0);
    for (int i = 0; i < n; i++) {
        InviteResponse& IR = inviteResponses[i];
        if (IR.den == 'T') {
            AL[IR.x].pb(invites[i].k);
        }
    }
    
    // traverse graph to change statuses
    for (int i = 0; i < vals.size(); i++) {
        if (!visited[i] and status[i] == 'A') dfs(i, -1);
    }
    // go through events
    for (auto& prep : preproc) {
        processed.pb({prep.arr, prep.ct});
        processed.pb({prep.dep, -prep.ct});
    }
    
    sort(processed.begin(), processed.end());
    int idx = 0;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < minuteVals.size(); i++) {
        while (idx < processed.size() and processed[idx].time == i) {
            cur += processed[idx].ct;
            idx++;
        }
        
        ans = max(ans, cur);
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
