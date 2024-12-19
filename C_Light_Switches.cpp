#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Read the installation times
        vector<long long> arr(n);
        for (long long i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // Calculate the value of kk as 2*k
        long long kk = 2 * k;

        // Sort the array to process elements in increasing order
        sort(arr.begin(), arr.end());

        // Find the maximum element in the array
        long long mx = arr[n - 1];

        // Adjust all elements to be closer to `mx` in multiples of kk
        for (auto &it : arr) {
            long long full = (mx - it) / kk;
            it = it + full * kk;
        }

        // Map to track frequency of ranges
        map<long long, long long> mpp;

        // Populate the map for each element in the array
        for (auto it : arr) {
            mpp[it]++;            // Start of a range
            mpp[it + k]--;        // End of the range for k
            mpp[it + kk]++;       // Start of the second range for 2*k
            mpp[it + 3 * k]--;    // End of the second range for 3*k
        }

        // Variable to track active ranges
        long long on = 0;
        long long answer = -1;

        // Iterate over the map to find the range covering all elements
        for (auto it : mpp) {
            on += it.second;
            if (on == n) {
                answer = it.first;
                break;
            }
        }

        cout << answer << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
