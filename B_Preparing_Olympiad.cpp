#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int valid_sets = 0;

    // Iterate over all subsets using bit masking
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0, min_difficulty = 1e6, max_difficulty = 0, count = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // If the i-th problem is included
                sum += c[i];
                min_difficulty = min(min_difficulty, c[i]);
                max_difficulty = max(max_difficulty, c[i]);
                count++;
            }
        }

        // Check if this subset satisfies the conditions
        if (count >= 2 && l <= sum && sum <= r && (max_difficulty - min_difficulty) >= x) {
            valid_sets++;
        }
    }

    cout << valid_sets << endl;
    return 0;
}
