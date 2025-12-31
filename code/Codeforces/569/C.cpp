// Problem: C. Primes or Palindromes?
// Contest: Codeforces - Codeforces Round 315 (Div. 2)
// URL: https://codeforces.com/contest/569/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

vector<int> pi;
const int N = 2000000;
bitset<N + 1> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= N; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= N; j+=i) {
			bs[j] = false;
		}
		// dbg(i, pi.size());
		pi.pb(i);
	}
}

vector<int> rub;

void palin() {
	for (int i = 1; i <= N; i++) {
		string rep = to_string(i);
		int x = rep.size();
		bool poss = true;
		for (int j = 0; j < x / 2; j++) {
			if (rep[j] != rep[x - 1 - j]) {
				poss = false;
				break;
			}
		}
		if (poss) {
			// dbg(i, rub.size());
			rub.pb(i);	
		}
	}
}

void solve() {
	int p, q;
	cin >> p >> q;
    
    int pr = pi.size();
    int rr = rub.size();
    ld A = (ld)p / (ld)q;
    int ans = 0;
    
    vector<int> pimrub(N, 0);
    int idxp = 0, idxr = 0;
    for (int i = 0; i < N; i++) {
    	if (idxp < pi.size() and pi[idxp] == i) {
    		pimrub[i] += q;
    		idxp++;
    	}
    	
    	if (idxr < rub.size() and rub[idxr] == i) {
    		pimrub[i] -= p;
    		idxr++;
    	}
    }
    vector<int> pref(N + 1, 0), pref2(N + 1, -1e9);
    int l0 = -1;
    for (int i = 0; i < N; i++) {
    	pref[i + 1] = pref[i] + pimrub[i];
    	// dbg(pref[i], pref[i + 1]);
    	if (pref[i] <= 0) {
    		l0 = i - 1;
    	}
    }
    
    ans = l0;
    
    
    
    if (ans == -1) {
    	cout << "Palindromic tree is better than splay tree" << ln;
    }
    else cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    palin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
