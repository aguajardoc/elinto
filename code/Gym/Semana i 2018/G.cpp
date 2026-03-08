// Problem: G. A+B+C
// Contest: Codeforces - Semana i 2018
// URL: https://codeforces.com/gym/101917/problem/G
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

pair<int, int> getNum(string s) {
	int N, D;
	string cur;
	for (auto& i : s) {
		if (i == '/') {
			N = stoll(cur);
			cur.clear();
		}
		else cur += i;
	}
	D = stoll(cur);
	
	return {N, D};
}

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    
    pair<int, int> A = getNum(a);
    pair<int, int> B = getNum(b);
    pair<int, int> C = getNum(c);
    
    int DEN = lcm(A.second, B.second);
    DEN = lcm(DEN, C.second);
    
    A.first *= DEN / A.second;
    B.first *= DEN / B.second;
    C.first *= DEN / C.second;
    
    int NUM = A.first + B.first + C.first;
    
    int hcf = gcd(NUM, DEN);
    
    NUM /= hcf;
    DEN /= hcf;
    cout << NUM << "/" << DEN << ln;
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
