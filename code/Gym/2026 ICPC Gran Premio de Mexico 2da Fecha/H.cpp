// Problem: H. Huron Airlines
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/H
// Memory Limit: 256 MB
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
    int n;
    cin >> n;
    vector<int> r(n), k(n);
    int time = 0;
    
    for (auto& i : r) cin >> i;
    for (auto& i : k) cin >> i;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < n; i++) {
    	// See if we have to wait
    	while (!pq.empty()) {
    		pair<int, int> block = pq.top();
    		pq.pop();
    		
    		// idc if it ended before now
    		if (block.second <= time) continue;
    		
    		// it must end!
    		if (block.first <= r[i]) {
    			time = max(time, block.second);
    		}
    		// else let it be
    		else {
    			pq.push(block);
    			break;
    		}
    	}
    	
    	// Add new task to queue
    	pq.push({r[i], time + r[i] + k[i]});
    	
    	// Can't board at the same time as someone else
    	time++;
    }
    
    // Time ends when last one sits
    while (!pq.empty()) {
    	time = max(time, pq.top().second);
    	pq.pop();
    }
    
    cout << time << ln;
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
