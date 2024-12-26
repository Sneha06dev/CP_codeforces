#include <iostream>
#include <vector>
using namespace std;

bool isSuperior(const vector<int>& x, const vector<int>& y) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
        if (x[j] < y[j]) {
            count++;
        }
    }
    return count >= 3;
}

int findGoldMedalist(int n, vector<vector<int>>& rankings) {
    vector<vector<int>> adj(n); // Adjacency list to represent superior relationships
    
    // Step 1: Construct the graph by adding directed edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isSuperior(rankings[i], rankings[j])) {
                adj[i].push_back(j); // i is superior to j, so there's an edge from i to j
            }
        }
    }

    // Step 2: Find the athlete who dominates everyone else
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == n - 1) {  // If the current athlete has edges to all other athletes
            return i + 1; // Return the athlete's 1-based index
        }
    }
    
    return -1; // No such athlete found
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> rankings(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> rankings[i][j];
            }
        }

        cout << findGoldMedalist(n, rankings) << endl;
    }

    return 0;
}
