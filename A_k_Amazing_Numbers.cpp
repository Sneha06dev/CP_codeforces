#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // To store the positions of each number
        vector<vector<int>>b(n + 1);

        for (int i = 0; i < n; ++i) {
            b[a[i]].push_back(i + 1); // 1-based indexing
        }

        vector<int> ans(n + 1, INT_MAX);

        for (int j = 1; j <= n; ++j) {
            if (b[j].empty()) continue;

            // Add boundaries for easier gap calculation
           b[j].insert(b[j].begin(), 0);
           b[j].push_back(n + 1);

            // Calculate the maximum gap
            int maxi = 0;
            for (int i = 1; i < b[j].size(); ++i) {
                maxi = max(maxi, b[j][i] - b[j][i - 1]);
            }

            // Update min_k_amazing for the given max_gap
            if (maxi <= n) {
                ans[maxi] = min(ans[maxi],j);
            }
        }

        // Fill in the results for each k
        vector<int> result(n + 1, -1);
        int current_min = INT_MAX;

        for (int k = 1; k <= n; ++k) {
            current_min = min(current_min, min_k_amazing[k]);
            if (current_min != INT_MAX) {
                result[k] = current_min;
            }
        }

        // Print the results
        for (int k = 1; k <= n; ++k) {
            cout << result[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
