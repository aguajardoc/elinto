// Problem: N. Petya's Exams
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/N
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Exam {
	int s, d, c, idx, p;
	bool operator<(const Exam& b) const{
		return s < b.s;
	}
};

struct comp {
	bool operator()(const Exam& a, const Exam& b) {
		return a.d > b.d;
	}
};

void solve() {
    // pq of what is more pressing
    // what is more pressing tho?
    // c - (d - i) is sort criterion
    
    priority_queue<Exam, vector<Exam>, comp> pq, temp;
    
    int n, m;
    cin >> n >> m;
    
    vector<Exam> exams(m);
    vector<int> exam_day(n, 0);
    bool poss = true;
    for (int i = 0; i < m; i++) {
    	cin >> exams[i].s >> exams[i].d >> exams[i].c;
    	exams[i].idx = i;
    	exams[i].s--;
    	exams[i].d--;
    	exam_day[exams[i].d]++;
    	
    	if (exam_day[exams[i].d] == 2) poss = false;
    }
    
    sort(exams.begin(), exams.end());
    
    vector<int> sch(n, 0);
    int idx = 0;
    for (int i = 0; i < n; i++) {
    	while (idx < m and exams[idx].s == i) {
    		pq.push(exams[idx]);
    		idx++;
    	}
    	
    	while (!pq.empty()) {
    		Exam cur = pq.top();
    		pq.pop();
    		if (cur.d <= i) poss = false;
    		temp.push(cur);
    	}
    	swap(pq, temp);
    	
    	if (exam_day[i]) {
    		sch[i] = m + 1;
    		continue;
    	}
    	if (pq.empty()) continue;
    	
    	Exam cur = pq.top();
    	pq.pop();
    	sch[i] = cur.idx + 1;
    	if (--cur.c) pq.push(cur);
    }
    
    if (!pq.empty()) poss = false;
    
    if (!poss) {
    	cout << -1 << ln;
    	return;
    }
    
    for (int i = 0; i < n; i++) {
    	cout << sch[i] << " ";
    }
    cout << ln;
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
