// Problem: B. MUH and Important Things
// Contest: Codeforces - Codeforces Round 269 (Div. 2)
// URL: https://codeforces.com/contest/471/problem/B
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

void print(vector<pair<int, int>> a) {
	for (auto& i : a) {
		cout << i.second << " ";
	}
	cout << ln;
}

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> ct;
    vector<pair<int, int>> ordering(n);
    int two = 0, three = 0;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	// ct[x].pb(i);
    	ordering[i] = {x, i + 1};
    	
    }
    
    sort(ordering.begin(), ordering.end());
    
    
    for (int i = 0; i < n; i++) {
    	int x = ordering[i].first;
    	ct[ordering[i].first].pb(i);
    	if (ct[x].size() == 2) two++;
    	if (ct[x].size() == 3) three++;
    }
    if (two < 2 and three == 0) {
    	cout << "NO" << ln;
    	return;
    }
    cout << "YES" << ln;
    
    
    
    
    if (three >= 1) {
    	vector<int> idx;
    	int ooo = false;
    	
    	for (auto& i : ct) {
    		if (i.second.size() >= 3) {
    			for (int j = 0; j < 3; j++) {
    				idx.pb(i.second[j]);
    			}
    			break;
    		}
    	}
    	
    	print(ordering);
    	swap(ordering[idx[0]], ordering[idx[1]]);
    	print(ordering);
    	swap(ordering[idx[0]], ordering[idx[1]]);
    	swap(ordering[idx[0]], ordering[idx[2]]);
    	print(ordering);
    }
    else {
    	// take vector of ones to change
    	vector<int> fi, se;
    	int idx = 0;
    	for (auto& i : ct) {
    		if (i.second.size() >= 2) {
    			for (int j = 0; j < 2; j++) {
    				if (idx == 0) {
    					fi.pb(i.second[j]);
    				}
    				else if (idx == 1) {
    					se.pb(i.second[j]);
    				}
    			}
    			idx++;
    		}
    	}
    	
    	print(ordering);
    	swap(ordering[fi[0]], ordering[fi[1]]);
    	print(ordering);
    	swap(ordering[se[0]], ordering[se[1]]);
    	print(ordering);
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
