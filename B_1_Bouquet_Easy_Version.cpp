#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> petals(n);
        for (int i = 0; i < n; ++i) {
            cin >> petals[i];
        }

        // Sort the petals
        sort(petals.begin(), petals.end());

        // We will use a frequency map to count occurrences of each number of petals
        unordered_map<int, long long> petal_count;
        for (int petal : petals) {
            petal_count[petal]++;
        }

        long long max_petals = 0;

        // Check each unique number of petals `x` and the bouquet formed with `x` and `x+1`
        for (const auto& entry : petal_count) {
            int x = entry.first;
            long long count_x = entry.second;

            // Case 1: Only flowers with `x` petals
            long long cost = x * count_x;
            if (cost <= m) {
                max_petals = max(max_petals, x * count_x);
            }

            // Case 2: Flowers with `x` and `x+1` petals
            if (petal_count.find(x + 1) != petal_count.end()) {
                long long count_x_plus_1 = petal_count[x + 1];
                long long total_cost = (x * count_x) + ((x + 1) * count_x_plus_1);
                if (total_cost <= m) {
                    max_petals = max(max_petals, (x * count_x) + ((x + 1) * count_x_plus_1));
                }
            }
        }

        cout << max_petals << "\n";
    }

    return 0;
}
