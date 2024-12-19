#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Store segments as pairs {b, a} for sorting by end point
    vector<pair<int, int>> segments(n);
    for (auto &seg : segments) {
        cin >> seg.second >> seg.first; // Input as (a, b), store as (b, a)
    }

    // Sort segments by ending point (b). If b is the same, sort by start (a)
    sort(segments.begin(), segments.end());

    // List to keep track of processed starting points
    vector<int> processed_starts;
    long long greetings = 0;

    // Process each segment
    for (const auto &seg : segments) {
        int a = seg.second; // Current segment's starting point
        int b = seg.first;  // Current segment's ending point

        // Count how many starting points in processed_starts are greater than a
        // Binary search: find the first element > a
        int greater_count = processed_starts.end() - upper_bound(processed_starts.begin(), processed_starts.end(), a);
        greetings += greater_count;

        // Add the current starting point to the list of processed starts
        processed_starts.insert(lower_bound(processed_starts.begin(), processed_starts.end(), a), a);
    }

    // Output the total greetings for this test case
    cout << greetings << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}