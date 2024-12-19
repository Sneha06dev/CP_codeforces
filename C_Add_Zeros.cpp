#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& a, vector<bool>& visited, int i, int l) {
    long long k = *max_element(a.begin(), a.end());
    long long take = 0;
    long long skip = 0;

    // Base cases
    if (l - a.size() + 1 > k) return 0;
    if (i >= a.size()) return 0;

    // Take the current element if it satisfies the condition and is not visited
    if (a[i] == l - i && !visited[i]) {
        visited[i] = true;                      // Mark as visited when taking
        take = solve(a, visited, 0, l + i) + i; // Restart recursion from 0
        visited[i] = false;                     // Unmark when recursion returns
    }

    // Skip the current element
    skip = solve(a, visited, i + 1, l);

    return max(take, skip);
}

void solved() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        long long n;
        cin >> n; // Size of the array
        vector<long long> a(n); // Input array

        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Initialize visited array
        vector<bool> visited(n, false);

        long long ans = solve(a, visited, 0, a.size());
        cout << ans+a.size() << endl;
    }
}

int main() {
    solved();
    return 0;
}
