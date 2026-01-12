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

int getDigsum(int x, int y) {
	int ans = 0;
	
	string s = to_string(x);
	for (int i = 0; i < y; i++) {
		ans += (s[i] - '0');
	}
	
	return ans;
}

vector<int> digsum;
vector<int> digcount;
vector<int> pow10;

int getSOD(int x, int i) {
	int ans = 0;
	string left;
	string right;
	int mult = pow10[i];
	
	left = to_string(x);
	right = to_string(x);
	int n = left.length();
	
	vector<int> occ(10, 0);
	
	string cum;
	
	for (int i = 0; i < n; i++) {
		int dig = (left[i] - '0');
		string leftn = left.substr(0, i);
		
		right[i] = '0';
		for (int j = 1; j <= 9; j++) {
			if (i == 0) {
				if (j < dig) {
					occ[j] += mult;
				}
				else if (j == dig) {
					occ[j] += stoll(right, NULL, 10) + 1;
				}
			}
			else {
				string cur = left.substr(0, i + 1);
				int leftS = stoll(cur);
				cur.back() = (j + '0');
				int now = stoll(cur);
				
				// dbg(leftS, now);
				int times = mult/10;
				if (now < leftS) {
					string oth = cur;
					oth.back() = '1';
					int help = stoll(oth);
					
					int d = leftS - help;
					// dbg(times * d);
					occ[j] += times * d;
				}
				else if (now == leftS) {
					string oth = cur;
					oth.back() = '2';
					int help = stoll(oth);
					
					int d = leftS - help;
					int r = times * d + stoll(right, NULL, 10) + 1;
					// dbg(r);
					occ[j] += r;
				}
				else {
					string oth = cur;
					oth.back() = '2';
					int help = stoll(oth);
					
					int d = leftS - help;
					int r = times * d;
					// dbg(r);
					occ[j] += r;
				}
			}
			
		}
		
		if (i) cum += '0';
		else cum += '1';
	}
	
	for (int i = 1; i <= 9; i++) {
		ans += occ[i] * i;
	}
	
	return ans;
}

void brute (int l, int r) {
	vector<vector<int>> occ(10, vector<int> (10, 0));
	
	for (int i = l; i <= r; i++) {
		string s= to_string(i);
		for (int j = 0; j < s.length(); j++) {
			occ[(s[j] - '0')][j]++;
		}
	}
	
	for (auto& i : occ) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << ln;
	}
}


void solve() {
	int k;
	cin >> k;
    
    // SOD from 1 to pow(10, i) - 1 = 45 * pow(10, i-1) * i
    // # of digits up to pow(10, i) - 1 = sum of 9 * i * pow(10, i - 1)
    
    // Get up to previous power
    int ans = 0;
    int i = 0;
    for (; i < digsum.size(); i++) {
    	if (digcount[i] > k) {
    		i--;
    		ans += digsum[i];
    		k -= digcount[i];
    		break;
    	}
    }
    
    // Add surplus
    int fullNum = k / (i + 1);
    int left = pow10[i] - 1;
    int right = pow10[i] + fullNum - 1;
    int extra = k % (i + 1);
    
    dbg(right);
    brute(left + 1, right);
    
    int surplusFull = 0;
    if (right > left) surplusFull = getSOD(right, i);
    int surplusExtra = getDigsum(right + 1, extra);
    
    ans += surplusFull + surplusExtra;  
    dbg(surplusFull); 
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    int cpow = 1;
    int prev = 0;
    digsum = {0};
    digcount = {0};
    for (int i = 1; i <= 15; i++, cpow *= 10) {
    	digsum.pb(45 * cpow * i);
    	int cur = 9 * i * cpow;
    	
    	cur += prev;
    	digcount.pb(cur);
    	pow10.pb(cpow);
    	prev = cur;
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
