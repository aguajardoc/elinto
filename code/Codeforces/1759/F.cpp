// Problem: F. All Possible Digits
// Contest: Codeforces - Codeforces Round  834 (Div. 3)
// URL: https://codeforces.com/contest/1759/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

void increment(vector<int>& a, int p) {
	vector<int> b = {0};
	a.back() = p - 1;
	b.insert(b.end(), a.begin(), a.end());
	int n = b.size();
	for (int j = n - 1; j >= 0; j--) {
		if (b[j] == p - 1) {
			b[j] = 0;
		}
		else {
			b[j]++;
			break;
		}
	}
	a = b;
}

void print(vector<int>& a) {
	for (auto& i : a) {
		cout << i << " ";
	}
	cout << ln;
}

void solve() {
    int n, p; cin >> n >> p;
    set<int> used;
    
    vector<int> a(n);
    int an = 0;
    for (auto& i : a) {
    	cin >> i;
    	used.insert(i);
    }
    an = a.back();
    
    // dbg(an);
    
    // Case 1: All digits are already in there 
    if (used.size() == p) {
    	cout << 0 << ln;
    	return;
    }
    
    // Case 2: All digits <= a_n are there
    // if all under an are covered:
    bool allc = true;
    for (int i = an - 1; i >= 0; i--) {
    	if (!used.count(i)) {
    		allc = false;
    		break;
    	}
    }
    if (allc) {
    	int last = p;
    	for (int i = p - 1; i >= 0; i--) {
    		if (!used.count(i)) break;
    		last = i;
    	}
    	
    	// dbg(last);
    	cout << last - an - 1 << ln;
    	return;
    }
    
    // Case 3: Not all digits <= a_n are there
    // print(a);
    increment(a, p);
    // print(a);
    for (auto& i : a) {
    	used.insert(i);
    }
    
    // dbg(used.size(), p);
    bool allc2 = true;
    for (int i = an - 1; i >= 0; i--) {
    	if (!used.count(i)) {
    		allc2 = false;
    		break;
    	}
    }
    
    if (allc2) {
    	cout << p - an << ln;
    	return;
    }
    
    for (int j = an - 1; j >= 0; j--) {
    	if (!used.count(j)) {
    		cout << p - an + j << ln;
    		return;
    	}
    }
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