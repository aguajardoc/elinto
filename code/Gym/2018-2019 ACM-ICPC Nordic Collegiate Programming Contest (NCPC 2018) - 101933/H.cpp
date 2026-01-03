// Problem: H. House Lawn
// Contest: Codeforces - 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// URL: https://codeforces.com/gym/101933/problem/H
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

ld getAvg(int c, int t, int r) {
	int k = lcm(t + r, 10080);
	int w = k / 10080;
	int x = k / (t + r);
	int y = (x * c * t);
	ld avg = (ld)y / (ld)w;
	
	// dbg(c, t, r, k, w, x, y, avg);
	
	return avg;
}

string getName(string s, int& idx) {
	string c;
	int d = s.length();
	for (; idx < d; idx++) {
		if (s[idx] == ',') break;
		c += s[idx];
	}
	idx++;
	return c;
}

int getVal(string s, int& idx) {
	string c;
	int num;
	int d = s.length();
	for (; idx < d; idx++) {
		// dbg(idx, s[idx]);
		if (s[idx] == ',') break;
		c += s[idx];
	}
	idx++;
	// dbg(c);
	num = stoll(c);
	return num;
}

void solve() {
    int l, n;
    cin >> l >> n;
    cin.ignore();
    
    vector<pair<int, string>> winners;
    map<string, int> place;
    for (int i = 0; i < n; i++) {
    	string s;
    	getline(cin, s);
    	
    	int idx = 0;
    	string m = getName(s, idx);
    	place[m] = i;
    	
    	int p = getVal(s, idx);
    	int c = getVal(s, idx);
    	int t = getVal(s, idx);
    	int r = getVal(s, idx);
    	
    	ld avg = getAvg(c, t, r);
    	
    	// dbg(avg);
    	
    	if (avg>=l) {
    		winners.pb({p, m});
    	}
    }
    
    sort(winners.begin(), winners.end(), [&place](const auto& a, const auto& b) {
    	if (a.first != b.first) return a.first < b.first;
    	
    	return (place[a.second] < place[b.second]);
    });
    while (!winners.empty() and winners.back().first != winners.front().first) winners.pop_back();
    for (auto& i : winners) {
    	cout << i.second << ln;
    }
    
    if (winners.empty()) {
    	cout << "no such mower" << ln;
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
