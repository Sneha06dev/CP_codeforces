#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;

        // Read input and count frequencies
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> candidates;

        // Collect numbers with at least 2 occurrences
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int val = it->first;
            int count = it->second;
            if (count >= 2) {
                // Push the value count / 2 times into candidates
                for (int i = 0; i < count / 2; ++i) {
                    candidates.push_back(val);
                }
            }
        }

        // Sort the candidates to easily form the rectangle
        sort(candidates.begin(), candidates.end());

        if (candidates.size() < 4) {
            cout << "NO\n";
            continue;
        }

        // Try to form the rectangle with the largest possible area
        int A = candidates[0];    // Smallest x
        int B = candidates[1];    // Second smallest x
        int C = candidates[candidates.size() - 2];  // Second largest x
        int D = candidates[candidates.size() - 1];  // Largest x

        // If we have at least two distinct x and y coordinates, print the rectangle
        if (1) {
            cout << "YES\n";
            cout << A << " " << B << " " << A << " " << D << " " << C << " " << B << " " << C << " " << D << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
