// Problem: C. Queue
// Contest: Codeforces - Codeforces Round 101 (Div. 2)
// URL: https://codeforces.com/contest/141/problem/C
// Memory Limit: 256 MB
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

void solve() {
	int n;
	cin >> n;
    vector<pair<int, string>> a(n);
    
    for (int i = 0; i < n; i++) {
    	cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    vector<pair<int, string>> h(n);
    vector<int> ch;
    bool poss = true;
    int inc = 10000;
    
    for (int i = 0; i < n; i++) {
    	// ith customer
    	
    	// get a[ith] lgest
    	if (a[i].first > ch.size()) {
    		poss = false;
    		break;
    	}
    	sort(ch.rbegin(), ch.rend()); // nlogn
    	
    	int ne;
    	
    	if (a[i].first == 0) {
    		if (ch.empty()) ne = inc;
    		else ne = ch.front() + inc;
    	}
    	else {
    		ne = ch[a[i].first - 1];
    	}
    	
    	for (auto& j : h) {
    		if (j.first >= ne) j.first += inc;
    	}
    	
    	h[i].first = ne;
    	h[i].second = a[i].second;
    	ch.clear();
    	for (int j = 0; j <= i; j++) {
    		ch.pb(h[j].first);
    	}
    }
    
    if (!poss) {
    	cout << -1 << ln;
    }
    else {
    	for (auto& i : h) {
    		cout << i.second << " " << i.first << ln;
    	}
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
