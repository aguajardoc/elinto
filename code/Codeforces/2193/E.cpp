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
	int n;
	cin >> n;
	set<int> st;
	vector<int> a;
	for (int i = 0; i < n ;i++) {
		int x;
		cin >> x;
		if (st.insert(x).second)a.pb(x);
	}
	sort(a.begin(), a.end());
	
	vector<int> dist(n + 1, 1e9);
	queue<int> q;
	for (auto& i : a) {
		dist[i] = 1;
		q.push(i);
	}
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (auto& i : a) {
			if (u * i > n) break;
			if (dist[u * i] != 1e9) continue;
			
			dist[u*i] = dist[u] + 1;
			q.push(u*i);
		}
	}
	
	for (int i= 1; i <= n; i++) {
		cout << (dist[i] == 1e9 ? -1:dist[i]) << " ";
	}
	cout << ln;
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
