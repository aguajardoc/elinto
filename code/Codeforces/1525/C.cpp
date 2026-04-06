// Problem: C. Robot Collisions
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/C
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

struct Robot {
	int idx=-1, pos=-1, tod=-1;
	bool operator<(const auto& oth) {
		return pos < oth.pos;
	}
	char dir;
};

int m;

vector<Robot> kill_pairs(vector<Robot>& A, vector<Robot>& a) {
	vector<Robot> L, rem, R;
	for (auto& i : a) {
		if (i.dir == 'L') L.pb(i);
		else R.pb(i);
	}
	
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	vector<Robot> NR;
	int pt = (int)L.size() - 1;
	for (int i = (int)R.size() - 1; i >= 0; i--) {
		while (pt >= 0 and (A[L[pt].idx].tod != -1 or L[pt].pos >= R[i].pos)) {
			NR.pb(L[pt]);
			pt--;
		}
		
		while (!NR.empty() and A[NR.back().idx].tod != -1) NR.pop_back();
		if (NR.empty()) continue;
		
		Robot& Li = NR.back();
		int tod = (Li.pos - R[i].pos) / 2;
		A[Li.idx].tod = tod;
		A[R[i].idx].tod = tod;
	}
	
	for (auto & i : L) {
		if (A[i.idx].tod == -1) rem.pb(i);
	}
	for (auto & i : R) {
		if (A[i.idx].tod == -1) rem.pb(i);
	}
	
	return rem;
}

Robot kill_left(vector<Robot>& A, vector<Robot>& a) {
	vector<Robot> L;
	for (auto& i : a) {
		if (i.dir == 'L') L.pb(i);
	}
	
	int n = L.size();
	for (int i = 0; i < n - 1; i += 2) {
		int tod = L[i].pos + (L[i+1].pos - L[i].pos) / 2;
		A[L[i].idx].tod = tod;
		A[L[i+1].idx].tod = tod;
	}
	
	if (n % 2) {
		return L.back();
	}
	return Robot();
}

Robot kill_right(vector<Robot>& A, vector<Robot>& a) {
	vector<Robot> R;
	for (auto& i : a) {
		if (i.dir == 'R') R.pb(i);
	}
	
	int n = R.size();
	for (int i = n - 1; i >= 1; i -= 2) {
		int tod = (m - R[i].pos) + (R[i].pos - R[i-1].pos) / 2;
		
		A[R[i].idx].tod = tod;
		A[R[i-1].idx].tod = tod;
	}
	
	if (n % 2) {
		return R.front();
	}
	return Robot();
}

void pair_remaining(vector<Robot>& a, Robot L, Robot R) {
	if (L.idx == -1 or R.idx == -1) return;
	L.pos = -L.pos;
	int tod = (m - R.pos) + (R.pos - L.pos) / 2;
	a[L.idx].tod = tod;
	a[R.idx].tod = tod;
}

void process(vector<Robot>& A, vector<Robot>& a) {
	vector<Robot> rem = kill_pairs(A, a); 
	Robot L = kill_left(A, rem);
	Robot R = kill_right(A, rem);
	pair_remaining(A, L, R);
}

void solve() {
	int n;
	cin >> n >> m;
	vector<Robot> a(n), even, odd;
	for (int i = 0; i < n; i++) {
		cin >> a[i].pos;
		a[i].idx = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].dir;
		
		if (a[i].pos % 2) odd.pb(a[i]);
		else even.pb(a[i]);
	}
	
	process(a, even);
	process(a, odd);
	
	for (auto& i : a) {
		cout << i.tod << " ";
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
