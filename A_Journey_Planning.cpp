#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long maximumBeauty(int n, vector<int>& b) {
    unordered_map<int, long long> beautySums;

    // Calculate `i - b[i]` for each city and sum the beauty values
    for (int i = 0; i < n; ++i) {
        int key = (i + 1) - b[i]; // Convert 0-based index to 1-based
        beautySums[key] += b[i];
    }

    // Find the maximum beauty sum across all groups
    long long maxBeauty = 0;
    for (const auto& entry : beautySums) {
        maxBeauty = max(maxBeauty, entry.second);
    }

    return maxBeauty;
}

int main() {
    // Input
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Output the maximum beauty of the journey
    cout << maximumBeauty(n, b) << endl;

    return 0;
}
