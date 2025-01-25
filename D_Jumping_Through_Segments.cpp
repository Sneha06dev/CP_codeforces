#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

// Function to check if a given k is sufficient to complete the level
bool canCompleteLevel(ll k, const vector<pair<ll, ll>>& segments) {
    ll current = 0; // Starting point

    for (const auto& segment : segments) {
        ll l = segment.first, r = segment.second;

        // Check if we can jump to this segment
        if (current + k > r || current - k < l) {
            return false;
        }

        // Update current position to the closest point within this segment
        current = max(current - k, l);
        current = min(current + k, r);
    }

    return true;
}

// Function to find the minimum k for a test case
ll findMinimumK(const vector<pair<ll, ll>>& segments) {
    ll left = 0, right = 1e9, answer = -1;

    // Binary search for the minimum k
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (canCompleteLevel(mid, segments)) {
            answer = mid;
            right = mid - 1; // Try for a smaller k
        } else {
            left = mid + 1; // Increase k
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<ll, ll>> segments(n);
        for (int i = 0; i < n; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }

        cout << findMinimumK(segments) << "\n";
    }

    return 0;
}
