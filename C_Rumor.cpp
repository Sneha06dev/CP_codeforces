#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

// DSU (Disjoint Set Union) structure
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cost(n + 1); // Bribe costs (1-based indexing)
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    DSU dsu(n);

    // Read friendships and build connected components
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    // Find the minimum cost in each connected component
    vector<int> minCost(n + 1, INT_MAX); // Store minimum cost for each leader
    for (int i = 1; i <= n; i++) {
        int leader = dsu.find(i);
        minCost[leader] = min(minCost[leader], cost[i]);
    }

    // Calculate the total cost
    long long totalCost = 0;
    for (int i = 1; i <= n; i++) {
        if (minCost[i] != INT_MAX) {
            totalCost += minCost[i];
        }
    }

    cout << totalCost << endl;
    return 0;
}
