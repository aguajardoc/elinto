// Problem: I. Intergalactic Bidding
// Contest: Codeforces - 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// URL: https://codeforces.com/gym/101933/problem/I
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

struct Part {
	string name, bid;

	bool operator<(const auto& oth) {
		if (bid.length() != oth.bid.length()) return bid.length() < oth.bid.length();
		
		int n = bid.length();
		for (int i = 0; i < n; i++) {
			if (bid[i] == oth.bid[i]) continue;
			
			return bid[i] < oth.bid[i];
		}
		
		return bid < oth.bid;
	}
	
	string operator+(auto& b) {
		string temp(bid.length() + b.bid.length(), '0');
		
		int n = bid.length() + b.bid.length();
		reverse(bid.begin(), bid.end());
		reverse(b.bid.begin(), b.bid.end());
		int carry = 0;
		for (int i = 0; i < n; i++) {
			int x = carry;
			carry = 0;
			if (i < bid.length()) x += (bid[i] - '0');
			if (i < b.bid.length()) x += (b.bid[i] - '0');
			
			carry = x / 10;
			x = x % 10;
			
			int addt = (temp[i] - '0') + x;
			carry += addt / 10;
			temp[i] = ((addt % 10) + '0');
			
			// dbg(carry);
		}
		
		reverse(bid.begin(), bid.end());
		reverse(b.bid.begin(), b.bid.end());
		while (temp.back() == '0') temp.pop_back();
		reverse(temp.begin(), temp.end());
		return temp;
	}
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    Part goat;
    goat.bid = s;
    Part cur;
    cur.bid = "1";
    
    vector<Part> p(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i].name >> p[i].bid;
    }
    
    sort(p.rbegin(), p.rend());
    // for (auto& i : p) {
    	// for (auto& j : p) {
    		// dbg(i.bid);
    		// dbg(j.bid);
    		// dbg(i + j);
    	// }
    // }
    
    goat.bid = goat + cur;
    cur.bid = "0";
    
    vector<string> ans;
    
    for (int i = 0; i < n; i++) {
    	Part add;
    	add.bid = (cur + p[i]);
    	if (add < goat) {
    		ans.pb(p[i].name);
    		cur.bid = add.bid;
    	}
    }
    
    if (s != cur.bid) ans.clear();
    
    cout << ans.size() << ln;
    for (auto& i : ans) {
    	cout << i << ln;
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
