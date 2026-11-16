// Problem: F. Circular Minesweeper
// Contest: Codeforces - 2026-2027 ICPC NERC, Kyrgyzstan Regional Contest
// URL: https://codeforces.com/gym/106802/problem/F
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

pair<int, int> query(int x) {
	cout << "? " << x << endl;
	string ra; int rb; cin >> ra >> rb;
	int y = 0;
	if (ra == "YES") y = 1;
	return {y, rb};
}

void answer(int x) {
	cout << "! " << x << endl;
}

void solve() {
    int n; cin >> n;
    int L = 1e9;
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
    
    int first = mt() % L + 1;
    
    pair<int, int> res = query(first);
    if (res.first) n--;
    int prev = first;
    while (n > 1) {
    	int d = res.second;
    	
    	int left = prev - d;
    	int right = prev + d;
    	if (right > L) right -= L;
    	if (left <= 0) left = L + left;
    	
//     	
    	// dbg(prev, d);
    	// dbg(left, right);
    	int choose = mt() % 2;
    	if (choose) swap(left, right);
    	
    	pair<int, int> nr = query(left);
    	if (nr.first) n--;
    	
    	if (nr.first == 0) {
    		answer(right);
    		return;
    	} 
    	
    	res = nr;
    	prev = left;
    }
    
    int d = res.second;
    	
	int left = prev - d - 1;
	int right = prev + d + 1;
	if (right > L) right -= L;
	if (left <= 0) left = L + left;
	if (left == right) {
		answer(left);
		return;
	}
	
	pair<int, int> nr = query(left);
	
	if (!nr.first and nr.second == 1) {
		answer(left + 1);
	}
	else if (!nr.first) answer(right - 1);
	else 0/0;
    
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
