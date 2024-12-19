#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int max_slots = (n + k - 1) / k; // Max number of cells per group
    int overflow = (n - 1) % k + 1; // Extra slots in the last group (if uneven)

    int count_max = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] == max_slots) count_max++;
        if (a[i] > max_slots) {
            cout << "NO\n";
            return;
        }
    }

    // Check if the total number of groups required fits within constraints
    if (count_max > overflow) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
