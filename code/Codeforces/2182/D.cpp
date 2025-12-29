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
const int MOD = 998244353;
const double eps = 1e-9;

vector<int> factorial;

void print(vector<int>& a) {
	for (auto& i : a) {
		cout << i << " ";
	}
	cout << ln;
}

int binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) {
			res = (a * res) % MOD;
		}
		a = ( a  * a) % MOD;
		 b>>= 1;
	}
	
	return res;
}

int nck(int n, int k) {
	int num = factorial[n];
	int den = factorial[n - k] * factorial[k];
	den %= MOD;
	
	int res = num * binexp(den, MOD - 2);
	res = res % MOD;
	return res;
}

int npk(int n, int k) {
	int num = factorial[n];
	int den = factorial[n - k];
	
	int res = num * binexp(den, MOD - 2);
	res = res % MOD;
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (auto& i : a) {
    	cin >> i;
    	sum += i;
    }
    
    int bucket = a[0];
    reverse(a.begin(), a.end());
    a.pop_back();
    sort(a.rbegin(), a.rend());
    
    int k = sum % n;
    int target = sum / n + min(1ll, k);
    int ct = k;
    
    // print(a);
    bool poss = true;
    
    if (a.front() > target) {
    	poss = false;
    	cout << 0 << ln;
    	return;
    }
    
    int alreadyTarget = 0;
    
    if (k == 0) {
    	// if any exceeds the target, its impossible
    	// but we filtered for that so must be poss
    	// do nothing
    }
    else {
    	// count how many are already the target
    	for (auto& i : a) {
    		if (i == target) {
    			alreadyTarget++;
    		}
    	}
    	
    	// if exceeds k, bad!, else possible
    	if (alreadyTarget > k) poss = false;
    }
    
    if (!poss) {
    	cout << 0 << ln;
    	return;
    }
    else {
    	int ans = 1;
    	ans *= npk(k, alreadyTarget);
    	ans %= MOD;
    	
    	ans *= nck(n - alreadyTarget, k - alreadyTarget);
    	ans %= MOD;
    	
    	ans *= factorial[k - alreadyTarget];
    	ans %= MOD;
    	
    	ans *= factorial[n - k];
    	ans %= MOD;
    	
    	cout << ans << ln;
    }
}

signed main() {
    fast_cin();
    factorial = {1, 1};
    for (int i = 2; i < 67; i++) {
    	factorial.pb(factorial.back() * i);
    	factorial.back() %= MOD;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
