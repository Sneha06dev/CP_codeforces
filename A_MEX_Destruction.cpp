#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) c++;
    }

    // Count zeroes at the start
    int zeroAtStart = 0;
    for (int i = 0; i < n && a[i] == 0; i++) {
        zeroAtStart++;
    }

    // Count zeroes at the end
    int zeroAtEnd = 0;
    for (int i = n - 1; i >= 0 && a[i] == 0; i--) {
        zeroAtEnd++;
    }

    // Check if all zeroes are at the boundaries
    bool allZeroAtBoundaries = (zeroAtStart + zeroAtEnd == c);

    // Debug output for verification
    // cout << "ZeroAtStart: " << zeroAtStart << ", ZeroAtEnd: " << zeroAtEnd << ", TotalZeroes: " << c << endl;
    // cout << allZeroAtBoundaries << endl;

    // Original cases
    if (c == n) {
        cout << 0 << endl;
    } else if (allZeroAtBoundaries) {
        cout << 1 << endl;
    } else if ((c == 1)) {
        cout << 2 << endl;
    } else if ((c >= 2)) {
        cout << 2 << endl;
    } else if ((c == 0)) {
        cout << 1 << endl;
    } else {
        cout << "Not a case" << endl;
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
