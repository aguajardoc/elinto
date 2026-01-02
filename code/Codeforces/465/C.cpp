// Problem: C. No to Palindromes!
// Contest: Codeforces - Codeforces Round 265 (Div. 2)
// URL: https://codeforces.com/contest/465/problem/C
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;
int n, p;

int increment(vector<int>& a, int start = n - 1) {
	int idx = start;
	while (idx >= 0) {
		a[idx]++;
		a[idx] %= p;
		
		if (a[idx] == 0) {
			idx--;
			continue;
		}
		else {
			break;
		}
	}
	
	return idx;
}

bool isPal(vector<int>& a, int rv, int ending = n - 1) {
	for (int i = rv; i <= ending; i++) {
		if (i >= 1) {
			if (a[i] == a[i - 1]) return true;
		}
		if (i >= 2) {
			if (a[i] == a[i - 2]) return true;
		}
	}
	
	return false;
}

void print(vector<int>& a){
	for (auto& i : a) {
    	cout << char(i + 'a');	
    }
    cout << ln;
}

void solve() {
    string s;
    cin >> n >> p >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = (s[i] - 'a');
    }
    
    bool check = true;
    int rv = 1e9;
    int cur = n - 1;
    while (check) {
    	rv = min(rv, increment(a, cur));
    	
    	// print(a);
    	
    	if (rv == -1) {
    		cout << "NO" << ln;
    		return;
    	}
    	
    	while (rv < cur) {
    		cur--;
    	}
    
    	
    	check = isPal(a, 0, cur);
    }
    
    // change everything from cur onwards to the first perm of 3 that works
    vector<int> test = {0, 1, 2};
    if (cur == 0) {
	    if (a[cur] == 0) {
	    	test = {1, 2, 0};
	    }
	    if (a[cur] == 1) {
	    	test = {0, 2, 1};
	    }
	    if (a[cur] == 2) {
	    	test = {0, 1, 2};
	    }
	}
	else {
		if (a[cur - 1] == 0 and a[cur] == 1) {
			test = {2, 0, 1};
		}
		else if (a[cur - 1] == 2 and a[cur] == 1) {
			test = {0, 2, 1};
		}
		else if (a[cur - 1] == 1 and a[cur] == 0) {
			test = {2, 1, 0};
		}
		else if (a[cur - 1] == 1 and a[cur] == 2) {
			test = {0, 1, 2};
		}
		else if (a[cur - 1] == 0 and a[cur] == 2) {
			test = {1, 0, 2};
		}
		else if (a[cur - 1] == 2 and a[cur] == 0) {
			test = {1, 2, 0};
		}
		else if (a[cur] == 0) {
	    	test = {1, 2, 0};
	    }
	    else if (a[cur] == 1) {
	    	test = {0, 2, 1};
	    }
	    else if (a[cur] == 2) {
	    	test = {0, 1, 2};
	    }
	    else if (a[cur - 1] == 0) {
	    	test = {1, 0, 2};
	    }
	    else if (a[cur - 1] == 1) {
	    	test = {0, 1, 2};
	    }
	    else if (a[cur - 1] == 2) {
	    	test = {0, 1, 2};
	    }
	}
	
	for (int i = cur + 1, j = 0; i < n; i++, j++) {
		a[i] = test[j % 3];
	}
	
    
    print(a);
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
