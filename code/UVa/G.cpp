// Problem: G - Expedition
// Contest: Virtual Judge - Brazilian ICPC Summer School 2026 - Contest 1
// URL: https://vjudge.net/contest/781528#problem/G
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

struct Stop {
	int loc, val;
	
	bool operator < (const Stop& oth) {
		if (loc != oth.loc) return loc < oth.loc;
		return val < oth.val;
	}
};

vector<Stop> stops;
int L, P;

void solve() {
    int n;
    cin >> n;
    stops.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
    	cin >> stops[i].loc >> stops[i].val;
    }
    cin >> L >> P;
    for (int i = 0; i < n; i++) {
    	stops[i].loc = L - stops[i].loc;
    }
    
    stops.pb({L, 0});
    
    sort(stops.begin(), stops.end());
    
    // Get needed fuel to each, if its higher than P, then refuel
    priority_queue<int> pq;
    int ans = 0;
    bool poss = true;
    for (int i = 0; i <= n and stops[i].loc <= L; i++) {
    	if (stops[i].loc > P) {
    		while (!pq.empty() and stops[i].loc > P) {
    			P += pq.top();
    			ans++;
    			pq.pop();
    		}
    	}
    	
    	if (stops[i].loc > P) {
    		poss = false;
    		break;
    	}
    	
    	pq.push(stops[i].val);
    }
    
    cout << (poss ? ans:-1) << ln;
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
