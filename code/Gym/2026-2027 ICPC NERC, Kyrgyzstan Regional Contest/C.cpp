// Problem: C. Digital MEGAROOT
// Contest: Codeforces - 2026-2027 ICPC NERC, Kyrgyzstan Regional Contest
// URL: https://codeforces.com/gym/106802/problem/C
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

vector<vector<int>> weights(200001);

vector<int> get_w(int n) {
	if (n == 0) return {0};
	vector<int> w(n);
	int cw = n;
	for (int i = 0; i < n / 2 + n % 2; i++) {
		w[i] = w[n-i-1] = cw;
		cw += (n - 2 * (i+1));
	}
	
	return w;
}

string get_num(string s) {
	int res = 0;
	int n = s.length();
	if (n == 0 or s == "0") return {0};
	for (int i = 0; i < n; i++) {
		res += (s[i] - '0') * weights[n][i];
	}
	
	string ans = to_string(res);
	if (ans.empty()) ans = "0";
	return ans;
}

string calc(string s) {
	int n = s.length();
	if (n == 0 or s == "0") return "0";
	if (weights[n].empty()) weights[n] = get_w(n);
	
	string res = get_num(s);
	if (res == "0") return "0";
	if (res.length() != n or res != s) return calc(res);
	return s;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    cout << calc(s) << " ";
    int q;
    cin >> q;
    vector<int> p(q), d(q);
    for (auto& i : p) cin >> i;
    for (auto& i : p) i--;
    for (auto& i : d) cin >> i;
    int second = stoll(get_num(s));
    
    for (int i = 0; i < q; i++) {
    	second -= weights[n][p[i]] * (s[p[i]] - '0');
    	s[p[i]] = (d[i] + '0');
    	second += weights[n][p[i]] * (s[p[i]] - '0');
    	
    	string x = to_string(second);
    	cout << calc(x) << " ";
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