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

int sod(int cur) {
	int x = 0;
	string s = to_string(cur);
	for (auto& i : s) {
		x += (i - '0');
	}
	
	return x;
}

void solve() {
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << s << ln;
		return;
	}
	vector<int> ct(10, 0);
	for (auto& i : s) {
		ct[i-'0']++;
	}

	for (int i = 0; i <= 10 * (int)s.length(); i++) {
		string ns = to_string(i);
		if (ns == "0") ns.pop_back();
		int cur = i;
		bool poss = true;
		while (cur > 9) {
			cur = sod(cur);
			ns += to_string(cur);
		}
		
		vector<int> ct2 = ct;
		for (auto& i : ns) {
			ct2[i-'0']--;
		}
		
		int rest = 0;
		for (int j = 0; j < 10; j++) {
			if (ct2[j] < 0) {
				poss = false;
			}
			else rest += j * ct2[j];
		}
		
		// dbg(i, rest, ns);
		
		if (rest != i) poss = false;
		
		if (poss) {
			string ans;
			for (int j = 9; j >= 0; j--) {
				ans += string(ct2[j], j + '0');
			}
			ans += ns;
			
			cout << ans << ln;
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
