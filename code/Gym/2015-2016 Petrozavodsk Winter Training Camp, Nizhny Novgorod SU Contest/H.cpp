// Problem: H. Garland Checking
// Contest: Codeforces - 2015-2016 Petrozavodsk Winter Training Camp, Nizhny Novgorod SU Contest
// URL: https://codeforces.com/gym/100960/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

// typedef long long ll;

typedef struct snode *sn;
struct snode {         //////// VARIABLES
	sn p, c[2];        // parent, children
	bool flip = 0;     // subtree flipped or not
	int sz;            // # nodes in current splay tree
	ll sub, vsub = 0;  // vsub stores sum of virtual children
	ll val;            // value in node
	ll sum;
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = NULL;
		calc();
	}
	friend int getSz(sn x) { return x ? x->sz : 0; }
	friend ll getSub(sn x) { return x ? x->sub : 0; }
	friend ll getSum(sn x) { return x ? x->sum : 0; }
	void prop() {  // lazy prop
		if (!flip) return;
		swap(c[0], c[1]);
		flip = 0;
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->flip ^= 1;
	}
	void calc() {  // recalc vals
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->prop();
		sz = 1 + getSz(c[0]) + getSz(c[1]);
		sub = val + getSub(c[0]) + getSub(c[1]) + vsub;
		sum = val + getSum(c[0]) + getSum(c[1]);
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		for (int i = 0; i < 2; i++)
			if (p->c[i] == this) return i;
		return -1;  // p is path-parent pointer
	}  // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; }
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() {  // assume p and p->p propagated
		assert(!isRoot());
		int x = dir();
		sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x ^ 1], x);
		setLink(this, pa, x ^ 1);
		pa->calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
		calc();
	}
	sn fbo(int b) {  // find by order
		prop();
		int z = getSz(c[0]);  // of splay tree
		if (b == z) {
			splay();
			return this;
		}
		return b < z ? c[0]->fbo(b) : c[1]->fbo(b - z - 1);
	}
	//////// BASE OPERATIONS
	void access() {  // bring this to top of tree, propagate
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay();  // now switch virtual children
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre;
			v->calc();
			pre = v;
		}
		splay();
		assert(!c[1]);  // right subtree is empty
	}
	void makeRoot() {
		access();
		flip ^= 1;
		access();
		assert(!c[0] && !c[1]);
	}
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access();
		if (!x->p) return NULL;
		x->splay();
		return x->p ?: x;  // y was below x in latter case
	}  // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x, y); }
	// # nodes above
	int distRoot() {
		access();
		return getSz(c[0]);
	}
	sn getRoot() {  // get root of LCT component
		access();
		sn a = this;
		while (a->c[0]) a = a->c[0], a->prop();
		a->access();
		return a;
	}
	sn getPar(int b) {  // get b-th parent on path to root
		access();
		b = getSz(c[0]) - b;
		assert(b >= 0);
		return fbo(b);
	}  // can also get min, max on path to root, etc
	//////// MODIFICATIONS
	void set(int v) {
		access();
		val = v;
		calc();
	}
	friend void link(sn x, sn y, bool force = 0) {
		assert(!connected(x, y));
		if (force) y->makeRoot();  // make x par of y
		else {
			y->access();
			assert(!y->c[0]);
		}
		x->access();
		setLink(y, x, 0);
		y->calc();
	}
	friend void cut(sn y) {  // cut y from its parent
		y->access();
		assert(y->c[0]);
		y->c[0]->p = NULL;
		y->c[0] = NULL;
		y->calc();
	}
	friend void cut(sn x, sn y) {  // if x, y adj in tree
		x->makeRoot();
		y->access();
		assert(y->c[0] == x && !x->c[0] && !x->c[1]);
		cut(y);
	}
};

const int MAX_N = 2e5;
sn LCT[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        LCT[i] = new snode(0);
    }
    
    while (true) {
        char type;
        cin >> type;
        
        if (type == 'E') {
            break;
        }
        
        int a, b;
        cin >> a >> b;
        
        if (type == 'C') {
            link(LCT[a], LCT[b], 1);
        }
        else if (type == 'D') {
            cut(LCT[a], LCT[b]);
        }
        else {
            if (LCT[a]->getRoot() == LCT[b]->getRoot()) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}

signed main() {
    // fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
