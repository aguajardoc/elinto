// Problem: D1. Unique Values (Easy version)
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/D1
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

// okay no salió porque 
// 1. me mentalicé mal: vi que quedaban 25 minutos y dije nah ya no sale
// 2. Leí mal!!!! deja de leer mal wey!!! 
// THE ANSWER TO THE QUERY WILL BE THE NUMBER OF VALUES THAT APPEAR ONCE!
// 3. No pensé que encontrar un lower bound para tq en el C, sooooo

// okay okay ahora si
// 2, 1, 2, ,3, 4, 1, 2, 4, 3
// 1, 2, 1, 2, 3, 2, 2, 1, 0
// no pues namas encontrar el punto donde NO cambia
// pero como lol 
// jaja busaqueda binaria o sea si pero a ver

// ah duh, es mod 2 hasta ese punto
// entonces encontrar el primer indice donde los primeros
// k no tienen una respuesta congruente a idx + 1 mod 2

// okay así encuentras el último, después incluyes ese idx
// y otra vez, pero con la cond del mod invertida

// 2, 1, 2, ,3, 4, 1, X, 4, 3
// 0, 1, 1, 2, 3, 2,     1, 0

// 2, 1, X, 3, 4, 1, X, 4, 3
// 0,

int query(vector<int>& q) {
	int k = q.size();
	
	cout << "? " << k;
	for (auto& i : q) {
		cout << " " << i;
	}
	cout << endl;
	
	int r;
	cin >> r;
	return r;
	
}

void solve() {
	int n;
	cin >> n;
	
	set<int> found;
	for (int i = 0; i < 3; i++) {
		int l = 1, r;
		
		if (!found.empty()) r = *found.rbegin();
		else r = 2 * n + 1;
		
		int ans = INF;
		
		while (l <= r) {
			int m = (l + r) / 2;
			
			vector<int> q;
			for (int j = 1; j <= m; j++) {
				if (!found.count(j)) q.pb(j);
			}
			for (auto& j : found) q.pb(j);
			
			int fm = query(q);
			
			int emod = (q.size()) % 2;
			
			if ((fm % 2) != emod) {
				ans = min(ans, m);
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		
		found.insert(ans);
	}
	
	cout << "!";
	for (auto& i : found) {
		cout << " " << i;
	}
	cout << endl;
}

signed main() {
    // fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
