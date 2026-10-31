// Problem: 1036. Lucky Tickets
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1036
// Memory Limit: 64 MB
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

struct BigInt {
    static const int BASE = 1e9;
    vector<int> digits;

    BigInt() {}
    BigInt(long long v) {
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % BASE);
            v /= BASE;
        }
    }
    BigInt(const string &s) {
        for (int i = (int)s.length(); i > 0; i -= 9) {
            if (i < 9) digits.push_back(stoi(s.substr(0, i)));
            else digits.push_back(stoi(s.substr(i - 9, 9)));
        }
        trim();
    }

    void trim() {
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    }

    bool operator<(const BigInt &other) const {
        if (digits.size() != other.digits.size()) return digits.size() < other.digits.size();
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) return digits[i] < other.digits[i];
        }
        return false;
    }

    BigInt operator+(const BigInt &other) const {
        BigInt res;
        long long carry = 0;
        for (size_t i = 0; i < max(digits.size(), other.digits.size()) || carry; i++) {
            long long sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            res.digits.push_back(sum % BASE);
            carry = sum / BASE;
        }
        return res;
    }

    BigInt operator*(const BigInt &other) const {
        BigInt res;
        res.digits.assign(digits.size() + other.digits.size(), 0);
        for (size_t i = 0; i < digits.size(); i++) {
            long long carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; j++) {
                long long cur = res.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                res.digits[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }
        res.trim();
        return res;
    }

    friend ostream& operator<<(ostream &out, const BigInt &a) {
        if (a.digits.empty()) return out << 0;
        out << a.digits.back();
        for (int i = (int)a.digits.size() - 2; i >= 0; i--) {
            out << setfill('0') << setw(9) << a.digits[i];
        }
        return out;
    }
};

BigInt dp[2][501];
ll n, s;

void solve() {
    cin >> n >> s;
    
    fill_n(&dp[0][0], 2*501, BigInt(0));
    dp[0][0] = 1;
    
    for (__int128 d = 1; d <= n; d++) {
    	__int128 now = d % 2;
    	__int128 last = 1 - now;
    	for (__int128 ls = 0; ls <= s/2; ls++) {
			for (__int128 x = 0; x <= 9; x++) {
				if (ls >= x) {
					dp[now][ls] = dp[now][ls] + dp[last][ls-x];
				}
    		}
    	}
    	
    	fill_n(&dp[last][0], 501, BigInt(0));
    }
    
    BigInt ans = dp[n%2][s/2] * dp[n%2][s/2];
    if (s % 2) ans = 0;
    cout << ans << ln;
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
