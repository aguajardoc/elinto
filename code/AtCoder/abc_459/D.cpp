// Problem: D - Adjacent Distinct String
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2026  (AtCoder Beginner Contest 459)
// URL: https://atcoder.jp/contests/abc459/tasks/abc459_d
// Memory Limit: 1024 MB
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

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    string t = string(n, '0');
    vector<int> ct(26, 0);
    for (auto& i : s) ct[i-'a']++;
    
    int mx = 0;
    int lg;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) {
    	if (ct[i])pq.push({ct[i], (i + 'a')});
    }
    // dbg(n);
    
    int idx = 0;
    while (pq.size() >= 2) {
    	pair<int, char> A = pq.top();
    	pq.pop();
    	pair<int, char> B = pq.top();
    	pq.pop();
    	
    	if (idx and A.second == t[idx-1]) swap(A, B);
    	
    	t[idx] = A.second;
    	t[idx+1] = B.second;
    	ct[A.second - 'a']--;
    	ct[B.second - 'a']--;
    	if(--A.first) pq.push(A);
    	if(--B.first) pq.push(B);
    	
    	idx += 2;
    }
    
    if (!pq.empty()) {
    	pair<int, char> A = pq.top();
    	pq.pop();
    	
    	t[idx] = A.second;
    	ct[A.second - 'a']--;
    	
    	if(--A.first) pq.push(A);
    	
    	idx++;
    }
    
    // dbg(t);
    // dbg(n, idx);
    for (auto& i : ct) {
    	if (i or idx != n) {
    		cout << "No" << ln;
    		return;
    	}
    }
    
    cout << "Yes" << ln;
    cout << t << ln;
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
