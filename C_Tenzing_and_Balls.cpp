#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> dp(n, 0);                // dp array to store max balls removable at each step
    vector<vector<long long>> ans(2, vector<long long>(n + 1, -1)); // Store last state for each color

    dp[0] = 0;
    ans[0][a[0]] = 0; // Initialize first occurrence
    ans[1][a[0]] = 0; // Store index

    for (int i = 1; i < n; i++) {
        int val = a[i];

        // If this is the first occurrence of a[i], carry forward the dp value
        if (ans[0][val] == -1) {
            dp[i] = max(dp[i], dp[i - 1]);
        } else {
            // Otherwise, calculate the max removals considering the previous occurrence
            dp[i] = max({dp[i], dp[i - 1], ans[0][val] + (i - ans[1][val] + 1)});
        }

        // Update the state for color a[i]
        if (ans[0][val] == -1) {
            ans[0][val] = dp[i - 1];
            ans[1][val] = i;
        } else {
            long long val1 = abs(i - ans[1][val]);
            long long val2 = abs(dp[i - 1] - ans[0][val]);
            if (val1 < val2) {
                ans[0][val] = dp[i - 1];
                ans[1][val] = i;
            }
        }
    }

    cout << dp[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
