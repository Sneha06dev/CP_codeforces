#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Depth-first search function
ll dfs(int node, vector<vector<int>>& adj, vector<ll>& a) {
    if (adj[node].empty()) {
        // Leaf node, return its value
        return a[node];
    }

    ll min_subtree = LLONG_MAX; // Minimum value in the subtree
    for (int child : adj[node]) {
        // Recurse on the child nodes
        min_subtree = min(min_subtree, dfs(child, adj, a));
    }

    // Update the current node value based on the logic
    if (min_subtree == LLONG_MAX) {
        return a[node]; // If no valid minimum, return the node value
    } else {
        return (a[node] + min_subtree) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1); // Node values, 1-indexed
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> adj(n + 1); // Adjacency list for the tree
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            adj[p].push_back(i); // Add child to parent's adjacency list
        }

        // Perform DFS starting from the root (node 1)
        cout << dfs(1, adj, a) << '\n';
    }

    return 0;
}
