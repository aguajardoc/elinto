// Problem: C. Bulls and Cows
// Contest: Codeforces - Codeforces Beta Round 59 (Div. 2)
// URL: https://codeforces.com/contest/63/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

struct Guess {
	string s;
	int l, r;
};

string getNum(int x) {
	string s = to_string(x);
	while (s.length() < 4) {
		s = '0' + s;
	}
	return s;
}

bool hasRep(int x) {
	string t = getNum(x);
	map<int, int> ct;
	for (auto& i : t) {
		if (++ct[i] == 2) return true;
	}
	return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> possible;
    
    vector<Guess> a(n);
    for (int i = 0; i < n; i++) {
    	string g;
    	int l, r;
    	cin >> g >> l >> r;
    	a[i] = {g, l, r};
    }
    
    for (int i = 100; i < 10000; i++) {
		if (hasRep(i)) continue;
    	string num = getNum(i);
    	
    	// go through every guess and check if valid
    	bool valid = true;
    	for (auto& j : a) {
    		string x = j.s;
    		
    		int bulls = 0, cows = 0;
    		for (int k = 0; k < 4; k++) {
    			if (x[k] == num[k]) bulls++;
    			else if (num.find(x[k]) != string::npos) cows++;
    		}
    		
    		if (bulls != j.l or cows != j.r) valid = false;
    	}
    	
    	if (valid) {
    		possible.push_back(num);
    	}
    }
    
    if (possible.empty()) {
    	cout << "Incorrect data" << ln;
    }
    else if (possible.size() == 1) {
    	cout << possible.front() << ln;
    }
    else cout << "Need more data" << ln;
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
