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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<int> p;
bitset<10001> bs;
int8_t choice[1300][10001];
ld dp[2][10001];

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 10000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}

void solve(int n) {
    
    int idx = p.size();
    int s = n;
    vector<int> path;
    while (idx != 0) {
    	if (choice[idx][s] == 0) {
    		idx--;
    		continue;
    	}
    	
    	int num = 1;
    	for (int i = 0; i < choice[idx][s]; i++) {
    		num *= p[idx-1];
    	}
    	
    	path.pb(num);
    	
    	idx--;
    	s -= num;
    }
    
    sort(path.rbegin(), path.rend());
    while (!path.empty() and path.back() == 0) path.pop_back();
    int sum = 0;
    for (auto& i : path) sum += i;
    
    while (sum < n) {
    	path.pb(1);
    	sum++;
    }
    
    reverse(path.begin(), path.end());
    
    vector<int> ans;
    
    int x = 1;
    for (auto& i : path) {
    	for (int j = 1; j < i; j++) {
    		ans.pb(x + j);
    	}
    	ans.pb(x);
    	
    	x += i;
    }
    
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    fill_n(&dp[0][0], 2*10001, 1);
    
    int T = 1;
    cin >> T;
    vector<int> tc;
    int mx = 0;
    for (int i = 1; i <= T; i++) {
        int x;
        cin >> x;
        tc.pb(x);
        mx = max(mx, x);
    }
    
    for (int i = 1; i <= p.size(); i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	for (int j = 0; j <= mx; j++) {
    		
    		dp[now][j] = dp[last][j];
    		ld best = dp[last][j];
    		choice[i][j] = 0;
    		
    		
    		int cp = p[i-1];
    		for (int k = 1; j - cp >= 0; k++, cp *= p[i-1]) {
    			ld temp = dp[last][j-cp] + log(cp);
    			
    			if (temp > best) {
    				best = temp;
    				choice[i][j] = k; 
    			}
    		}
    		
    		dp[now][j] = best;
    	}
    }
    
    for (auto& i : tc) solve(i);

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
