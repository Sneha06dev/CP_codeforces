#include <bits/stdc++.h>
using namespace std;

// DFS function to count the size of connected components
void count(unordered_map<int, vector<int>>& adj, int node, vector<int>& vis, int& c) {
    vis[node] = 1;
    c++;
    for (auto k : adj[node]) {
        if (!vis[k]) {
            count(adj, k, vis, c);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    // Graph representation using adjacency list
    unordered_map<int, vector<int>> adj;

    // Reading the tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) { // Only consider red edges
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> vis(n + 1, 0); // Visited array
    vector<int> number; // Sizes of connected components

    // Find all connected components
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int c = 0;
            count(adj, i, vis, c);
            number.push_back(c);
        }
    }

    // Calculate total and bad sequences
    const int MOD = 1e9 + 7;

    // Modular exponentiation
    auto mod_exp = [&](long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    };

    long long total_sequences = mod_exp(n, k); // Total sequences of length k
    long long bad_sequences = 0; // Sequences entirely within red components

    for (int size : number) {
        bad_sequences = (bad_sequences + mod_exp(size, k)) % MOD;
    }

    // Good sequences = Total sequences - Bad sequences
    long long good_sequences = (total_sequences - bad_sequences + MOD) % MOD;

    cout << good_sequences << endl;

    return 0;
}
