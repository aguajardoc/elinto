// Problem: 12096 - The SetStack Computer
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3248
// Memory Limit: 32 MB
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

long long compute_hash(set<int>& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int c : s) {
        hash_value = (hash_value + (c + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void solve() {
    int n;
    cin >> n;
    stack<set<int>> st;
    for (int i = 0; i < n; i++) {
    	string c;
    	cin >> c;
    	if (c[0] == 'P') {
    		st.push(set<int>());
    	}
    	if (c[0] == 'D') {
    		st.push(st.top());
    	}
    	if (c[0] == 'U') {
    		set<int> a, b;
    		a = st.top();
    		st.pop();
    		b = st.top();
    		st.pop();
    		
    		
    		set<int> d;
    		for (auto& i : a) d.insert(i);
    		for (auto& i : b) d.insert(i);
    		
    		st.push(d);
    	}
    	if (c[0] == 'I') {
    		set<int> a, b;
    		a = st.top();
    		st.pop();
    		b = st.top();
    		st.pop();
    		
    		set<int> d;
    		for (auto& i : a) if (b.count(i)) d.insert(i);
    		
    		st.push(d);
    	}
    	if (c[0] == 'A') {
    		set<int> a, b;
    		a = st.top();
    		st.pop();
    		b = st.top();
    		st.pop();
    		
    		set<int> d;
    		for (auto& i : b) d.insert(i);
    		d.insert(compute_hash(a));
    		
    		st.push(d);
    	}
    	
    	cout << st.top().size() << ln;
    }
    cout << "***\n";
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
