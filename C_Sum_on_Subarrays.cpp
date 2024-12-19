#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve the problem
vector<int> solve(int n, int k) {
    if (n == 0) {
        return {}; // Base case: No elements, return empty array
    }

    if (k < n) {
        // Case where k < n
        vector<int> a(n, -1);  // Initialize the array with 0
        a[k - 1] = 100;      // Place 1000 at k-1 index (0-based)
        a[k]=-200;
        return a;
    } else {
        // Case where k >= n
        vector<int> a = solve(n - 1, k - n); // Recursively solve for n-1 and k-n
        a.push_back(1000);                    // Append 1000 to ensure the last position is positive
        return a;
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> result = solve(n, k); // Solve for current test case
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
