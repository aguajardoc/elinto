// Problem: D. Strange Device
// Contest: Codeforces - Good Bye 2019
// URL: https://codeforces.com/contest/1270/problem/D
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

pair<int, int> query(vector<int> q) {
	cout << "? ";
	for (auto& i : q) {
		cout << i << " ";
	}
	cout << endl;
	int pos, val;
	cin >> pos >> val;
	return {pos, val};
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> toq(k);
    iota(toq.begin(), toq.end(), 2);
    
    if (k == 1) {
    	cout << "! " << 1 << endl;
    	return;
    }
    
    map<int, int> ct;
	    
    for (int i = 0; i <= k; i++) {
    	pair<int, int> r = query(toq);
    	
    	ct[r.second]++;
    	
    	toq.clear();
    	for (int j = 0; j <= i; j++) {
    		toq.pb(j+1);
    	}
    	for (int j = i + 2; j <= k; j++) {
    		toq.pb(j + 1);
    	}
    }
    
    cout << "! " << (ct.rbegin()->second) << ln;
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
