#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    long long req;
    long long inc;
    int prev;
    int next;
    bool active;
};

// Validates if initial tolerance X is enough to eat the whole pizza
bool check(long long X, const vector<long long>& S) {
    int n = S.size();
    if (n == 1) return X >= S[0]; // Edge case for a single slice
    
    vector<Node> nodes(n);
    queue<int> q;
    
    // Build the cyclic linked list
    for (int i = 0; i < n; i++) {
        nodes[i] = {S[i], S[i], (i - 1 + n) % n, (i + 1) % n, true};
        
        // If we can start at this slice, queue it up
        if (X >= S[i]) {
            q.push(i);
        }
    }
    
    int remaining = n;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // Skip if this node was already absorbed by another sequence
        if (!nodes[curr].active) continue;
        
        bool merged = false;
        
        // 1. Try to merge with the right neighbor
        int nxt = nodes[curr].next;
        if (nxt != curr && X + nodes[curr].inc >= nodes[nxt].req) {
            // Absorb the neighbor
            nodes[curr].req = min(nodes[curr].req, nodes[nxt].req);
            nodes[curr].inc += nodes[nxt].inc;
            nodes[nxt].active = false;
            
            // Rewire pointers to bypass the absorbed node
            int nxt_nxt = nodes[nxt].next;
            nodes[curr].next = nxt_nxt;
            nodes[nxt_nxt].prev = curr;
            
            remaining--;
            merged = true;
        }
        
        // 2. Try to merge with the left neighbor
        int prv = nodes[curr].prev;
        if (prv != curr && X + nodes[curr].inc >= nodes[prv].req) {
            // Absorb the neighbor
            nodes[curr].req = min(nodes[curr].req, nodes[prv].req);
            nodes[curr].inc += nodes[prv].inc;
            nodes[prv].active = false;
            
            // Rewire pointers to bypass the absorbed node
            int prv_prv = nodes[prv].prev;
            nodes[curr].prev = prv_prv;
            nodes[prv_prv].next = curr;
            
            remaining--;
            merged = true;
        }
        
        // If it grew, it might be able to eat more slices, so requeue it
        if (merged) {
            q.push(curr);
        }
    }
    
    // If everything merged into a single node, X is a valid starting tolerance
    return remaining == 1;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> S(n);
    long long max_s = 0;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        max_s = max(max_s, S[i]);
    }
    
    // Binary search over the answer
    // Max needed initial tolerance will never exceed the spiciest slice
    long long left = 0, right = max_s, ans = max_s;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (check(mid, S)) {
            ans = mid;
            right = mid - 1; // Try to find a smaller valid tolerance
        } else {
            left = mid + 1;  // Tolerance too low, increase it
        }
    }
    
    cout << ans << "\n";
    return 0;
}