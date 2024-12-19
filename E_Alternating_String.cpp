#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (n % 2 == 0) {
            // Even-length string
            unordered_map<char, int> count_even, count_odd;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) count_even[s[i]]++;
                else count_odd[s[i]]++;
            }
            
            int max_even = 0, max_odd = 0;
            for (const auto& pair : count_even) max_even = max(max_even, pair.second);
            for (const auto& pair : count_odd) max_odd = max(max_odd, pair.second);

            int even_replacements = (n / 2) - max_even;
            int odd_replacements = (n / 2) - max_odd;
            cout << even_replacements + odd_replacements << '\n';

        } else {
            // Odd-length string: Efficient logic
            unordered_map<char, int> o1, e1, o2, e2;

            // Initialize o1 and e1 with full string
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) e1[s[i]]++;
                else o1[s[i]]++;
            }

            int min_operations = n;

            for (int i = 0; i < n; i++) {
                // Remove the current character from o1 or e1
                if (i % 2 == 0) e1[s[i]]--;
                else o1[s[i]]--;

                // Create temporary maps for the current state
                unordered_map<char, int> o = o2, e = e2;

                // Merge suffix maps into prefix maps
                if (i % 2 == 0) {
                    e[s[i]]++; // Update prefix even frequencies
                } else {
                    o[s[i]]++; // Update prefix odd frequencies
                }

                // Calculate max frequencies for both prefix and suffix
                int max_even = 0, max_odd = 0;
                for (const auto& pair : e) max_even = max(max_even, pair.second);
                for (const auto& pair : o) max_odd = max(max_odd, pair.second);

                for (const auto& pair : e1) max_even = max(max_even, pair.second);
                for (const auto& pair : o1) max_odd = max(max_odd, pair.second);

                // Calculate operations
                int even_replacements = ((n - 1) / 2) - max_even;
                int odd_replacements = ((n - 1) / 2) - max_odd;
                if(even_replacements<0)even_replacements=0;
                if(odd_replacements<0)odd_replacements=0;
                min_operations = min(min_operations, even_replacements + odd_replacements + 1);

                // Add current character to o2 or e2
                if (i % 2 == 0) e2[s[i]]++;
                else o2[s[i]]++;
            }

            cout << min_operations << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
