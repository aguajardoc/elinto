// Problem: F. Classic Tetris: Scoring
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2025
// URL: https://codeforces.com/gym/106189/problem/F
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
    
    int sp = 760;
    int dp = 1900;
    int tp = 5700;
    int qp = 22800;
    int thresh = 130;
    int rows = 0;
    int level = 18;
    int points = 0;
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	
    	if (s == "single") {
    		rows += 1;
    		points += sp;
    	}
    	if (s == "double") {
    		rows += 2;
    		points += dp;
    	}
    	if (s == "triple") {
    		rows += 3;
    		points += tp;
    	}
    	if (s == "tetris") {
    		rows += 4;
    		points += qp;
    	}
    	
    	if (rows >= thresh) {
    		thresh += 10;
    		sp += 40;
    		dp += 100;
    		tp += 300;
    		qp += 1200;
    		level++;
    	}
    }
    
    cout << points << " " << level << ln;
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
