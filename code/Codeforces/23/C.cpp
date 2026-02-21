// Problem: C. Oranges and Apples
// Contest: Codeforces - Codeforces Beta Round 23
// URL: https://codeforces.com/contest/23/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

struct SSS {
	int f,s,i;
};

void solve() {
    int n;
    cin >> n;
    
    int A = 0, O = 0;
    vector<SSS> boxes(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
    	int a, o;
    	cin >> a >> o;
    	A += a;
    	O += o;
    	boxes[i] = {o, a, i+1};
    }
    
    sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b) {
    	return (a.f < b.f);
    });
    
    int oddA = 0, evenA = 0;
    for (int i = 0; i<  2 * n - 1; i++) {
    	if (i % 2) {
    		oddA += boxes[i].s;
    	}
    	else evenA += boxes[i].s;
    }
    
    if (oddA * 2 >= A) {
    	cout << "YES" << ln;
    	for (int i = 1; i < 2 * n - 1; i+=2) {
    		cout << boxes[i].i << " ";
    	}
    	cout << boxes.back().i << ln;
    }
    else if (evenA * 2 >= A) {
    	cout << "YES" << ln;
    	for (int i = 0; i < 2 * n - 1; i+=2) {
    		cout << boxes[i].i << " ";
    	}
    	cout << ln;
    }
    else cout << "NO" << ln;
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
