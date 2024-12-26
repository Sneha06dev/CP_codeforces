#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int c = 0;
        sort(a.begin(), a.end());
        int x = 0;
        int i = 0;
        vector<bool> visited(n, false); // Create a visited array to track processed elements

        while (i < n - 1) {
            if (visited[i]) {
                i++; // Skip the element if it's already visited
                continue;
            }

            x += a[i];
            auto it = lower_bound(a.begin() + i + 1, a.end(), x);

            // If we find an element equal to x and it's not visited, mark it as visited
            if (it != a.end() && *it == x && !visited[it - a.begin()]) {
                visited[it - a.begin()] = true; // Mark this element as visited
                c += x;  // Add the value of x to the count
                c++;     // Increment count for the attack
                x = 0;   // Reset combo counter
                i++;     // Move to the next element
            } else {
                i++; // Move to the next element
            }

            // If we are at the last element of the array, apply the logic
            if (i == n - 1) {
                // int k = a[i] - x;
                // int z = (k % 2) ? ((k / 2)+1) : (k / 2);
                // if (k % 2) {
                //     c += ((z + x) + 1);
                // } else {
                //     c += (z + x+1);
                // }
                c+=(a[i]-x+1);
            }
        }

        cout << c << endl;
    }
}
